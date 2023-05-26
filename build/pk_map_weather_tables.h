#ifndef PK_MAP_WEATHER_TABLES_H
#define PK_MAP_WEATHER_TABLES_H

namespace pk::weather {
    const uint8_t map_tables[][6] = {
        {0, 0, 0, 0, 0, 0}, // Player's House
        {0, 100, 0, 0, 0, 0}, // Newpine Town
    };
    const uint16_t map_tables_length = 2;
}

#endif
