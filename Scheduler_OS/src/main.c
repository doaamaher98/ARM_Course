#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "OS_interface.h"
#include "STK_interface.h"

#include "OS_private.h"
#include "OS_config.h"

/* Prototypes */
void LED1 (void);
void LED2 (void);
void LED3 (void);


int main(void)
{
	/* Intialization */
	/* RCC init */
	
	/* Enable GPIO RCC PORTA */
	
	/* GPIO init 	Direction		 */
	
	SOS_voidCreateTask(0,1000,LED1);
	SOS_voidCreateTask(1,2000,LED2);
	SOS_voidCreateTask(2,3000,LED3);
	
	SOS_voidStart();
	while(1)
	{
		
	}
	return 0;
	
}

/* Toggle LED */
void LED1 (void)
{
	static u8 Local_u8Pin1 = 0;
	TOG_BIT(Local_u8Pin1 ,0);
	
	MGPIO_voidSetPinValue(GPIOA, PIN1, Local_u8Pin1);
}

void LED2 (void)
{
	static u8 Local_u8Pin2 = 0;
	TOG_BIT(Local_u8Pin2 ,0);
	
	MGPIO_voidSetPinValue(GPIOA, PIN2, Local_u8Pin2);
}

void LED3 (void)
{
	static u8 Local_u8Pin3 = 0;
	TOG_BIT(Local_u8Pin3 ,0);
	
	MGPIO_voidSetPinValue(GPIOA, PIN3, Local_u8Pin3);
}
