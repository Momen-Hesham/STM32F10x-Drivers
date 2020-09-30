/*
 * IR_program.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Mo'men
 */

#ifndef IR_CONFIG_H
#define IR_CONFIG_H

/* You MUST Enable AFIO clk Selected PORT clk by RCC */

/* Options:	GPIOA,PIN0...PIN7
 * 			GPIOB,PIN0...PIN7
 * 			GPIOC,PIN13(PIN14,PIN15)
 */
#define IR_INPUT_PORT	GPIOC
#define IR_INPUT_PIN	PIN14

#endif
