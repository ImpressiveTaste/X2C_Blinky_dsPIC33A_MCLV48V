/*
 * Copyright (c) 2013, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
 *       the names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 2584 $
 */
/* USERCODE-BEGIN:Description                                                                                         */
/*      Description: With lookup table approximated arc tangent function	  */
/*                      Calculation:                                          */
/* 							theta = atan2(y,x)						 		  */
/* 						Range:												  */
/* 							y:		-1..1								 	  */
/* 							x:		-1..1								 	  */
/* 							theta:	-pi..pi 								  */
/* 										--> with -pi..pi ~ -1..1		 	  */
/* 																			  */
/* USERCODE-END:Description                                                                                           */
#ifndef ATAN2_FIP8_H
#define ATAN2_FIP8_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(ATAN2_FIP8_ISLINKED)
#define ATAN2_FIP8_ID ((uint16)4880)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    int8            *y;
    int8            *x;
    int8            Out;
} ATAN2_FIP8;
#else
typedef struct {
    uint16          ID;
    INT8_PTR        y;
    INT8_PTR        x;
    int8            Out;
} ATAN2_FIP8;
#endif

#define ATAN2_FIP8_FUNCTIONS { \
    ATAN2_FIP8_ID, \
    (void (*)(void*))Atan2_FiP8_Update, \
    (void (*)(void*))Atan2_FiP8_Init, \
    (tLoadImplementationParameter)Common_Load, \
    (tSaveImplementationParameter)Common_Save, \
    (void* (*)(const void*, uint16))Atan2_FiP8_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void Atan2_FiP8_Update(ATAN2_FIP8 *pTAtan2_FiP8);
void Atan2_FiP8_Init(ATAN2_FIP8 *pTAtan2_FiP8);
void* Atan2_FiP8_GetAddress(const ATAN2_FIP8 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
