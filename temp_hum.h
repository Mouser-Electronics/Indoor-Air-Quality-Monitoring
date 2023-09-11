/* 
 * File:   temp&hum.h
 * Author: chris.mao
 *
 * Created on July 24, 2023, 11:07 AM
 */

#ifndef TEMP_HUM_H
#define	TEMP_HUM_H
#define TEMPHUM18_SET_DEV_ADDR                                  0x44
#define TEMPHUM18_REG_HUMIDITY_SENSOR_RESOLUTION_READ           0x06
#define TEMPHUM18_REG_HUMIDITY_SENSOR_RESOLUTION_WRITE          0x46
#define TEMPHUM18_REG_TEMPERATURE_SENSOR_RESOLUTION_READ        0x11
#define TEMPHUM18_REG_TEMPERATURE_SENSOR_RESOLUTION_WRITE       0x51
#ifdef	__cplusplus
extern "C" {
#endif

   #include <xc.h>
   void i2c_read_temperature_humidity();
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_HUM_H */

