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
#include "pk_transitions.h"

#include "newpine_town.h"

pk::scenes::SaveSel::SaveSel() : pk::Scene("Save Select", bn::array<bn::regular_bg_ptr, 4>{bn::regular_bg_items::background.create_bg(pk::common::bgpos),bn::regular_bg_items::background.create_bg(pk::common::bgpos),bn::regular_bg_items::background.create_bg(pk::common::bgpos),bn::regular_bg_items::background.create_bg(pk::common::bgpos)}) {

    bn::sram::read(pk::common::sav);
    if (!pk::common::sav.flags.has_sav) pk::common::sav = pk::common::sav_templ;

    if (pk::common::sav.flags.has_sav) {

    } else {
        
    }
    pk::transitions::TRANSITION_FADE(18, true);
};

pk::scenes::SaveSel::~SaveSel() {
    pk::transitions::TRANSITION_FADE(18, false);
}

void pk::scenes::SaveSel::update() {
        if (bn::keypad::a_pressed()) pk::SceneManager::load<pk::scenes::NEWPINE_TOWN>();
        if (bn::keypad::up_held()) pk::common::bgpos.set_y(pk::common::bgpos.y() + 1);
        if (bn::keypad::down_held()) pk::common::bgpos.set_y(pk::common::bgpos.y() - 1);
        if (bn::keypad::right_held()) pk::common::bgpos.set_x(pk::common::bgpos.x() - 1);
        if (bn::keypad::left_held()) pk::common::bgpos.set_x(pk::common::bgpos.x() + 1);
        bg[0].set_position(pk::common::bgpos);

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