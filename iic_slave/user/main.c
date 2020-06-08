/**
  ******************************************************************************
  * @file     main.c
  * @author   ZRT
  * @version  V1.0
  * @date     2020/01/09
  * @attention  
	* @warning	
  ******************************************************************************  
  * 
  * 
  ******************************************************************************
  */
/*-- includes ----------------------------------------------------------------*/
#include "./main.h"
#include "./printf.h"
#include "./led.h"

/*-- defined -----------------------------------------------------------------*/
#define   DB_LOG(fmt, ...)       LOG("[MAIN]");LOG(fmt, ##__VA_ARGS__)


/*-- private variables -------------------------------------------------------*/


/*-- private functions -------------------------------------------------------*/


/*-- functions ---------------------------------------------------------------*/

/** @function  
  * @brief   
  * @param    
  * @param    
  * @return  
  */
int main(void)
{
	/* When system start, it should be disable the global interrupt. */
	GLOBAL_INTERRUPT_DISABLE();
	
	/* mcu common init. */
	hal_mcu_init();
	//freq = hal_get_sys_freq();
	
	/* Enable global interrupt. */
	GLOBAL_INTERRUPT_ENABLE();
	
	/* user init process. */
	printf_init();
	led_init();
	
	/* Loop. */
	while(1)
	{
	  printf_loop();
	}
}


/*------------------ end of file ---------------------------------------------*/

