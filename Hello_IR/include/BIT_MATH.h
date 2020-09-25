/**************************************************************/
/* Author : Doaa Maher                                        */
/* Date : 7/8/2020                                            */
/* Version : V01                                              */
/**************************************************************/
// 1st Header file guard same name as the file name.
#ifndef BIT_MATH_H
#define BIT_MATH_H

// Defining some operation on bits (only 4 are needed)
#define SET_BIT(VAR,BIT)                  VAR |=  (1 << (BIT))
// To set bit                           
#define CLR_BIT(VAR,BIT)                  VAR &= ~(1 << (BIT)) 
// To clear bit                        
#define GET_BIT(VAR,BIT)                 ((VAR >> BIT) & 1  )
// To get bit we must move it to right 
#define TOG_BIT(VAR,BIT)                  VAR ^=  (1 << (BIT))
// To toggle a bit                   

#endif