#ifndef BN_REGULAR_BG_TILES_ITEMS_TXT8_H
#define BN_REGULAR_BG_TILES_ITEMS_TXT8_H

#include "bn_regular_bg_tiles_item.h"

//{{BLOCK(txt8_bn_gfx)

//======================================================================
//
//	txt8_bn_gfx, 80x8@4, 
//	+ 10 tiles not compressed
//	Total size: 320 = 320
//
//	Time-stamp: 2023-04-13, 13:47:49
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TXT8_BN_GFX_H
#define GRIT_TXT8_BN_GFX_H

#define txt8_bn_gfxTilesLen 320
extern const bn::tile txt8_bn_gfxTiles[10];

#endif // GRIT_TXT8_BN_GFX_H

//}}BLOCK(txt8_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item txt8(
            span<const tile>(txt8_bn_gfxTiles, 10), bpp_mode::BPP_4, compression_type::NONE);
}

#endif

