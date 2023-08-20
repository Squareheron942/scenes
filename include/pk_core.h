#ifndef PK_CORE_H
#define PK_CORE_H

#include "bn_random.h"

namespace pk::core {
    void update(bn::random& rand);
    void update_gui();
}

#endif