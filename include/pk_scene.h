#ifndef PK_SCENE_H
#define PK_SCENE_H

#include "bn_string_view.h"
#include "bn_regular_bg_item.h"
#include "bn_optional.h"
#include "bn_log.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_ptr.h"
#include "bn_size.h"
#include "bn_string.h"
#include "bn_array.h"

namespace pk {

class Scene {
    public:
    const bn::string_view name;
    bn::array<bn::regular_bg_ptr, 4> bg;
    virtual ~Scene() {
        bn::log(bn::to_string<128>("Scene \"") + name + bn::to_string<128>("\" unloaded."));
    };
    virtual void update() = 0;
    protected:
    Scene(bn::string_view _name, bn::array<bn::regular_bg_ptr, 4> _bg) : name(_name), bg(_bg) {
        bn::log(bn::to_string<128>("Scene \"") + name + bn::to_string<128>("\" loaded."));
    };
};

}

#endif