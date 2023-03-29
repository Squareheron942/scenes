#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_background.h"
#include "pk_title_scene2.h"
#include "pk_menu_scene.h"
#include "bn_log.h"
#include "bn_string.h"
#include "pk_scenemanager.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "pk_common.h"

pk::scenes::TitleScene2::TitleScene2() : pk::scene_types::MenuScene(bn::string_view("titlescreen"), &(bn::regular_bg_items::background)) {};

void pk::scenes::TitleScene2::main() {
    bn::log(bn::to_string<16>("mainfunc"));
    while(true) {
        if (bn::keypad::a_pressed()) {
            pk::common::load_scn = true;
            pk::common::scn_to_load = 0;
            return;
        }
        bn::core::update();
    }
}