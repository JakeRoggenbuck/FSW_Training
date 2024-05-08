#ifndef REALOP1_GLOBALS_H_
#define REALOP1_GLOBALS_H_

#include "stm32l476xx.h"


#define OP_REV 1

#if OP_REV == 1 || OP_REV == 2
#define UNUSED_GPIO             GPIOG, 1
#define LOCK_UNUSED_GPIO_HIGH() GPIOG->PUPDR |= (1 << GPIO_PUPDR_PUPD1)
#endif

typedef enum {false, true} bool;
#define NULL 0

/*
 * Insert a certain number of Assembly nop instructions
 *
 * @param   The number of nop instructions to wait for
 * @return  None
 */
void nop(long long nop_loops);

/*
 * Returns the number of milliseconds elapsed since the board started
 *
 * @return  The number of milliseconds as an int
 */
uint64_t getSysTime();

/*
 * Adds a delay for a certain number of milliseconds
 *
 * @param The number of ms to delay by
 */
void delay_ms(uint64_t delay_ms);

#endif // REALOP1_GLOBALS_H_
