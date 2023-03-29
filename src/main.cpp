#include "bn_core.h"
#include "bn_math.h"
#include "bn_fixed.h"
#include "bn_sram.h"
#include "bn_string.h"
#include "bn_random.h"
#include "bn_log.h"
#include "bn_list.h"

#include "bn_keypad.h"

#include "bn_link.h"

#include "bn_display.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_sprites.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_item.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_sprite_palette_item.h"
#include "bn_display.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_items_snek.h"
#include "bn_sprite_items_apple.h"

#include "bn_bg_palettes.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_ptr.h"

#include "bn_regular_bg_items_background.h"

#include "pk_title_scene.h"
#include "pk_scenemanager.h"

using namespace bn;

int main()
{
    core::init();

    // pk::scenes::TitleScene test("image", &(bn::regular_bg_items::background));

    pk::SceneManager::load();

    while(true)
    {
        core::update();
    }
}