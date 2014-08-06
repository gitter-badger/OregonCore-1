/*
 * Copyright (C) 2010-2014 OregonCore <http://www.oregoncore.com/>
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _VMAPDEFINITIONS_H
#define _VMAPDEFINITIONS_H
#include <cstring>

#define LIQUID_TILE_SIZE (533.333f / 128.f)

namespace VMAP
{
    const char VMAP_MAGIC[] = "VMAP_3.0";                   // used in final vmap files
    const char RAW_VMAP_MAGIC[] = "VMAP003";                // used in extracted vmap files with raw data

    // defined in TileAssembler.cpp currently...
    bool readChunk(FILE *rf, char *dest, const char *compare, uint32 len);
}

#ifdef MMAP_GENERATOR
    #include <assert.h>
    #define ASSERT(x) assert(x)
    #define DEBUG_LOG(...) 
    #define DETAIL_LOG(...) 
    #define ERROR_LOG(...) do{ printf("ERROR:"); printf(__VA_ARGS__); printf("\n"); } while(0)
#elif !defined NO_CORE_FUNCS
    #include "Errors.h"
    #include "Log.h"
    #define ERROR_LOG(...) sLog.outError(__VA_ARGS__);
    #define DETAIL_LOG(...) sLog.outDetail(__VA_ARGS__);
#else
    #include <assert.h>
    #define ASSERT(x) assert(x)
    #define DEBUG_LOG(x, ...) printf(x,"\n", ##__VA_ARGS__)
    #define DETAIL_LOG(x, ...) printf(x "\n", ##__VA_ARGS__)
    #define ERROR_LOG(x, ...) printf("ERROR:" x, ##__VA_ARGS__)
#endif

#endif // _VMAPDEFINITIONS_H

