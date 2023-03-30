#ifndef PK_TITLE_SCENE2_H
#define PK_TITLE_SCENE2_H

#include "pk_menu_scene.h"

namespace pk {
    namespace scenes {
        class SaveSel : public pk::scene_types::MenuScene {
            public:
            SaveSel();
            void main();
        };
    }
}

#endif