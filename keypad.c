#include <stdio.h>
#include "keypad.h"
GPIO_InitTypeDef GPIOA_init;
GPIO_InitTypeDef GPIOC_init;

//Initialized used pins rows: A1, A2, A3, A4 and columns: C0, C1, C2.
void init_GPIO() {
      //Initialize the rows of the keypad.
			GPIOA_init.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4;
			GPIOA_init.Mode = GPIO_MODE_IT_RISING;
			GPIOA_init.Pull = GPIO_PULLUP;
			GPIOA_init.Speed = GPIO_SPEED_FREQ_LOW;
  
      //Initiialize the columns of the keypad.
			GPIOC_init.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
			GPIOC_init.Mode = GPIO_MODE_IT_RISING;
			GPIOC_init.Pull = GPIO_PULLUP;
			GPIOC_init.Speed = GPIO_SPEED_FREQ_LOW;
  
			HAL_GPIO_Init(GPIOA, &GPIOA_init);
			HAL_GPIO_Init(GPIOC, &GPIOC_init);
}
