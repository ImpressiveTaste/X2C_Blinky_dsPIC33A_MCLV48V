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
/* Description:
 *    Calculation of L2-Norm: ||u|| = sqrt(u1^2 + u2^2)
 */
/* USERCODE-END:Description                                                                                           */
#ifndef L2NORM_FIP32_H
#define L2NORM_FIP32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(L2NORM_FIP32_ISLINKED)
#define L2NORM_FIP32_ID ((uint16)5058)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    int32           *u1;
    int32           *u2;
    int32           Out;
} L2NORM_FIP32;
#else
typedef struct {
    uint16          ID;
    INT32_PTR       u1;
    INT32_PTR       u2;
    int32           Out;
} L2NORM_FIP32;
#endif

#define L2NORM_FIP32_FUNCTIONS { \
    L2NORM_FIP32_ID, \
    (void (*)(void*))L2Norm_FiP32_Update, \
    (void (*)(void*))L2Norm_FiP32_Init, \
    (tLoadImplementationParameter)Common_Load, \
    (tSaveImplementationParameter)Common_Save, \
    (void* (*)(const void*, uint16))L2Norm_FiP32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void L2Norm_FiP32_Update(L2NORM_FIP32 *pTL2Norm_FiP32);
void L2Norm_FiP32_Init(L2NORM_FIP32 *pTL2Norm_FiP32);
void* L2Norm_FiP32_GetAddress(const L2NORM_FIP32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
