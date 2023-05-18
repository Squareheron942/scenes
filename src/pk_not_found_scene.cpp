#include "pk_not_found_scene.h"
#include "pk_common.h"

#include "bn_regular_bg_items_titlebg.h"
#include "bn_string_view.h"
#include "bn_core.h"
#include "bn_sprite_text_generator.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_string.h"
#include "bn_bg_palettes.h"
#include "bn_color.h"

#include "common_variable_8x16_sprite_font.h"

pk::scenes::NotFoundScene::NotFoundScene() : pk::scene_types::MenuScene(bn::string_view("NOT_FOUND"), bn::regular_bg_items::titlebg) {has_bg = false;};

void pk::scenes::NotFoundScene::main() {
    bn::sprite_text_generator text_gen(::common::variable_8x16_sprite_font);
    text_gen.set_center_alignment();
    bn::bg_palettes::set_transparent_color(bn::color(31, 31, 31));
    while(true) {
        bn::vector<bn::sprite_ptr, 16> text_sprites;
        text_gen.generate(0, 0, bn::string_view("Scene \"" + bn::to_string<32>(pk::common::scn_to_load) + "\" not found"), text_sprites);
        bn::core::update();
    }
};