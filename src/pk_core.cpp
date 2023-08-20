#include "pk_core.h"
#include "pk_weather.h"
#include "pk_seasons.h"

#include "bn_random.h"
#include "bn_fixed_point.h"
#include "bn_format.h"
#include "bn_memory.h"
#include "bn_bgs.h"
#include "bn_sprites.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"
#include "bn_sprite_items_common_fixed_8x8_font.h"

#include "defines.h"

namespace pk::core
{
    namespace {
        unsigned char counter = 0;
    }
    bn::vector<bn::sprite_ptr, 128>* _texts = NULL;
    void update(bn::random& rand) {
        update_gui();
        pk::weather::update(rand);
        pk::seasons::update();
    };

    void update_gui() {
        if (DEBUG) {
            if (((counter += 1) %= 30) == 0) {    
                if (_texts == NULL) _texts = new bn::vector<bn::sprite_ptr, 128>();
                _texts->shrink(0);
                const bn::sprite_text_generator _textGen(bn::sprite_font(bn::sprite_items::common_fixed_8x8_font));
                const bn::fixed_point BG_SPR_POS(32, -70), CPU_POS(56, -60), IWRAM_POS(16, -50), EWRAM_POS(16, -40);
                _textGen.generate(
                    BG_SPR_POS,
                    bn::format<14>("BG/SPR {}/{}", bn::bgs::used_items_count(), bn::sprites::used_items_count()),
                    *_texts);
                _textGen.generate(
                    CPU_POS, 
                    bn::format<10>("CPU {}%", (bn::core::last_cpu_usage() * 100).round_integer()),
                    *_texts);
                const int usedIw = bn::memory::used_stack_iwram() + bn::memory::used_static_iwram();
                _textGen.generate(
                    IWRAM_POS,
                    bn::format<13>("IW {}% {}", (bn::fixed(usedIw) / IWRAM_BYTES * 100).round_integer(), usedIw),
                    *_texts);
                const int usedEw = EWRAM_BYTES - bn::memory::available_alloc_ewram();
                _textGen.generate(
                    EWRAM_POS,
                    bn::format<14>("EW {}% {}", (bn::fixed(usedEw) / EWRAM_BYTES * 100).round_integer(), usedEw),
                    *_texts);
            }
        }
    }
}