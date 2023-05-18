#ifndef PK_TXTBOX_H
#define PK_TXTBOX_H

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_bg_palette_item.h"


#include "pk_common.h"
#include "pk_scenemanager.h"

#include "bn_bg_palette_items_txtpal1.h"
#include "bn_bg_palette_items_txtpal2.h"
#include "bn_bg_palette_items_txtpal3.h"
#include "bn_bg_palette_items_txtpal4.h"
#include "bn_bg_palette_items_txtpal5.h"
#include "bn_bg_palette_items_txtpal6.h"
#include "bn_bg_palette_items_txtpal7.h"
#include "bn_bg_palette_items_txtpal8.h"
#include "bn_bg_palette_items_txtpal9.h"
#include "bn_bg_palette_items_txtpal10.h"
#include "bn_bg_palette_items_txtpal11.h"
#include "bn_bg_palette_items_txtpal12.h"
#include "bn_bg_palette_items_txtpal13.h"
#include "bn_bg_palette_items_txtpal14.h"
#include "bn_bg_palette_items_txtpal14.h"
#include "bn_bg_palette_items_txtpal15.h"
#include "bn_bg_palette_items_txtpal16.h"
#include "bn_bg_palette_items_txtpal17.h"
#include "bn_bg_palette_items_txtpal18.h"
#include "bn_bg_palette_items_txtpal19.h"
#include "bn_bg_palette_items_txtpal20.h"

#include "bn_regular_bg_tiles_items_txt1.h"
#include "bn_regular_bg_tiles_items_txt2.h"
#include "bn_regular_bg_tiles_items_txt3.h"
#include "bn_regular_bg_tiles_items_txt4.h"
#include "bn_regular_bg_tiles_items_txt5.h"
#include "bn_regular_bg_tiles_items_txt6.h"
#include "bn_regular_bg_tiles_items_txt7.h"
#include "bn_regular_bg_tiles_items_txt8.h"
#include "bn_regular_bg_tiles_items_txt9.h"
#include "bn_regular_bg_tiles_items_txt10.h"
#include "bn_regular_bg_tiles_items_txt11.h"
#include "bn_regular_bg_tiles_items_txt12.h"
#include "bn_regular_bg_tiles_items_txt13.h"
#include "bn_regular_bg_tiles_items_txt14.h"
#include "bn_regular_bg_tiles_items_txt15.h"
#include "bn_regular_bg_tiles_items_txt16.h"
#include "bn_regular_bg_tiles_items_txt17.h"
#include "bn_regular_bg_tiles_items_txt18.h"
#include "bn_regular_bg_tiles_items_txt19.h"
#include "bn_regular_bg_tiles_items_txt20.h"

namespace pk
{

namespace ui
{

const bn::bg_palette_item txtboxpalettes[] = {
    bn::bg_palette_items::txtpal1,
    bn::bg_palette_items::txtpal2,
    bn::bg_palette_items::txtpal3,
    bn::bg_palette_items::txtpal4,
    bn::bg_palette_items::txtpal5,
    bn::bg_palette_items::txtpal6,
    bn::bg_palette_items::txtpal7,
    bn::bg_palette_items::txtpal8,
    bn::bg_palette_items::txtpal9,
    bn::bg_palette_items::txtpal10,
    bn::bg_palette_items::txtpal11,
    bn::bg_palette_items::txtpal12,
    bn::bg_palette_items::txtpal13,
    bn::bg_palette_items::txtpal14,
    bn::bg_palette_items::txtpal15,
    bn::bg_palette_items::txtpal16,
    bn::bg_palette_items::txtpal17,
    bn::bg_palette_items::txtpal18,
    bn::bg_palette_items::txtpal19,
    bn::bg_palette_items::txtpal20
};

const bn::regular_bg_tiles_item txtboxtiles[] = {
    bn::regular_bg_tiles_items::txt1,
    bn::regular_bg_tiles_items::txt2,
    bn::regular_bg_tiles_items::txt3,
    bn::regular_bg_tiles_items::txt4,
    bn::regular_bg_tiles_items::txt5,
    bn::regular_bg_tiles_items::txt6,
    bn::regular_bg_tiles_items::txt7,
    bn::regular_bg_tiles_items::txt8,
    bn::regular_bg_tiles_items::txt9,
    bn::regular_bg_tiles_items::txt10,
    bn::regular_bg_tiles_items::txt11,
    bn::regular_bg_tiles_items::txt12,
    bn::regular_bg_tiles_items::txt13,
    bn::regular_bg_tiles_items::txt14,
    bn::regular_bg_tiles_items::txt15,
    bn::regular_bg_tiles_items::txt16,
    bn::regular_bg_tiles_items::txt17,
    bn::regular_bg_tiles_items::txt18,
    bn::regular_bg_tiles_items::txt19,
    bn::regular_bg_tiles_items::txt20,
};

class TextBox {
    int width, height, x, y;
    bn::regular_bg_map_ptr ui_map;
    TextBox(int width, int height, int x, int y) : width(width), height(height), x(x), y(y) {
        ui_map = pk::SceneManager::ui_layer.create_bg().map();
        ui_map.set_tiles(txtboxtiles[pk::common::sav.settings.frame_type]);
    }
};

} // namespace ui

} // namespace pk


#endif