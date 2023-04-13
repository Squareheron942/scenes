#ifndef BN_REGULAR_BG_TILES_ITEMS_TXT9_H
#define BN_REGULAR_BG_TILES_ITEMS_TXT9_H

#include "bn_regular_bg_tiles_item.h"

//{{BLOCK(txt9_bn_gfx)

//======================================================================
//
//	txt9_bn_gfx, 80x8@4, 
//	+ 10 tiles not compressed
//	Total size: 320 = 320
//
//	Time-stamp: 2023-04-13, 13:47:49
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TXT9_BN_GFX_H
#define GRIT_TXT9_BN_GFX_H

#define txt9_bn_gfxTilesLen 320
extern const bn::tile txt9_bn_gfxTiles[10];

#endif // GRIT_TXT9_BN_GFX_H

//}}BLOCK(txt9_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item txt9(
            span<const tile>(txt9_bn_gfxTiles, 10), bpp_mode::BPP_4, compression_type::NONE);
}

#endif

