#include "bn_core.h"

#include "pk_scenemanager.h"
#include "pk_taskmanager.h"
#include "pk_core.h"


#include "newpine_town.h"
#include "bn_random.h"

int main()
{
    bn::core::init();
    bn::random rand;

    pk::SceneManager::load<pk::scenes::NEWPINE_TOWN>();

    while(true)
    {   
        pk::TaskManager::update();
        pk::SceneManager::cur_scn->update();

        pk::core::update_gui();
        bn::core::update();
    }
}