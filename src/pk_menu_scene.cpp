#include "pk_scene.h"
#include "bn_string_view.h"
#include "bn_regular_bg_item.h"
#include "pk_menu_scene.h"

pk::scene_types::MenuScene::MenuScene(bn::string_view _name, const bn::regular_bg_item& _background) : pk::Scene(_name, 0, _background) {};