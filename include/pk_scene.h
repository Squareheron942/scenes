#ifndef PK_SCENE_H
#define PK_SCENE_H

#include "bn_string_view.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_log.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_size.h"
#include "bn_string.h"

namespace pk {

class Scene {
    public:
    bn::string_view name;
    int type;
    const bn::regular_bg_item background;
    bn::regular_bg_map_cell *cells;
    bn::regular_bg_map_item ui_bg; // covers the entire background
    bool has_bg = true;
    virtual void main() {};
    virtual ~Scene() { 
        delete[] cells; 
        bn::log(bn::to_string<128>("Scene \"") + name + bn::to_string<128>("\" not found."));
    };

    Scene(bn::string_view _name, int _type, const bn::regular_bg_item& _background) : name(_name), type(_type), background(_background), cells(new bn::regular_bg_map_cell[1024]), ui_bg(cells[0], bn::size(32, 32)) {};


};

}

#endif