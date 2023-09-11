/**
\file
\defgroup doc_driver_uart_code UART Driver Source Code Reference
\ingroup doc_driver_uart
\brief This file contains the UART configurations selected by the user in the UART Foundation Services MCC Interface.
\copyright (c) 2020 Microchip Technology Inc. and its subsidiaries.
\page License
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
**/

#ifndef _UART_H
#define _UART_H


#include <stdint.h>
#include <stddef.h>
#include "../uart2.h"
#include "../../sps30.h"
/**
*   \ingroup doc_driver_uart_code
*   \enum uart_configurations_t uart.h
*/
typedef enum { 
    UART2 /**<UART Name */
} uart_configurations_t;

/**
*   \ingroup doc_driver_uart_code
*   \struct uart_functions_t uart.h
*/
typedef struct { uint8_t (*Read)(void); void (*Write)(uint8_t txdata); bool (*TransmitReady)(void); bool (*DataReady)(void); void (*SetTxISR)(void (* interruptHandler)(void)); void (*RxDefaultISR)(void); void (*SetRxISR)(void (* interruptHandler)(void)); bool (*TransmitDone)(void); void (*TxDefaultISR)(void); void (*Initialize)(void);  } uart_functions_t;

extern const uart_functions_t uart[];

/**
 * @brief  interface uart init
 * @return status code
 *         - 0 success
 *         - 1 uart init failed
 * @note   none
 */
uint8_t sps30_interface_uart_init(void);

/**
 * @brief  interface uart deinit
 * @return status code
 *         - 0 success
 *         - 1 uart deinit failed
 * @note   none
 */
uint8_t sps30_interface_uart_deinit(void);

/**
 * @brief      interface uart read
 * @param[out] *buf points to a data buffer
 * @param[in]  len is the length of the data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint16_t sps30_interface_uart_read(uint8_t *buf, uint16_t len);

/**
 * @brief     interface uart write
 * @param[in] *buf points to a data buffer
 * @param[in] len is the length of the data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t sps30_interface_uart_write(uint8_t *buf, uint16_t len);

/**
 * @brief  interface uart flush
 * @return status code
 *         - 0 success
 *         - 1 uart flush failed
 * @note   none
 */
uint8_t sps30_interface_uart_flush(void);

/**
 * @brief     interface delay ms
 * @param[in] ms
 * @note      none
 */
void sps30_interface_delay_ms(uint32_t ms);

/**
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @note      none
 */
void sps30_interface_debug_print(const char *const fmt, ...);

/**
 * @}
 */

#endif	// _UART_H