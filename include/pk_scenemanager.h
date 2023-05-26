#ifndef PK_SCENE_MANAGER_H
#define PK_SCENE_MANAGER_H

#include "pk_title_scene.h"
#include "pk_scene.h"

#include "bn_string_view.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"
#include "bn_unique_ptr.h"
#include "bn_array.h"
#include "bn_regular_bg_map_item.h"
#include "bn_fixed.h"
#include "bn_point.h"

namespace pk {
// Groups together all of the scene managing systems
class SceneManager {
    public:
        struct transitions {
            const static uint8_t NONE = 0;
            const static uint8_t TRANSITION_FADE = 1;
            const static uint8_t TRANSITION_HBLANK = 2;
        };
        static inline bn::unique_ptr<pk::Scene> cur_scn;
        static void load(int index); // Loads given scene based on name
        static void load(bn::string_view name); // Loads given scene based on name
        // static void load(bn::string_view name, uint8_t transition, bn::fixed time); // Loads given scene with a transition out and in
        static void set_load(bn::string_view name); // Loads given scene based on name
        static void set_load(bn::string_view name, uint8_t transition, bn::fixed time); // Loads given scene with a transition out and in
};

}

#endif