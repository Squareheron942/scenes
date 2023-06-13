#ifndef PK_COMMON_H
#define PK_COMMON_H

#include "bn_string_view.h"
#include "bn_point.h"
#include "bn_random.h"
#include "bn_fixed.h"
#include <agbabi.h>

namespace pk
{

struct {
    uint8_t MENU = 0;
    uint8_t WORLD = 1;
} map_types;

struct sav_data {
    uint8_t check;
    bool gender;
    bn::string_view name;
    bn::string_view location;
    bn::point position;
    bn::random random;
    struct { // The settings for the game
        uint8_t txt_spd; // 0-2: Slow, Medium, Fast
        bool btl_scn; // Whether or not to use attack animations
        bool set_btl; // Whether using set battle mode or not
        bool audio_stereo; // Whether audio is stereo
        uint8_t btn_mode; // 0: normal, 1: LR, 2: L=A
        uint8_t frame_type; // UI frame type
    } settings;
    struct {
        bool has_sav;
        bool isOnTitle;
        bool main_sav;
        bool has_clk;
    } flags;
};

class common
{
    public:
        static inline uint8_t scn_type = 0;
        static inline uint8_t scn_tr_out = 0;
        static inline bn::fixed scn_t_out = 0;
        static inline bn::string_view scn_to_load = bn::string_view("TITLE_SCREEN");
        static inline bool load_scn = true;
        static inline uint16_t num_scn = 2;
        static inline pk::sav_data sav;
        static inline pk::sav_data temp_sav = { // Basic save template, has default settings
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
                .btn_mode = 0, // 0: normal, 1: LR, 2: L=A
                .frame_type = 0 // ui frame type
            },
            .flags = {
                .has_sav = false,
                .isOnTitle = true,
                .main_sav = false,
                .has_clk = true
            }
        };

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