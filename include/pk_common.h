#ifndef PK_COMMON_H
#define PK_COMMON_H

#include "bn_string_view.h"

namespace pk
{

struct setting_template {
    uint8_t txt_spd;
    bool btl_scn;
    bool set_btl;
    bool audio_stereo;
    uint8_t btn_mode;
    uint8_t frame_type;
};

struct sav_data {
    bool has_sav;
    bool gender;
    bn::string_view name;
    pk::setting_template settings;
};

class common

{

public:
static inline bn::string_view scn_to_load = bn::string_view("TITLE_SCREEN");
static inline bool load_scn = true;
static inline uint16_t num_scn = 2;
static inline pk::sav_data perm_sav;
static inline pk::sav_data temp_sav = {
    .has_sav = false,
    .gender = false,
    .name = bn::string_view(""),
    .settings = {
        .txt_spd = 1,
        .btl_scn = true,
        .set_btl = false,
        .audio_stereo = false,
        .btn_mode = 0,
        .frame_type = 0
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