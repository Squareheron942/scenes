#ifndef PK_TITLE_SCENE2_H
#define PK_TITLE_SCENE2_H

#include "pk_scene.h"
#include "bn_regular_bg_ptr.h"

namespace pk {
    namespace scenes {
        class SaveSel : public pk::Scene {
            public:
            SaveSel();
            ~SaveSel();
            void update() override;
        };
    }
}

#endif