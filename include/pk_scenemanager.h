#ifndef PK_SCENE_MANAGER_H
#define PK_SCENE_MANAGER_H

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
#include "bn_unordered_map.h"
#include "bn_core.h"
#include "pk_core.h"

#include <type_traits>

namespace pk {
// Groups together all of the scene managing systems
class SceneManager {
    public:
        enum class transitions : unsigned char {
            NONE,
            TRANSITION_FADE,
            TRANSITION_HBLANK,
        };
        static inline bn::unique_ptr<pk::Scene> cur_scn;
        template <typename T = pk::Scene>
        requires std::is_base_of_v<pk::Scene, T>
        static void load() {
            pk::SceneManager::cur_scn.reset();
            pk::core::update();
            pk::SceneManager::cur_scn.reset(new T());
        }
};

}

#endif