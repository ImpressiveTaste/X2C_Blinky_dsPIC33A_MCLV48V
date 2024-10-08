/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Date:  2024-09-12 10:33                                                                                            */

/* X2C-Version: 6.5.3419                                                                                              */
/* X2C-Edition: Free                                                                                                  */

#include "RamTable.h"

int16 RamTable_int16[2];

static const int16 RamTable_int16_init[2] = {0,0}; 

void initRamTables()
{
    uint16 i;

    for (i = 0; i < 2; i++)
    {
        RamTable_int16[i] = RamTable_int16_init[i];
    }
}
