/* 
 * File:   main.h
 * Author: chris.mao
 *
 * Created on July 25, 2023, 11:35 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

    void read_temperature_humidityData();
    void read_co2_tvocData();
    void read_PMData();
    void displayData();


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

