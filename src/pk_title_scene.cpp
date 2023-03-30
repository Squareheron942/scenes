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

pk::scenes::TitleScene::TitleScene() : pk::scene_types::MenuScene(bn::string_view("titlescreen"), &(bn::regular_bg_items::titlebg)) {};

void pk::scenes::TitleScene::main() {
    pk::SceneManager::cur_bg.value().set_position(8, 48);
    bn::log(bn::to_string<16>("scene1"));
    while(true) {
        if (bn::keypad::a_pressed()) {
            pk::common::load_scn = true;
            pk::common::scn_to_load = bn::string_view("SAVE_SEL");
            return;
        }
        bn::core::update();
    }
}