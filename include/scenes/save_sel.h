#ifndef PK_TITLE_SCENE2_H
#define PK_TITLE_SCENE2_H

#include "pk_scene.h"
#include "bn_regular_bg_ptr.h"

namespace pk {
    namespace scenes {
        class SaveSel : public pk::Scene {
            public:
            SaveSel();
            void main() override;
            bn::regular_bg_ptr bg0;
        };
    }
}

#endif