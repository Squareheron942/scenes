#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_background.h"
#include "save_sel.h"
#include "bn_log.h"
#include "bn_string.h"
#include "pk_scenemanager.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "pk_common.h"
#include "bn_sram.h"
#include "bn_fixed.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"
#include "bn_music_items.h"
#include "pk_core.h"
#include "bn_fixed_point.h"
#include "bn_point.h"

pk::scenes::SaveSel::SaveSel() : pk::Scene("Save Select"), bg0(bn::regular_bg_items::background.create_bg(8, 0)) {

    bn::sram::read(pk::common::sav);
    if (!pk::common::sav.flags.has_sav) pk::common::sav = pk::common::temp_sav;

    if (pk::common::sav.flags.has_sav) {

    } else {
        
    }
    for (int i = 0; i < 18 /* 60 * 0.3 */; i++) {
        bn::bg_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
        bn::sprite_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
        bn::core::update();
    }
};

void pk::scenes::SaveSel::main() {
        if (bn::keypad::a_pressed()) pk::SceneManager::set_load(bn::string_view("TITLE_SCREEN"), pk::SceneManager::transitions::TRANSITION_FADE, 0.3);
        if (bn::keypad::up_held()) pk::common::bgpos.set_y(pk::common::bgpos.y() + 1);
        if (bn::keypad::down_held()) pk::common::bgpos.set_y(pk::common::bgpos.y() - 1);
        if (bn::keypad::right_held()) pk::common::bgpos.set_x(pk::common::bgpos.x() - 1);
        if (bn::keypad::left_held()) pk::common::bgpos.set_x(pk::common::bgpos.x() + 1);
        bg0.set_position(pk::common::bgpos);

    // pk::SceneManager::cur_bg.value().set_position(8, 48);
    // bn::log(bn::to_string<16>("Title Screen"));
    // for (int i = 0; i < (60 * bn::fixed(0.3)); i++) {
    //     bn::bg_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
    //     bn::sprite_palettes::set_fade_intensity(1 - bn::fixed(i) / (bn::fixed(0.3) * 60));
    //     bn::core::update();
    // }
    // while(true) {
    //     if (bn::keypad::a_pressed()) {
    //         pk::SceneManager::set_load(bn::to_string<18>("SAVE_SEL"), pk::SceneManager::transitions::TRANSITION_FADE, 0.3);
    //         return;
    //     }
    //     bn::core::update();
    // }
}