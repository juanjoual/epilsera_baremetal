/**
 ****************************************************************************************
 *
 * @file custom_config_ram.h
 *
 * @brief Custom configuration file for bare-metal applications executing from RAM.
 *
 * The MIT License (MIT)
 * Copyright (c) 2023 Dialog Semiconductor
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 ****************************************************************************************
 */

#ifndef CUSTOM_CONFIG_RAM_H_
#define CUSTOM_CONFIG_RAM_H_

#include "bsp_definitions.h"

#define CONFIG_RETARGET

#define dg_configUSE_LP_CLK                     ( LP_CLK_32768 )
#define dg_configCODE_LOCATION                  NON_VOLATILE_IS_NONE

#define dg_configUSE_WDOG                       ( 0 )

#define dg_configFLASH_CONNECTED_TO             ( FLASH_IS_NOT_CONNECTED )

#define dg_configUSE_SW_CURSOR                  ( 1 )

#define OS_BAREMETAL

/*************************************************************************************************\
 * System Configuration
 */
#define dg_configSYSTEMVIEW                     ( 0 )

/*************************************************************************************************\
 * Peripheral specific config
 */

#define dg_configRF_ENABLE_RECALIBRATION        ( 0 )

#define dg_configFLASH_ADAPTER                  ( 0 )
#define dg_configNVMS_ADAPTER                   ( 0 )
#define dg_configNVMS_VES                       ( 0 )
#define dg_configPMU_ADAPTER                    ( 0 )
#define dg_configCRYPTO_ADAPTER                 ( 0 )

#define dg_configUSE_HW_USB                     ( 0 )

#define dg_configUSE_SYS_TRNG                   ( 0 )
#define dg_configUSE_SYS_DRBG                   ( 0 )

#define dg_configFLASH_AUTODETECT               ( 1 )
#define dg_configOQSPI_FLASH_AUTODETECT         ( 1 )

/* Include bsp default values */
#include "bsp_defaults.h"
/* Include middleware default values */
#include "middleware_defaults.h"

#endif /* CUSTOM_CONFIG_RAM_H_ */
