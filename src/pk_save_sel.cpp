#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_background.h"
#include "pk_save_sel.h"
#include "pk_menu_scene.h"
#include "bn_log.h"
#include "bn_string.h"
#include "pk_scenemanager.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "pk_common.h"
#include "bn_sram.h"

pk::scenes::SaveSel::SaveSel() : pk::scene_types::MenuScene(bn::string_view("titlescreen"), bn::regular_bg_items::background) {};

void pk::scenes::SaveSel::main() {
    bn::sram::read(pk::common::perm_sav);

    if (pk::common::perm_sav.has_sav) {

    } else {
        
    }
    while(true) {
        
        bn::core::update();
    }
}