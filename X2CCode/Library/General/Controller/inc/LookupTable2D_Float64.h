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
/* Description: Two dimensional look-up table with selectable number of entries */
/* USERCODE-END:Description                                                                                           */
#ifndef LOOKUPTABLE2D_FLOAT64_H
#define LOOKUPTABLE2D_FLOAT64_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(LOOKUPTABLE2D_FLOAT64_ISLINKED)
#define LOOKUPTABLE2D_FLOAT64_ID ((uint16)308)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    float64         *x;
    float64         *y;
    float64         Out;
const  float64      *Table;
    uint16          dimX;
    float64         gainX;
    float64         offsetX;
    uint16          dimY;
    float64         gainY;
    float64         offsetY;
    float64         minX;
    float64         maxX;
    float64         minY;
    float64         maxY;
} LOOKUPTABLE2D_FLOAT64;
#else
typedef struct {
    uint16          ID;
    FLOAT64_PTR     x;
    FLOAT64_PTR     y;
    float64         Out;
const  FLOAT64_PTR  Table;
    uint16          dimX;
    float64         gainX;
    float64         offsetX;
    uint16          dimY;
    float64         gainY;
    float64         offsetY;
    float64         minX;
    float64         maxX;
    float64         minY;
    float64         maxY;
} LOOKUPTABLE2D_FLOAT64;
#endif

#define LOOKUPTABLE2D_FLOAT64_FUNCTIONS { \
    LOOKUPTABLE2D_FLOAT64_ID, \
    (void (*)(void*))LookupTable2D_Float64_Update, \
    (void (*)(void*))LookupTable2D_Float64_Init, \
    (tLoadImplementationParameter)LookupTable2D_Float64_Load, \
    (tSaveImplementationParameter)LookupTable2D_Float64_Save, \
    (void* (*)(const void*, uint16))LookupTable2D_Float64_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void LookupTable2D_Float64_Update(LOOKUPTABLE2D_FLOAT64 *pTLookupTable2D_Float64);
void LookupTable2D_Float64_Init(LOOKUPTABLE2D_FLOAT64 *pTLookupTable2D_Float64);
uint8 LookupTable2D_Float64_Load(const LOOKUPTABLE2D_FLOAT64 *pTLookupTable2D_Float64, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 LookupTable2D_Float64_Save(LOOKUPTABLE2D_FLOAT64 *pTLookupTable2D_Float64, const uint8 data[], uint16 dataLength);
void* LookupTable2D_Float64_GetAddress(const LOOKUPTABLE2D_FLOAT64 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
