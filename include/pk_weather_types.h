#ifndef PK_WEATHER_TYPES_H
#define PK_WEATHER_TYPES_H

namespace pk::weather {
    enum class types : unsigned char {
        WEATHER_NONE,
        WEATHER_SUNNY,
        WEATHER_SEMI_CLOUD,
        WEATHER_CLOUD,
        WEATHER_LIGHT_RAIN,
        WEATHER_RAIN,
        WEATHER_HEAVY_RAIN,
        WEATHER_LIGHT_WIND,
        WEATHER_WIND,
        WEATHER_HEAVY_WIND,
        WEATHER_STORM,
        WEATHER_WIND_STORM,
        WEATHER_SNOW,
        WEATHER_SNOW_STORM,
        WEATHER_SAND_STORM, // probably not going to use, maybe in badlands
        WEATHER_CAVE,
        WEATHER_UNDERWATER_BUBBLES,
        WEATHER_DUSTY, 
    };
}

#endif