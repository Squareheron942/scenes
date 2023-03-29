#ifndef PK_SCENE_H
#define PK_SCENE_H

#include "bn_string_view.h"
#include "bn_regular_bg_item.h"
#include "bn_sprite_items_apple.h"
#include "bn_optional.h"
#include "bn_log.h"

namespace pk {

class Scene {
    public:
    bn::string_view name;
    const bn::regular_bg_item *background;
    int type = 0;
    virtual void main() {};

    Scene(bn::string_view _name, int _type, const bn::regular_bg_item * _background) : name(_name), type(_type), background(_background) {};


};

}

#endif