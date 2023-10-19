#ifndef PK_SW_KBD_H
#define PK_SW_KBD_H

#include "bn_string.h"
#include "bn_string_view.h"
#include "pk_scenemanager.h"

namespace pk {
    enum class swkbdtype : unsigned char {
        SWKBD_TYPE_NORMAL,
        SWKBD_TYPE_QWERTY,
        SWKBD_TYPE_NUMPAD
    };
    enum class swkbdvalidinput : unsigned char {
        SWKBD_ANYTHING,
        SWKBD_NOTEMPTY,
        SWKBD_NOTEMPTY_NOTBLANK,
        SWKBD_NOTBLANK,
        SWKBD_FIXEDLEN
    };


    template<unsigned char maxlen = 0>
    bn::string<maxlen + 1> swkbd(bn::string_view prompt = "Enter text", swkbdtype type = swkbdtype::SWKBD_TYPE_NORMAL) {
        return bn::string<maxlen + 1>("lol");
    }
}

#endif