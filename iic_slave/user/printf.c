/**
  ******************************************************************************
  * @file     printf.c
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
#include "../components/ring_buffer.h"
#include "./printf.h"
#include <stdio.h>


/*-- defined -----------------------------------------------------------------*/
#define     PUT_MAX_NUMBER     256


/*-- private variables -------------------------------------------------------*/
static   RingBuffObj    txRingBuffObj;

static   rb_data_type   txBuff[PUT_MAX_NUMBER];

/*-- private functions -------------------------------------------------------*/


/*-- functions ---------------------------------------------------------------*/
/** @function  
  * @brief   
  * @param    	
  * @return  
  */
void   printf_init(void)
{
  txRingBuffObj.depth = PUT_MAX_NUMBER;
	txRingBuffObj.posGet = 0;
	txRingBuffObj.posPut = 0;
	txRingBuffObj.remain = 0;
	txRingBuffObj.ptBuffer = txBuff;
}
	

/** @function  
  * @brief   
  * @param    	
  * @return  
  */
void   printf_loop(void)
{
	rb_data_type  ch = 0;
	
  while(check_ring_buff(&txRingBuffObj) != 0)
	{
		ch = get_ring_buff_data(&txRingBuffObj);
	  hal_uart1_send((u8_t *)&ch);
	}
}
	
	
/** @function  
  * @brief   
  * @param    	
  * @return  
  */
int fputc(int ch,FILE *f)
{
	put_ring_buff_data(&txRingBuffObj, ch);
	
	return ch;
}

/*------------------ end of file ---------------------------------------------*/

