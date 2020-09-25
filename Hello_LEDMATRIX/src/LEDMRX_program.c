/************************************************/
/* Author 	: Doaa Maher 						*/
/* Date   	: 31/8/2020							*/
/* Type 	: lED MATRIX DRIVER					*/
/* Version	: 1.0 								*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"

#include "LEDMRX_private.h"
#include "GPIO_private.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

/*
void HLEDMRX_voidInt(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN, OUTPUT_SPEED_2MHZ_PP);

	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN, OUTPUT_SPEED_2MHZ_PP);
}


void HLEDMRX_voidDisplay (u8 *Copy_u8Data)
{
	while (1) 
	{
	//					Column 0
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[0]);
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	
	//							Column 1
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[1]);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	
	//						Column 2
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[2]);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec
	
	//						Column 3
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[3]);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5 msec
	
	//						Column 4
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[4]);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	//						Column 5
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[5]);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	//						Column 6
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[6]);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	//						Column 7
	DisableAllColumns();
		
	SetRowValues(Copy_u8Data[7]);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	}
}

static void DisableAllColumns(void) // Used only by me
{
	//				Disable all Columns
	MGPIO_voidSetPinValue (LEDMRX_COL0_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL1_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL2_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL3_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL4_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL5_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL6_PIN , GPIO_HIGH);
	MGPIO_voidSetPinValue (LEDMRX_COL7_PIN , GPIO_HIGH);
}
static void SetRowValues(u8 Copy_u8Value) // Used only by me
{
	u8 Local_u8BIT;

	 //					Enable Column 0 = Wanted one
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN , Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN , Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,  2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN , Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN , Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN , Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN , Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN , Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value, 7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN , Local_u8BIT);
}

*/
/***************************************************************************/



u8 rows[16] = { LEDMRX_ROW0, LEDMRX_ROW1, LEDMRX_ROW2, LEDMRX_ROW3, LEDMRX_ROW4,
			   LEDMRX_ROW5, LEDMRX_ROW6, LEDMRX_ROW7 };

u8 columns[16] = { LEDMRX_COLUMN0, LEDMRX_COLUMN1, LEDMRX_COLUMN2, LEDMRX_COLUMN3,
				  LEDMRX_COLUMN4, LEDMRX_COLUMN5, LEDMRX_COLUMN6, LEDMRX_COLUMN7 };


void LEDMRX_voidInit(void)
{

	for (u8 i = 0; i <= 7; i++)
	{
		MGPIO_voidSetPinDirection (GPIO_A ,rows[i*2 + 1], OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection (GPIO_B ,columns[i*2 + 1], OUTPUT_SPEED_2MHZ_PP);
	}
}


void LEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	u8 Local_u8BIT;
		while(1)
		{
			for(u8 i =0; i <= 7; i++){
				for(u8 j =0; j <= 7; j++)
				{
					MGPIO_voidSetPinValue(columns[j*2], columns[j*2 + 1], GPIO_HIGH);
				}
				for(u8 k =0; k <= 7; k++){
					Local_u8BIT = GET_BIT(Copy_u8Data[i], k);
					MGPIO_voidSetPinValue(rows[k*2], rows[k*2 + 1], Local_u8BIT);
				}
				MGPIO_voidSetPinValue(columns[i*2], columns[i*2 + 1], GPIO_LOW);
				MSTK_voidSetBusyWait(1);
			}
		}
	}
void HLEDMRX_voidAnimation(u8 *Copy_u8Data)
{
	u8  Local_u8BIT;
		while(1)
		{
			for (u8 m = 0; m < 30; m++) // 30 Column needed --> 30x50 = 1500, then FPS for 1 led = 1/1500 = delay time = 0.6 msec
			{
			u8 x = 0;
			// My data intialized
			u8 Local_temp_data [8] = {Copy_u8Data[m], Copy_u8Data[m + 1],Copy_u8Data[m + 2],Copy_u8Data[m + 3],Copy_u8Data[m + 4],Copy_u8Data[m + 5],Copy_u8Data[m + 6],Copy_u8Data[m + 7]};
			while (x <= 50) // FPS = 50Hz
			{
			x++; // x = {1, 2, 3, 4, 5, ..., 50}
			for(u8 i =0; i <= 7; i++) 		// Rows
			{
				for(u8 j =0; j <= 7; j++) 	// Columns
					{
					/* SET COLUMNS pins value 									*/
						MGPIO_voidSetPinValue(columns[j*2], columns[j*2 + 1], GPIO_HIGH);
					}
				for(u8 k =0; k <= 7; k++) 	// My Entered Data
			{
						Local_u8BIT = GET_BIT(Local_temp_data[i], k);
						MGPIO_voidSetPinValue(rows[k*2], rows[k*2 + 1], Local_u8BIT);
			}

			MGPIO_voidSetPinValue(columns[i*2], columns[i*2 + 1], GPIO_LOW);
			MSTK_voidSetBusyWait(1);
			}
								}
			}
		}
}


/*static void LEDMRX_voidSetColumns(void)
{
	for (u8 j = 0; j <= 7; j++)
	{
		GPIO_voidSetPinDirection(columns[j], GPIO_HIGH);
	}
}

static void LEDMRX_voidSetRowValue(u8 Copy_u8Data)
{
	u8 LOC_u8BIT;
	for (u8 k = 0; k <= 7; k++)
	{
		LOC_u8BIT = GET_BIT(Copy_u8Data, k);
		GPIO_voidSetPinValue(rows[k], LOC_u8BIT);
	}
}*/



