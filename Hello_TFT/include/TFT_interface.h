/************************************************************************/
/* Author   : Doaa Maher												*/
/* Date     : 21/9/2020													*/
/* Type     : TFT Display												*/
/* Version  : 1.0														*/
/************************************************************************/

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInitialize (void);

// Constant to make it in Flash
void HTFT_voidDisplayImage (const u16 *Copy_Image);

/* Filling any color using color code */
void HTFT_voidFillColor (u16 Copy_u16Color);

/* Displaying any shape you Desire */
void HTFT_voidDrawRectangle (u8 x1 , u8 x2, u8 y1 , u8 y2, u16 Copy_u16Color);







#endif


