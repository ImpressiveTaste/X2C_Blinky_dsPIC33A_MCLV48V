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
/* Description: 	Makes the incoming signal accessible for reading with parameter numbers.						  */
/*																													  */
/* USERCODE-END:Description                                                                                           */
#ifndef SAVESIGNAL_FLOAT32_H
#define SAVESIGNAL_FLOAT32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(SAVESIGNAL_FLOAT32_ISLINKED)
#define SAVESIGNAL_FLOAT32_ID ((uint16)323)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    float32         *In;
} SAVESIGNAL_FLOAT32;
#else
typedef struct {
    uint16          ID;
    FLOAT32_PTR     In;
} SAVESIGNAL_FLOAT32;
#endif

#define SAVESIGNAL_FLOAT32_FUNCTIONS { \
    SAVESIGNAL_FLOAT32_ID, \
    (void (*)(void*))Common_Update, \
    (void (*)(void*))SaveSignal_Float32_Init, \
    (tLoadImplementationParameter)SaveSignal_Float32_Load, \
    (tSaveImplementationParameter)Common_Save, \
    (void* (*)(const void*, uint16))SaveSignal_Float32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void SaveSignal_Float32_Init(SAVESIGNAL_FLOAT32 *pTSaveSignal_Float32);
uint8 SaveSignal_Float32_Load(const SAVESIGNAL_FLOAT32 *pTSaveSignal_Float32, uint8 data[], uint16 *dataLength, uint16 maxSize);
void* SaveSignal_Float32_GetAddress(const SAVESIGNAL_FLOAT32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
