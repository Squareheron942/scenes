#ifndef BN_BG_PALETTE_ITEMS_GPAL_GENERAL_H
#define BN_BG_PALETTE_ITEMS_GPAL_GENERAL_H

#include "bn_bg_palette_item.h"

//{{BLOCK(gpal_general_bn_gfx)

//======================================================================
//
//	gpal_general_bn_gfx, 128x256@8, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-06-11, 20:19:48
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GPAL_GENERAL_BN_GFX_H
#define GRIT_GPAL_GENERAL_BN_GFX_H

#define gpal_general_bn_gfxPalLen 32
extern const bn::color gpal_general_bn_gfxPal[16];

#endif // GRIT_GPAL_GENERAL_BN_GFX_H

//}}BLOCK(gpal_general_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item gpal_general(span<const color>(gpal_general_bn_gfxPal, 16), 
            bpp_mode::BPP_8, compression_type::NONE);
}

#endif

