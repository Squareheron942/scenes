#ifndef NOT_FOUND_SCENE_H
#define NOT_FOUND_SCENE_H

#include "pk_menu_scene.h"

namespace pk
{

namespace scenes
{

class NotFoundScene : public pk::scene_types::MenuScene {
    public:
        NotFoundScene();
        void main();
};

} // namespace scenes


} // namespace pk


#endif