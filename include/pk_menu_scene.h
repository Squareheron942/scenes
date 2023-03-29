#ifndef PK_SCENE_TYPE_MENU_H
#define PK_SCENE_TYPE_MENU_H

#include "pk_scene.h"
#include "bn_string_view.h"
#include "bn_regular_bg_item.h"

namespace pk {
    namespace scene_types {
        class MenuScene : public pk::Scene {
            public:
            MenuScene(bn::string_view _name, const bn::regular_bg_item * _background);
        };
    }
}

#endif