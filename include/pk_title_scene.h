#ifndef PK_TITLE_SCENE_H
#define PK_TITLE_SCENE_H

#include "pk_menu_scene.h"

namespace pk {
    namespace scenes {
        class TitleScene : public pk::scene_types::MenuScene {
            public:
            TitleScene();
            void main();
        };
    }
}

#endif