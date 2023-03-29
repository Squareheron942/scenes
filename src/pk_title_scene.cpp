#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_regular_bg_items_background.h"
#include "pk_title_scene.h"
#include "pk_menu_scene.h"
#include "bn_log.h"
#include "bn_string.h"

pk::scenes::TitleScene::TitleScene() : pk::scene_types::MenuScene(bn::string_view("titlescreen"), &(bn::regular_bg_items::background)) {};

void pk::scenes::TitleScene::main() {
    bn::log(bn::to_string<16>("mainfunc"));
}