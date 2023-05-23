#include "bn_core.h"

#include "pk_scenemanager.h"
#include "pk_title_scene.h"
#include "pk_common.h"
#include "bn_fixed.h"
#include "bn_log.h"
#include "bn_string.h"

int main()
{
    bn::core::init();

    // pk::common::load_scn = true;

    while(true)
    {
        if (pk::common::load_scn) {
            // pk::SceneManager::load(pk::common::scn_to_load, pk::common::scn_tr_out, pk::common::scn_t_out);
            pk::SceneManager::load(pk::common::scn_to_load);
            pk::SceneManager::cur_scn->main();
        }
        bn::core::update();
    }
}