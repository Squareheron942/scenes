#include "bn_core.h"

#include "pk_scenemanager.h"
#include "pk_core.h"

int main()
{
    bn::core::init();

    while(true)
    {
        if (pk::SceneManager::load_scn) pk::SceneManager::load(pk::SceneManager::scn_to_load);
        
        pk::SceneManager::cur_scn->main();

        pk::core::update_gui();
        bn::core::update();
    }
}