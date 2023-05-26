#ifndef PK_MAPS_H
#define PK_MAPS_H

#include "bn_core.h"

namespace pk::maps
{
    namespace types {
        const uint8_t MAP_TYPE_NONE = 0;
        const uint8_t MAP_TYPE_TOWN = 1;
        const uint8_t MAP_TYPE_CITY = 2;
        const uint8_t MAP_TYPE_ROUTE = 3;
        const uint8_t MAP_TYPE_UNDERGROUND = 4;
        const uint8_t MAP_TYPE_UNDERWATER = 5;
        const uint8_t MAP_TYPE_OCEAN_ROUTE = 6;
        const uint8_t MAP_TYPE_UNKNOWN = 7;
        const uint8_t MAP_TYPE_INDOOR = 8;
        const uint8_t MAP_TYPE_SECRET_BASE = 9;
    }
} // namespace pk::maps


#endif