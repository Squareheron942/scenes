#ifndef PK_WORLD_SCENE_H
#define PK_WORLD_SCENE_H

#include "pk_scene.h"

#include "bn_regular_bg_item.h"
#include "bn_string_view.h"
#include "bn_camera_actions.h"
#include "bn_point.h"
#include "bn_fixed.h"

namespace pk {
    namespace scene_types
    {
        class WorldScene : public pk::Scene {
            public:
                bn::regular_bg_item bg0; // World map layer
                bn::regular_bg_item bg1; // UI layer, only sometimes visible
                bn::regular_bg_item bg2; // Weather layer
                bn::regular_bg_item bg3; // Cloud layer
                bn::camera_ptr cam;
                static uint8_t w_probs; // Int array representing the percentage chance of weather happening
                static uint8_t weather;
                static bn::fixed cd_i; // Cloud intensity [0, 1]
                static bn::fixed wd_i; // Wind intensity [0, 1]
                WorldScene(
                    bn::string_view _name,
                    bn::point position,
                    bn::regular_bg_item& bg0,
                    bn::regular_bg_item& bg1,
                    bn::regular_bg_item& bg2,
                    bn::regular_bg_item& bg3
                );
        };
    }
}

#endif