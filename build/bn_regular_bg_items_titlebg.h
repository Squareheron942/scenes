#ifndef BN_REGULAR_BG_ITEMS_TITLEBG_H
#define BN_REGULAR_BG_ITEMS_TITLEBG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(titlebg_bn_gfx)

//======================================================================
//
//	titlebg_bn_gfx, 256x256@4, 
//	+ palette 16 entries, not compressed
//	+ 14 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 32 + 448 + 2048 = 2528
//
//	Time-stamp: 2023-03-31, 11:31:36
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLEBG_BN_GFX_H
#define GRIT_TITLEBG_BN_GFX_H

#define titlebg_bn_gfxTilesLen 448
extern const bn::tile titlebg_bn_gfxTiles[14];

#define titlebg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell titlebg_bn_gfxMap[1024];

#define titlebg_bn_gfxPalLen 32
extern const bn::color titlebg_bn_gfxPal[16];

#endif // GRIT_TITLEBG_BN_GFX_H

//}}BLOCK(titlebg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item titlebg(
            regular_bg_tiles_item(span<const tile>(titlebg_bn_gfxTiles, 14), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(titlebg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(titlebg_bn_gfxMap[0], size(32, 32), compression_type::NONE));
}

#endif

