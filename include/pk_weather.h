#ifndef PK_WEATHER_H
#define PK_WEATHER

#include "pk_common.h"
#include "pk_map_weather_tables.h"

#include "bn_color.h"
#include "bn_random.h"
#include "bn_core.h"

namespace pk::weather {
    const uint8_t WEATHER_NONE = 0;
    const uint8_t WEATHER_SUNNY = 1;
    const uint8_t WEATHER_SEMI_CLOUD = 2;
    const uint8_t WEATHER_CLOUD = 3;
    const uint8_t WEATHER_LIGHT_RAIN = 4;
    const uint8_t WEATHER_RAIN = 5;
    const uint8_t WEATHER_HEAVY_RAIN = 6;
    const uint8_t WEATHER_LIGHT_WIND = 7;
    const uint8_t WEATHER_WIND = 8;
    const uint8_t WEATHER_HEAVY_WIND = 9;
    const uint8_t WEATHER_STORM = 10;
    const uint8_t WEATHER_WIND_STORM = 11;
    const uint8_t WEATHER_SNOW = 12;
    const uint8_t WEATHER_SNOW_STORM = 13;
    const uint8_t WEATHER_SAND_STORM = 14;
    const uint8_t WEATHER_CAVE = 15;
    const uint8_t WEATHER_UNDERWATER_BUBBLES = 16;
    const uint8_t WEATHER_DUSTY = 17;

    // Possible weathers that can be gotten from rng
    const uint8_t random_weathers[] = {
        WEATHER_NONE,
        WEATHER_SUNNY,
        WEATHER_LIGHT_RAIN,
        WEATHER_RAIN,
        WEATHER_HEAVY_RAIN,
        WEATHER_STORM
    };

    // void update(bn::random &rand) {
    //     // if (pk::common::last_weather_update)
    //     for (uint16_t i = 0; i < pk::weather::map_tables_length; ++i) {
    //         uint8_t num = rand.get_int(100);
    //         for (uint8_t j = 0 ; j < 6; j++) {
    //             if (num < pk::weather::map_tables[i][j]) {
                    
    //             }
    //         }
    //     }
    // }
}

#endif