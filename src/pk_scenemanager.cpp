#include "pk_title_scene.h"
#include "pk_scene.h"
#include "bn_string_view.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_unique_ptr.h"
#include "bn_string.h"
#include "bn_log.h"
#include "pk_scenemanager.h"

// namespace pk {

// class SceneManager {
//     public:
//         static inline bn::unique_ptr<pk::Scene> cur_scn;
//         static inline bn::optional<bn::regular_bg_ptr> cur_bg;
//         static inline void load() {
//             pk::SceneManager::cur_scn.reset(new pk::scenes::TitleScene());
//             cur_bg = cur_scn->background->create_bg(0, 0);

//             bn::log(bn::to_string<16>("text"));
//         }
// };

// }

void pk::SceneManager::load() {
    pk::SceneManager::cur_scn.reset(new pk::scenes::TitleScene());
    cur_bg = cur_scn->background->create_bg(0, 0);
    cur_scn->main();
}
