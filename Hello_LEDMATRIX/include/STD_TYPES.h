// 1st Header file guard same name as the file name.
// No dots in macros, replace it with an underscore "-".
/**************************************************************/
/* Author : Doaa Maher                                        */
/* Date : 7/8/2020                                            */
/* Version : V01                                              */
/**************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

// Defining new types (to be standerd with those no. of bits 
// u = "unsigned" 

typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef long int               u32;

typedef signed char 			s8;
typedef signed short 			s16;
typedef signed long 			s32;

#define STD_u8_ERROR_NOK 	 	(u8)1
#define STD_u8_ERROR_OK   		(u8)0

#define Null ((void *)0)


#endif

