#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "global_vars.h"

void init_rows(void);

void init_columns(void);
