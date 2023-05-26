#ifndef PK_MAP_ITEMS_OLDALE_H
#define PK_MAP_ITEMS_OLDALE_H

#include "bn_music_items.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_item.h"
#include "bn_size.h"
#include "bn_string_view.h"
#include "pk_maps.h"

namespace pk::maps::NEWPINE_TOWN
{
    const uint8_t map_type = pk::maps::types::MAP_TYPE_TOWN;
    const bn::string_view id("MAP_NEWPINE_TOWN");
    const bn::string_view name("Newpine Town");
    const bn::music_item music = bn::music_items::cyberrid;
    // const bn::regular_bg_item bg0;
    const bn::size map_size(40, 40);
    const bool allow_cycling = true;
    const bool allow_escaping = false;
    const bool allow_running = true;
    const bool requires_flash = true;
    const bool show_map_name = true;
    const bool do_seasons = true;
    const bool do_weather = true;

    const uint16_t layout[] = {};
}


#endif