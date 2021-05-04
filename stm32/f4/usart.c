#include "usart.h"
#include <stdio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

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
) {
	rcc_periph_clock_enable(rcc_usart_port);
	rcc_periph_clock_enable(rcc_usart_tx);
	rcc_periph_clock_enable(rcc_usart_rx);
	rcc_periph_clock_enable(rcc_usart);

	gpio_mode_setup(port_usart_tx, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_usart_tx);
	gpio_set_af(port_usart_tx, GPIO_AF7, gpio_usart_tx);
	gpio_mode_setup(port_usart_rx, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_usart_rx);
	gpio_set_af(port_usart_rx, GPIO_AF7, gpio_usart_rx);

	usart_set_baudrate(usart, baudrate);
	usart_set_databits(usart, databits);
	usart_set_stopbits(usart, stopbits);
	usart_set_mode(usart, mode);
	usart_set_parity(usart, parity);
	usart_set_flow_control(usart, flow_control);

	usart_enable(usart);
}