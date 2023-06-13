#ifndef BN_REGULAR_BG_TILES_ITEMS_GMAP_GENERAL_H
#define BN_REGULAR_BG_TILES_ITEMS_GMAP_GENERAL_H

#include "bn_regular_bg_tiles_item.h"

//{{BLOCK(gmap_general_bn_gfx)

//======================================================================
//
//	gmap_general_bn_gfx, 128x256@8, 
//	+ 512 tiles not compressed
//	Total size: 32768 = 32768
//
//	Time-stamp: 2023-06-11, 20:19:48
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GMAP_GENERAL_BN_GFX_H
#define GRIT_GMAP_GENERAL_BN_GFX_H

#define gmap_general_bn_gfxTilesLen 32768
extern const bn::tile gmap_general_bn_gfxTiles[1024];

#endif // GRIT_GMAP_GENERAL_BN_GFX_H

//}}BLOCK(gmap_general_bn_gfx)

namespace bn::regular_bg_tiles_items
{
    constexpr inline regular_bg_tiles_item gmap_general(
            span<const tile>(gmap_general_bn_gfxTiles, 1024), bpp_mode::BPP_8, compression_type::NONE);
}

#endif

