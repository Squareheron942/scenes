#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_titlebg.h"
#include "pk_title_scene.h"
#include "pk_menu_scene.h"
#include "bn_log.h"
#include "bn_string.h"
#include "pk_scenemanager.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "pk_common.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"
#include "bn_regular_bg_map_item.h"
#include "bn_bg_palette_items_txtpal1.h"

#include "pk_map_items_newpine_town.h"
#include "bn_regular_bg_tiles_items_gmap_general.h"
#include "bn_bg_palette_items_gpal_general.h"
#include "bn_bpp_mode.h"
#include "bn_span.h"
#include "bn_regular_bg_tiles_item.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_ptr.h"

pk::scenes::TitleScene::TitleScene() : pk::scene_types::MenuScene(bn::string_view("TITLE_SCREEN"), bn::regular_bg_items::titlebg) {};

void pk::scenes::TitleScene::main() {
    // map.create_map(bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_item(bn::span(pk::maps::NEWPINE_TOWN::layout), bn::bpp_mode::BPP_8)), bn::bg_palette_items::txtpal1.create_palette());
    // pk::SceneManager::cur_bg.value().set_position(8, 48);
    // bn::regular_bg_ptr bg = bn::regular_bg_items::titlebg.create_bg(8, 48);
    const bn::regular_bg_map_item map(pk::maps::NEWPINE_TOWN::layout[0], pk::maps::NEWPINE_TOWN::map_size);
    bn::regular_bg_tiles_ptr tiles = bn::regular_bg_tiles_ptr::create(bn::regular_bg_tiles_items::gmap_general);
    bn::bg_palette_ptr palette = bn::bg_palette_items::gpal_general.create_palette();
    bn::regular_bg_ptr bg = bn::regular_bg_ptr::create(0, 0, map.create_map(tiles, palette));
    bn::log(bn::to_string<16>("Title Screen"));
    pk::maps::NEWPINE_TOWN::music.play(bn::fixed(0.5));
    bn::log(bn::to_string<32>(sizeof((uint16_t*)pk::maps::NEWPINE_TOWN::layout)));
    for (int i = 0; i < (60 * bn::fixed(0.3)); i++) {
        bn::bg_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
        bn::sprite_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
        bn::core::update();
    }
    while(true) {
        if (bn::keypad::a_pressed()) {
            pk::SceneManager::set_load(bn::string_view("SAVE_SEL"), pk::SceneManager::transitions::TRANSITION_FADE, 0.3);
            return;
        }
        bn::core::update();
    }
}