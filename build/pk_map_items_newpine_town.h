#ifndef MAP_NEWPINE_TOWN_H
#define MAP_NEWPINE_TOWN_H

#include "bn_music_items.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_item.h"
#include "bn_size.h"
#include "bn_string_view.h"
#include "pk_maps.h"
#include "pk_weather.h"
#include "pk_seasons.h"

namespace pk::maps::NEWPINE_TOWN {

   extern const uint8_t map_type;
   extern const bn::string_view id;
   extern const bn::string_view name;
   extern const bn::music_item music;
   extern const bn::size map_size;
   extern const bool allow_cycling;
   extern const bool allow_escaping;
   extern const bool requires_flash;
   extern const bool show_map_name;
   extern const bool do_seasons;
   extern const bool do_weather;
   extern const uint8_t default_weather;
   extern const uint8_t default_season;
   extern const uint16_t layout[];
}
#endif