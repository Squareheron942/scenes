#ifndef PK_SCENE_MANAGER_H
#define PK_SCENE_MANAGER_H

#include "pk_title_scene.h"
#include "pk_scene.h"
#include "bn_string_view.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_unique_ptr.h"

namespace pk {

class SceneManager {
    public:
        static inline bn::unique_ptr<pk::Scene> cur_scn;
        static inline bn::optional<bn::regular_bg_ptr> cur_bg;
        static void load();
};

}

#endif

        // static void load(bn::string_view name) {
            
        // }

        // static void load(int index) {

        // }