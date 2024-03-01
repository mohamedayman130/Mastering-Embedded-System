/*
 * rcc.c
 *
 *  Created on: 22 Sep 2023
 *      Author: Alfanan02
 */

#include "inc/rcc.h"

uint8_t apb_pre_scaler[8]={0,0,0,0,1,2,3,4};
uint16_t ahb_pre_scaler [16]={0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};
uint32_t mcal_rcc_get_sysclk1(void)
{

	return 8000000;

}
uint32_t mcal_rcc_get_hclk1(void)
{
    return mcal_rcc_get_sysclk1() >>ahb_pre_scaler[RCC_config->CFGR >>4];
}
uint32_t mcal_rcc_get_pclk1(void)
{
	return mcal_rcc_get_hclk1() >>apb_pre_scaler[RCC_config->CFGR >>8];
}
uint32_t mcal_rcc_get_pclk2(void)
{
	return mcal_rcc_get_hclk1() >>apb_pre_scaler[RCC_config->CFGR >>11];
}
