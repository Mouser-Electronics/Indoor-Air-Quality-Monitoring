/**
\file
\addtogroup doc_driver_uart_code
\brief This file contains the function names of the operations that can be carried out by the UART Foundation Services .
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

/**
  Section: Included Files
 */

#include "uart.h"   


const uart_functions_t uart[] = {   
    {UART2_Read, UART2_Write, UART2_IsTxReady, UART2_IsRxReady, UART2_SetTxInterruptHandler, UART2_Receive_ISR, UART2_SetRxInterruptHandler, UART2_IsTxDone, UART2_Transmit_ISR, UART2_Initialize }
};

uint8_t sps30_interface_uart_init(void)
{
    return 0;
}


uint8_t sps30_interface_uart_deinit(void)
{
    return 0;
}


uint16_t sps30_interface_uart_read(uint8_t *buf, uint16_t len)
{
    return 0;
}


uint8_t sps30_interface_uart_write(uint8_t *buf, uint16_t len)
{
    return 0;
}


uint8_t sps30_interface_uart_flush(void)
{
    return 0;
}


void sps30_interface_delay_ms(uint32_t ms)
{

}


void sps30_interface_debug_print(const char *const fmt, ...)
{
    
}


/**
 End of File
 */
