#ifndef PK_COMMON_H
#define PK_COMMON_H

#include "bn_string_view.h"
#include "bn_point.h"

namespace pk
{

struct sav_data {
    bool gender;
    bn::string_view name;
    bn::string_view location;
    bn::point position;
    struct {
        uint8_t txt_spd;
        bool btl_scn;
        bool set_btl;
        bool audio_stereo;
        uint8_t btn_mode;
        uint8_t frame_type;
    } settings;
    struct {
        bool has_sav;
        bool isOnTitle;
        bool main_sav;
    } flags;
};

class common

{

public:
static inline bn::string_view scn_to_load = bn::string_view("TITLE_SCREEN");
static inline bool load_scn = true;
static inline uint16_t num_scn = 2;
static inline pk::sav_data sav;
static inline pk::sav_data temp_sav = { // basic save template, default settings
    .gender = false,
    .name = bn::string_view(""),
    .location = bn::string_view(""),
    .position = bn::point(0, 0),
    .settings = {
        .txt_spd = 1, // 0-2, slow, med, fast
        .btl_scn = true, // whether or not to have attack animations
        .set_btl = false, // whether set battle mode or not
        .audio_stereo = false, // if audio is stereo
        .btn_mode = 0, // 0: normal, 1: LR, 2: L=A
        .frame_type = 0 // ui frame type
    },
    .flags = {
        .has_sav = false,
        .isOnTitle = true,
        .main_sav = false
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