#ifndef PK_WEATHER_H
#define PK_WEATHER_H

#include "pk_map_weather_tables.inc"
#include "pk_weather_types.h"

#include "bn_color.h"
#include "bn_random.h"
#include "bn_core.h"

namespace pk::weather {
    // Possible weathers that can be gotten from rng
    const types random_weathers[] = {
        types::WEATHER_NONE,
        types::WEATHER_SUNNY,
        types::WEATHER_LIGHT_RAIN,
        types::WEATHER_RAIN,
        types::WEATHER_HEAVY_RAIN,
        types::WEATHER_STORM,
        types::WEATHER_LIGHT_WIND,
        types::WEATHER_WIND,
        types::WEATHER_HEAVY_WIND
    };

    void update(bn::random& rand) {
        // if (pk::common::last_weather_update)
        for (unsigned short i = 0; i < pk::weather::map_tables_length; ++i) {
            unsigned char num = rand.get_int(100);
            for (unsigned char j = 0 ; j < 6; j++) {
                if (num < pk::weather::map_tables[i][j]) {
                    
                }
            }
        }
    }
}

#endif