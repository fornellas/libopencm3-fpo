#ifndef USART_H
#define USART_H

#include <inttypes.h>
#include <libopencm3/stm32/rcc.h>

void usart_setup(
	enum rcc_periph_clken rcc_usart_port,
	enum rcc_periph_clken rcc_usart,
	enum rcc_periph_clken rcc_usart_tx,
	uint32_t port_usart_tx,
	uint16_t gpio_usart_tx,
	enum rcc_periph_clken rcc_usart_rx,
	uint32_t port_usart_rx,
	uint16_t gpio_usart_rx,
	uint32_t usart,
	uint32_t baudrate,
	uint32_t databits,
	uint32_t stopbits,
	uint32_t mode,
	uint32_t parity,
	uint32_t flow_control
);

#endif