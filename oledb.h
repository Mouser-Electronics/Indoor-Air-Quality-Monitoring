/* 
 * File:   oledb.h
 * Author: chris.mao
 *
 * Created on July 25, 2023, 10:26 AM
 */

#ifndef OLEDB_H
#define	OLEDB_H

#include "mcc_generated_files/drivers/i2c_simple_master.h"
#include "oledb_resources.h"

#define OLEDB_SSD1306_WIDTH                         128
#define OLEDB_DISPLAY_WIDTH                         96
#define OLEDB_DISPLAY_HEIGHT                        39
#define OLEDB_DISPLAY_ROWS                          5
#define OLEDB_FONT_5X7                              0
#define OLEDB_FONT_6X8                              1
#define OLEDB_DISPLAYOFF                            0xAE
#define OLEDB_SETDISPLAYCLOCKDIV                    0xD5
#define OLEDB_SETMULTIPLEX                          0xA8
#define OLEDB_SETDISPLAYOFFSET                      0xD3
#define OLEDB_SETSTARTLINE                          0x40
#define OLEDB_CHARGEPUMP                            0x8D
#define OLEDB_SETSEGMENTREMAP                       0xA1
#define OLEDB_SEGREMAP                              0xA0
#define OLEDB_COMSCANDEC                            0xC8
#define OLEDB_SETCOMPINS                            0xDA
#define OLEDB_SETCONTRAST                           0x81
#define OLEDB_SETPRECHARGE                          0xD9
#define OLEDB_SETVCOMDETECT                         0xDB
#define OLEDB_DISPLAYALLON_RESUME                   0xA4
#define OLEDB_NORMALDISPLAY                         0xA6
#define OLEDB_DISPLAYON                             0xAF
#define OLEDB_DISPLAYALLON                          0xA5
#define OLEDB_INVERTDISPLAY                         0xA7
#define OLEDB_SETLOWCOLUMN                          0x00
#define OLEDB_SETHIGHCOLUMN                         0x10
#define OLEDB_MEMORYMODE                            0x20
#define OLEDB_COLUMNADDR                            0x21
#define OLEDB_PAGEADDR                              0x22
#define OLEDB_COMSCANINC                            0xC0
#define OLEDB_EXTERNALVCC                           0x01
#define OLEDB_SWITCHCAPVCC                          0x02
#define OLEDB_ACTIVATE_SCROLL                       0x2F
#define OLEDB_DEACTIVATE_SCROLL                     0x2E
#define OLEDB_SET_VERTICAL_SCROLL_AREA              0xA3
#define OLEDB_RIGHT_HORIZONTAL_SCROLL               0x26
#define OLEDB_LEFT_HORIZONTAL_SCROLL                0x27
#define OLEDB_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL  0x29
#define OLEDB_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL   0x2A

#define OLEDB_COMMAND                               0x3C
#define OLEDB_DATA                                  0x3D




#ifdef	__cplusplus
extern "C" {
#endif

void oledb_init(void);
void oledb_send_data(uint8_t oledb_data, uint8_t data_lan);
void oledb_set_page(uint8_t page_addr);
void oledb_set_column(uint8_t col_addr);
void oledb_clear_display();
void oledb_write_char(uint8_t font, uint8_t row, uint8_t position, uint8_t data_in);
void oledb_write_string(uint8_t font, uint8_t row, uint8_t position, uint8_t *data_in);
void oledb_set_contrast(uint8_t value);




#ifdef	__cplusplus
}
#endif

#endif	/* OLEDB_H */

