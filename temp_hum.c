#include "mcc_generated_files/i2c1_driver.h"
#include "temp_hum.h"
#include "mcc_generated_files/drivers/i2c_simple_master.h"

#define TEMPHUM18_SET_DEV_ADDR                                  0x44
#define TEMPHUM18_REG_HUMIDITY_SENSOR_RESOLUTION_READ           0x06
#define TEMPHUM18_REG_HUMIDITY_SENSOR_RESOLUTION_WRITE          0x46
#define TEMPHUM18_REG_TEMPERATURE_SENSOR_RESOLUTION_READ        0x11
#define TEMPHUM18_REG_TEMPERATURE_SENSOR_RESOLUTION_WRITE       0x51



void i2c_read_temperature_humidity()
{
    float temperature;
    float humidity;
    uint16_t result;
    //Read temperature and humidity register
    i2c_read2ByteRegister(TEMPHUM18_SET_DEV_ADDR, TEMPHUM18_REG_TEMPERATURE_SENSOR_RESOLUTION_READ);
    result = result << 2;
    temperature = (result * 0.00006104 * 100);
    
    i2c_read2ByteRegister(TEMPHUM18_SET_DEV_ADDR, TEMPHUM18_REG_HUMIDITY_SENSOR_RESOLUTION_READ);
    result = result >> 2;
    humidity = (result * 0.00006104 * 165 - 40);

}