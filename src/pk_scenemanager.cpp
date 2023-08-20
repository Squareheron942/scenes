// individual scenes
#include "pk_scenes_list.inc"

// utilities
#include "pk_scene.h"
#include "pk_scenemanager.h"
#include "pk_common.h"
#include "pk_core.h"

// butano stuff
#include "bn_string_view.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_string.h"
#include "bn_unordered_map.h"
#include "bn_core.h"
#include "bn_regular_bg_map_item.h"
#include "bn_blending.h"
#include "bn_blending_actions.h"
#include "bn_sprite_palettes.h"
#include "bn_bg_palettes.h"
#include "bn_color.h"
#include "bn_log.h"

// load based on scene id number
void pk::SceneManager::load(int index) {
    load_scn = false;
    switch (index) {
        case 0:
            pk::SceneManager::cur_scn.reset(new pk::scenes::TitleScene());
            break;
        case 1:
            pk::SceneManager::cur_scn.reset(new pk::scenes::SaveSel());
            break;
        default:
            BN_ERROR(bn::to_string<21 + sizeof(scn_to_load)>("Scene \"") + scn_to_load + bn::to_string<21 + sizeof(scn_to_load)>("\" not found."));
            break;
    }
    bn::core::update();
}

/**
 * @brief Loads given scene
 * 
 * @param name The name of the scene to load
 */
void pk::SceneManager::load(bn::string_view name) {
    
    pk::SceneManager::load(pk::common::indexOf<const bn::string_view>(pk::common::names, num_scn, name));
}

/**
 * @brief Tells the scene manager to load a new scene
 * 
 * @param name The name of the scene to load
 */
void pk::SceneManager::set_load(bn::string_view name) {
    scn_to_load.swap(name);
    load_scn = true;
}

/**
 * @brief Tells the scene manager to load a new scene
 * 
 * @param name The name of the scene to load
 * @param transition The transition to use
 * @param time The length of the transition (in seconds)
 */
void pk::SceneManager::set_load(bn::string_view name, pk::SceneManager::transitions transition, bn::fixed time) {

    set_load(name);

    switch (transition) {
        case pk::SceneManager::transitions::NONE:
            break;
        case pk::SceneManager::transitions::TRANSITION_FADE:
            bn::bg_palettes::set_fade_color(bn::color(0,0,0));
            bn::sprite_palettes::set_fade_color(bn::color(0, 0, 0));
            for (int i = 0; i <= (45 * time).integer(); i++) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(i) / (time * 60));
                bn::sprite_palettes::set_fade_intensity(bn::fixed(i) / (time * 60));
                bn::core::update();
            }
            for (int i = 0; i <= (15 * time).integer(); i++) {
                bn::bg_palettes::set_fade_intensity(1);
                bn::sprite_palettes::set_fade_intensity(1);
                bn::core::update();
            }
            break;
        case pk::SceneManager::transitions::TRANSITION_HBLANK:
            break;
        default:
            break;
    }
    for (int i = 0; i <= (60 * time).integer(); i++) bn::core::update();
}