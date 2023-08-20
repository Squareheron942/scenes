// individual scenes
#include "pk_title_scene.h"
#include "pk_save_sel.h"

// utilities
#include "pk_scene.h"
#include "pk_scenemanager.h"
#include "pk_common.h"
// #include "pk_core.h"

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
    pk::common::load_scn = false;
    switch (index) {
        case 0:
            pk::SceneManager::cur_scn.reset(new pk::scenes::TitleScene());
            break;
        case 1:
            pk::SceneManager::cur_scn.reset(new pk::scenes::SaveSel());
            break;
        default:
            // pk::SceneManager::cur_scn.reset(new pk::scenes::NotFoundScene());
            BN_ERROR(bn::to_string<128>("Scene \"") + pk::common::scn_to_load + bn::to_string<128>("\" not found."));
            break;
    }
    bn::core::update();

    // ui_layer = cur_scn->ui_bg;
    // if (cur_scn->has_bg) cur_bg = cur_scn->background.create_bg(0, 0);
}

/**
 * @brief Loads given scene
 * 
 * @param name The name of the scene to load
 */
void pk::SceneManager::load(bn::string_view name) {
    // pk::SceneManager::load(name, pk::common::scn_transition, 1);
    
    pk::SceneManager::load(pk::common::indexOf<const bn::string_view>(pk::common::names, pk::common::num_scn, name));
}



// /**
//  * @brief Loads given scene using a transition out
//  * 
//  * @param name Name of the scene to load
//  * @param transition Transition to use
//  * @param time Length of transition
//  */
// void pk::SceneManager::load(bn::string_view name, uint8_t transition, bn::fixed time) {
//     bn::log(bn::to_string<18>(transition));
    
//     // for (int i = 0; i <= (60 * time).integer(); i++) bn::core::update();
//     pk::SceneManager::load(pk::common::indexOf<const bn::string_view>(pk::common::names, pk::common::num_scn, name));
// }









/**
 * @brief Tells the scene manager to load a new scene
 * 
 * @param name The name of the scene to load
 */
void pk::SceneManager::set_load(bn::string_view name) {
    pk::common::scn_to_load.swap(name);
    pk::common::load_scn = true;
}

/**
 * @brief Tells the scene manager to load a new scene
 * 
 * @param name The name of the scene to load
 * @param transition The transition to use
 * @param time The length of the transition (in seconds)
 */
void pk::SceneManager::set_load(bn::string_view name, pk::SceneManager::transitions transition, bn::fixed time) {
    pk::common::scn_to_load.swap(name);
    pk::common::load_scn = true;
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