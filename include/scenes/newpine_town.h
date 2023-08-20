#ifndef PK_TITLE_SCENE_H
#define PK_TITLE_SCENE_H

#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_tiles_ptr.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "pk_scene.h"


namespace pk {
    namespace scenes {
        class TitleScene : public pk::Scene {
            public:
            TitleScene();
            ~TitleScene() {}

            void main() override;

            bn::regular_bg_map_item map;
            bn::regular_bg_tiles_ptr tiles;
            bn::bg_palette_ptr palette;
            bn::regular_bg_ptr bg;
        };
    }
}

#endif