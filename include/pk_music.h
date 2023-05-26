#ifndef PK_MUSIC_H
#define PK_MUSIC_H

#include "bn_music.h"
#include "bn_music_items.h"
#include "bn_music_item.h"
#include "bn_unique_ptr.h"
#include "bn_fixed.h"
#include "bn_core.h"

namespace pk::music {
    bn::unique_ptr<bn::music_item> current_music;
    void set_music(bn::music_item& music, uint8_t transition, bn::fixed time) {
        // fade out old music
        for (int i = 0; i < (60 * time); i++) {
            bn::music::set_volume(1 - (i / (60 * time * 2))); // fade music from 0.5 to 0
            bn::core::update();
        }
        bn::music::set_volume(0);
        bn::core::update();
        current_music.reset(&music);
        // fade in new music
        for (int i = 0; i < (60 * time); i++) {
            bn::music::set_volume(i / (60 * time * 2));
            bn::core::update();
        }
    };

    void set_music(bn::music_item& music) {
        current_music.reset(&music);
        current_music->play(bn::fixed(0.5));
    }
    //TODO Add fade out, fade in functions for when switching scenes
}

#endif