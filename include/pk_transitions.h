#ifndef PK_TRANSITIONS_H
#define PK_TRANSITIONS_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_palettes.h"

namespace pk {
    class transitions {
        public:
        /**
         * @brief Fade transition
         * @param time How many frames for the animation to take
         * @param direction Whether to fade in or out. `true`: Fade in `false`: Fade out
        */
        static void TRANSITION_FADE(int time, bool direction) {
            if (direction) 
            for (int i = 0; i <= time; i++) {
                bn::bg_palettes::set_fade_intensity(1 - bn::fixed(i) / (time));
                bn::sprite_palettes::set_fade_intensity(1 - bn::fixed(i) / (time));
                bn::core::update();
            }
            else
            for (int i = 0; i <= time; i++) {
                bn::bg_palettes::set_fade_intensity(bn::fixed(i) / (time));
                bn::sprite_palettes::set_fade_intensity(bn::fixed(i) / (time));
                bn::core::update();
            }
        }
    };
}

#endif