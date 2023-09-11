/****************************************************/
/******* Author   :  Kareem Amr Ahmed   *************/
/******* Date     :  1 sep 2023         *************/
/******* File Name:  BIT_MATH.h         *************/
/****************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT_NUMBER)  REG |= (1 << BIT_NUMBER)               
#define CLR_BIT(REG, BIT_NUMBER)  REG &= ~(1 << BIT_NUMBER)               
#define TOG_BIT(REG, BIT_NUMBER)  REG ^= (1 << BIT_NUMBER)               
#define GET_BIT(REG, BIT_NUMBER)  ((REG & (1 << BIT_NUMBER)) >> BIT_NUMBER)              


#endif /*BIT_MATH_H*/