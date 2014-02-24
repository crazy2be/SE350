/**
 * @brief: main routine for echoing user input through UART0 by interrupt.
 * @file:  main_irq.c
 * @author: Yiqing Huang
 * @date: 2014/02/11
 */

#include <LPC17xx.h>
#include <system_LPC17xx.h>
#include "uart.h"
#include "uart_polling.h"
#ifdef DEBUG_0
#include "printf.h"
#endif // DEBUG_0

int main()
{
	SystemInit();	
	__disable_irq();
	
	uart0_irq_init(); // uart0 interrupt driven, for RTX console
	uart1_init();     // uart1 polling, for debugging
	
#ifdef DEBUG_0
	init_printf(NULL, putc);
#endif
	__enable_irq();

	uart1_put_string("COM1> Type a character at COM0 terminal\n\r");
	
	// Wait for interrupts
	while (1) {}
}
