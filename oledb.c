#include "oledb.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"
#include "mcc_generated_files/i2c1_driver.h"

uint8_t page_addr;
uint8_t col_addr;
uint8_t oledb_data;
uint8_t data_len;


void oledb_init(void)
{
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_DISPLAYOFF, 0x00);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETDISPLAYCLOCKDIV, 0x80);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETMULTIPLEX, 0x27);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETDISPLAYOFFSET, 0x00);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETSTARTLINE, 0x00);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_CHARGEPUMP, 0x14);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_COMSCANDEC, 0x00);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETCOMPINS, 0x12);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETCONTRAST, 0xAF);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETPRECHARGE, 0x25);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETVCOMDETECT, 0x20);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_DISPLAYALLON_RESUME, 0x00);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_NORMALDISPLAY, 0x00);
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_DISPLAYON, 0x00);
}

void oledb_send_data(uint8_t oledb_data, uint8_t data_lan)
{
    uint8_t tx_buffer[256];
    tx_buffer[0] = 0x40;
    memcpy (&tx_buffer[1], oledb_data, data_len);
}



void oledb_set_page(uint8_t page_addr)
{
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_PAGEADDR , OLEDB_DISPLAY_ROWS - 1);
}

void oledb_set_column(uint8_t col_addr)
{
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_COLUMNADDR , OLEDB_SSD1306_WIDTH - 1);
}

void oledb_clear_display()
{
    uint8_t data_buf[ 8 ] = { 0 };
    uint8_t page_num = 0;
    uint8_t seg_num = 0;
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_DISPLAYOFF, 0x00);
    for ( page_num = 0; page_num < OLEDB_DISPLAY_ROWS; page_num++ ) 
    {
        oledb_set_column (0);
        oledb_set_page (page_num);
        for ( seg_num = 0; seg_num < OLEDB_SSD1306_WIDTH; seg_num += 8 )
        {
            oledb_send_data(data_buf, 8);
        }
    }
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_DISPLAYON, 0x00);
}


void oledb_write_char(uint8_t font, uint8_t row, uint8_t position, uint8_t data_in)
{
    if ( ( font > OLEDB_FONT_6X8 ) || ( row > ( OLEDB_DISPLAY_ROWS - 1 ) ) )
    {
        return;
    }
    uint8_t char_buf[ 6 ] = { 0 };
    uint8_t char_width = 0;
    if ( ( data_in < 32 ) || ( data_in > 127 ) ) 
    {
        data_in = ' ';
    }
    if ( OLEDB_FONT_5X7 == font )
    {
        char_width = 5;
        memcpy ( char_buf, &oledb_font_5x7[ ( data_in - 32 ) * char_width ], char_width );
    }
    else if ( OLEDB_FONT_6X8 == font )
    {
        char_width = 6;
        memcpy ( char_buf, &oledb_font_6x8[ ( data_in - 32 ) * char_width ], char_width );
    }
    if ( position > ( ( ( OLEDB_SSD1306_WIDTH + 1 ) / char_width ) - 1 ) )
    {
        return;
    }
    
    oledb_set_column (OLEDB_DISPLAY_WIDTH - char_width - position * char_width);
    oledb_set_page (row);
    oledb_send_data(char_buf, char_width);
}

void oledb_write_string(uint8_t font, uint8_t row, uint8_t position, uint8_t *data_in)
{
    uint8_t data_len = strlen ( data_in );
    uint8_t data_cnt = 0;
    for ( data_cnt = 0; data_cnt < data_len; data_cnt++ )
    {
        oledb_write_char(font, row, position + data_len - 1 - data_cnt, data_in[ data_len - 1 - data_cnt ] );
    }
}

void oledb_set_contrast(uint8_t value)
{
    i2c_write1ByteRegister(OLEDB_COMMAND, OLEDB_SETCONTRAST, 0xAF);
}

