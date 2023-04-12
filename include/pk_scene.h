#ifndef PK_SCENE_H
#define PK_SCENE_H

#include "bn_string_view.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_log.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_size.h"

#include "pk_txtbox.h"

namespace pk {

class Scene {
    public:
    bn::string_view name;
    bn::regular_bg_map_cell cells[600];
    bn::regular_bg_map_item ui_bg; // covers the entire background
    const bn::regular_bg_item background;
    int type = 0;
    virtual void main() {};

    Scene(bn::string_view _name, int _type, const bn::regular_bg_item& _background) : name(_name), type(_type), background(_background), ui_bg(cells[0], bn::size(32, 32)) {};


};

}

#endif