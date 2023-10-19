#ifndef PK_COMMON_H
#define PK_COMMON_H

#include "bn_string_view.h"
#include "bn_point.h"
#include "bn_fixed_point.h"
#include "bn_random.h"
#include "bn_fixed.h"
#include "bn_sprite_ptr.h"
#include "bn_optional.h"
// #include <agbabi.h>

namespace pk
{

struct sav_data {
    uint8_t check;
    bool gender;
    bn::string_view name;
    bn::string_view location;
    bn::point position;
    bn::random random;
    struct { // The settings for the game
        uint8_t txt_spd; // 0-2: Slow, Medium, Fast
        bool btl_scn : 1; // Whether or not to use attack animations
        bool set_btl : 1; // Whether using set battle mode or not
        bool audio_stereo : 1; // Whether audio is stereo
        struct {
            bn::fixed music;
            bn::fixed sfx;
        } volume;
        uint8_t btn_mode; // 0: normal, 1: LR, 2: L=A
        uint8_t frame_type; // UI frame type
    } settings;
    struct {
        bool has_sav : 1; // whether the save slot has been written to
        bool isOnTitle : 1;
        bool main_sav : 1; // whether this is the first or second save
        bool set_clk : 1; // whether or not clock has been set
    } flags;
};

class common
{
    public:
        static inline pk::sav_data sav, sav_templ = { // Basic save template, has default settings
            .check = 0,
            .gender = false,
            .name = bn::string_view(""),
            .location = bn::string_view(""),
            .position = bn::point(0, 0),
            .random = bn::random(),
            .settings = {
                .txt_spd = 1, // 0-2, slow, med, fast
                .btl_scn = true, // whether or not to have attack animations
                .set_btl = false, // whether set battle mode or not
                .audio_stereo = false, // whether audio is stereo
                .volume = {
                    .music = bn::fixed(0.5),
                    .sfx = bn::fixed(0.5)
                },
                .btn_mode = 0, // 0: normal, 1: LR, 2: L=A
                .frame_type = 0 // ui frame type
            },
            .flags = {
                .has_sav = false,
                .isOnTitle = true,
                .main_sav = false,
                .set_clk = true
            }
        };
        static inline bn::point bgpos;
        static inline bn::fixed_point playerpos;
        static inline bn::optional<bn::sprite_ptr> playersprite;
        static inline char playeranimstate = 0;

        constexpr static const bn::string_view names[] = {
            bn::string_view("TITLE_SCREEN"),
            bn::string_view("SAVE_SEL")
        };

        template <class Type>
        static int indexOf(Type arr[], uint16_t length, Type value) {
            for (uint16_t i = 0; i < length; i++) {
                if (arr[i] == value) return i;
            }
            return -1;
        }
};
}

#endif