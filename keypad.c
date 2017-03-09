#include <stdio.h>
#include "keypad.h"
GPIO_InitTypeDef GPIOA_init;
GPIO_InitTypeDef GPIOC_init;


//Initializes used pins rows: A1, A2, A3, A4 and columns: C0, C1, C2.
//This method is used to read rows (not columns).
void init_rows(void) {
      //Initialize the rows of the keypad.
			GPIOA_init.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4;
			GPIOA_init.Mode = GPIO_MODE_IT_RISING;
			GPIOA_init.Pull = GPIO_PULLUP;
			GPIOA_init.Speed = GPIO_SPEED_FREQ_LOW;
  
      //Initiialize the columns of the keypad.
			GPIOC_init.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
			GPIOC_init.Mode = GPIO_MODE_OUTPUT_PP;
			GPIOC_init.Pull = GPIO_NOPULL;
			GPIOC_init.Speed = GPIO_SPEED_FREQ_LOW;
  
			HAL_GPIO_Init(GPIOA, &GPIOA_init);
			HAL_GPIO_Init(GPIOC, &GPIOC_init);
}

//Initializes used pins rows: A1, A2, A3, A4 and columns: C0, C1, C2.
//This method is used to read columns (not rows).
void init_columns(void) {
      //Initialize the rows of the keypad.
			GPIOA_init.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4;
			GPIOA_init.Mode = GPIO_MODE_OUTPUT_PP;
			GPIOA_init.Pull = GPIO_NOPULL;
			GPIOA_init.Speed = GPIO_SPEED_FREQ_LOW;
  
      //Initiialize the columns of the keypad.
			GPIOC_init.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2;
			GPIOC_init.Mode = GPIO_MODE_IT_RISING;
			GPIOC_init.Pull = GPIO_PULLUP;
			GPIOC_init.Speed = GPIO_SPEED_FREQ_LOW;
  
			HAL_GPIO_Init(GPIOA, &GPIOA_init);
			HAL_GPIO_Init(GPIOC, &GPIOC_init);
}
//Checks if a row has been pressed and returns a value of the row pressed (otherwise 0).
uint8_t read_rows(void){
	init_rows();
	//If a row button has been pressed return that number if not return 0.
	if(!HAL_GPIO_READPin(GPIOA, GPIO_PIN_1)) return 1;
	else if(!HAL_GPIO_READPin(GPIOA, GPIO_PIN_2)) return 2;
	else if(!HAL_GPIO_READPin(GPIOA, GPIO_PIN_3)) return 3;
	else if(!HAL_GPIO_READPin(GPIOA, GPIO_PIN_4)) return 4;
	else return 0;

}
//Checks if a column has been pressed and returns a value of the column pressed (otherwise 0).
uint8_t read_columns(void){
	init_columns();
	//If a column button has been pressed return that number if not return 0.
	if(!HAL_GPIO_READPin(GPIOC, GPIO_PIN_0)) return 1;
	else if(!HAL_GPIO_READPin(GPIOC, GPIO_PIN_1)) return 2;
	else if(!HAL_GPIO_READPin(GPIOC, GPIO_PIN_2)) return 3;
	else return 0;

}	
}
