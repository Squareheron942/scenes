// individual scenes
#include "pk_title_scene.h"
#include "pk_save_sel.h"

// utilities
#include "pk_scene.h"
#include "pk_scenemanager.h"
#include "pk_common.h"

// butano stuff
#include "bn_string_view.h"
#include "bn_optional.h"
#include "bn_regular_bg_ptr.h"
#include "bn_unique_ptr.h"
#include "bn_string.h"
#include "bn_log.h"
#include "bn_unordered_map.h"
#include "bn_core.h"
#include "bn_regular_bg_map_item.h"

void pk::SceneManager::load(int index) {
    pk::common::load_scn = false;
    switch (index) {
        case 0:
            pk::SceneManager::cur_scn.reset(new pk::scenes::TitleScene());
            break;
        case 1:
            pk::SceneManager::cur_scn.reset(new pk::scenes::SaveSel());
            break;
        default:
            break;
    }
    bn::core::update();

    ui_layer = cur_scn->ui_bg;
    cur_bg = cur_scn->background.create_bg(0, 0);
    cur_scn->main();
}

void pk::SceneManager::load(bn::string_view name) {
    pk::SceneManager::load(pk::common::indexOf<const bn::string_view>(pk::common::names, pk::common::num_scn, name));
}