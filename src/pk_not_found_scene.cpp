#include "pk_not_found_scene.h"
#include "bn_regular_bg_items_titlebg.h"
#include "bn_string_view.h"
#include "bn_core.h"

pk::scenes::NotFoundScene::NotFoundScene() : pk::scene_types::MenuScene(bn::string_view("NOT_FOUND"), &(bn::regular_bg_items::titlebg)) {};

void pk::scenes::NotFoundScene::main() {
    while(true) bn::core::update();
};