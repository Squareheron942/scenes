#include "pk_world_scene.h"
#include "pk_scene.h"

#include "bn_string_view.h"
#include "bn_point.h"
#include "bn_regular_bg_item.h"
#include "bn_camera_actions.h"

pk::scene_types::WorldScene::WorldScene(bn::string_view _name, bn::point position, bn::regular_bg_item& bg0, bn::regular_bg_item& bg1, bn::regular_bg_item& bg2, bn::regular_bg_item& bg3
) : pk::Scene(_name, 0, bg0), bg0(bg0), bg1(bg1), bg2(bg2), bg3(bg3), cam(bn::camera_ptr::create(position)) {};