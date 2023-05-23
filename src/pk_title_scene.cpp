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

pk::scenes::TitleScene::TitleScene() : pk::scene_types::MenuScene(bn::string_view("TITLE_SCREEN"), bn::regular_bg_items::titlebg) {};

void pk::scenes::TitleScene::main() {
    pk::SceneManager::cur_bg.value().set_position(8, 48);
    bn::log(bn::to_string<16>("Title Screen"));
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