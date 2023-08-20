#ifndef PK_MAPS_H
#define PK_MAPS_H

#include "bn_core.h"

namespace pk::maps
{
    // namespace types {
    //     const uint8_t MAP_TYPE_NONE = 0;
    //     const uint8_t MAP_TYPE_TOWN = 1;
    //     const uint8_t MAP_TYPE_CITY = 2;
    //     const uint8_t MAP_TYPE_ROUTE = 3;
    //     const uint8_t MAP_TYPE_UNDERGROUND = 4;
    //     const uint8_t MAP_TYPE_UNDERWATER = 5;
    //     const uint8_t MAP_TYPE_OCEAN_ROUTE = 6;
    //     const uint8_t MAP_TYPE_UNKNOWN = 7;
    //     const uint8_t MAP_TYPE_INDOOR = 8;
    //     const uint8_t MAP_TYPE_SECRET_BASE = 9;
    // }
    
        enum class types : unsigned char {
            MAP_TYPE_NONE,
            MAP_TYPE_TOWN,
            MAP_TYPE_CITY,
            MAP_TYPE_ROUTE,
            MAP_TYPE_UNDERGROUND,
            MAP_TYPE_UNDERWATER,
            MAP_TYPE_OCEAN_ROUTE,
            MAP_TYPE_UNKNOWN,
            MAP_TYPE_INDOOR,
            MAP_TYPE_SECRET_BASE
        };
} // namespace pk::maps


#endif