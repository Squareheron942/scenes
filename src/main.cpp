#include "bn_core.h"

#include "pk_title_scene.h"
#include "pk_scenemanager.h"
#include "pk_common.h"

int main()
{
    bn::core::init();

    pk::SceneManager::load(pk::common::scn_to_load);

    while(true)
    {
        if (pk::common::load_scn) pk::SceneManager::load(pk::common::scn_to_load);
        bn::core::update();
    }
}