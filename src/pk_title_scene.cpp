#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_titlebg.h"
#include "pk_title_scene.h"
#include "bn_log.h"
#include "bn_string.h"
#include "pk_scenemanager.h"
#include "bn_core.h"
#include "bn_keypad.h"

#include "pk_common.h"

#include "bn_music_items.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"
#include "bn_regular_bg_map_item.h"
#include "bn_bg_palette_items_txtpal1.h"

#include "pk_map_items_newpine_town.h"
#include "bn_regular_bg_tiles_items_outdoors.h"
#include "bn_bg_palette_items_gpal_outdoors.h"
#include "bn_bpp_mode.h"
#include "bn_span.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_ptr.h"
#include "pk_core.h"
#include "bn_point.h"
#include "bn_fixed_point.h"

pk::scenes::TitleScene::TitleScene() : 
    pk::Scene("Newpine Town"),
    palette(bn::bg_palette_items::gpal_outdoors.create_palette()), 
    tiles(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::outdoors)), 
    map(bn::regular_bg_map_item(pk::maps::NEWPINE_TOWN::layout[0], 
    pk::maps::NEWPINE_TOWN::map_size)),
    bg(bn::regular_bg_ptr::create(0, 0, map.create_map(tiles, palette) /*bn::regular_bg_map_ptr::create(map)*/))
{
    pk::common::bgpos = bn::point(0, 0);
    pk::maps::NEWPINE_TOWN::music.play(bn::fixed(0.5));
    bn::log(bn::to_string<32>(name));
    for (int i = 0; i < 18; i++) {
        bn::bg_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
        bn::sprite_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
        bn::core::update();
    }
};

void pk::scenes::TitleScene::main() {
    
    if (bn::keypad::a_pressed()) pk::SceneManager::set_load(bn::string_view("SAVE_SEL"), pk::SceneManager::transitions::TRANSITION_FADE, 0.3);
    if (bn::keypad::up_held()) pk::common::bgpos.set_y(pk::common::bgpos.y() + 1);
    if (bn::keypad::down_held()) pk::common::bgpos.set_y(pk::common::bgpos.y() - 1);
    if (bn::keypad::right_held()) pk::common::bgpos.set_x(pk::common::bgpos.x() - 1);
    if (bn::keypad::left_held()) pk::common::bgpos.set_x(pk::common::bgpos.x() + 1);

    bg.set_position((bn::fixed_point)pk::common::bgpos);
}