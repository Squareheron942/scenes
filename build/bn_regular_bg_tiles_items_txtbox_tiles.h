#ifndef BN_REGULAR_BG_TILES_ITEMS_TXTBOX_TILES_H
#define BN_REGULAR_BG_TILES_ITEMS_TXTBOX_TILES_H

#include "bn_regular_bg_tiles_item.h"

//{{BLOCK(txtbox_tiles_bn_gfx)

//======================================================================
//
//	txtbox_tiles_bn_gfx, 80x24@4, 
//	+ 30 tiles not compressed
//	Total size: 960 = 960
//
//	Time-stamp: 2023-03-31, 14:05:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TXTBOX_TILES_BN_GFX_H
#define GRIT_TXTBOX_TILES_BN_GFX_H

#define txtbox_tiles_bn_gfxTilesLen 960
extern const bn::tile txtbox_tiles_bn_gfxTiles[30];

#endif // GRIT_TXTBOX_TILES_BN_GFX_H

//}}BLOCK(txtbox_tiles_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item txtbox_tiles(
            span<const tile>(txtbox_tiles_bn_gfxTiles, 30), bpp_mode::BPP_4, compression_type::NONE);
}

#endif

