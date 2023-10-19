#ifndef PK_TITLE_SCENE_H
#define PK_TITLE_SCENE_H

#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "pk_scene.h"
#include "pk_task.h"
#include "bn_fixed.h"
#include "bn_array.h" 
#include "bn_sprite_ptr.h"

namespace pk {
    namespace scenes {
        class NEWPINE_TOWN : public pk::Scene {
            public:
            NEWPINE_TOWN();
            ~NEWPINE_TOWN();

            void update() override;

            bn::array<bn::regular_bg_map_item, 4> map;
            bn::regular_bg_tiles_ptr tiles;
            bn::bg_palette_ptr palette;
            static inline bn::fixed playerX = 0, playerY = 0;
            pk::Task movePlayerRight, movePlayerUp, movePlayerLeft, movePlayerDown;
        };
    }
}

#endif