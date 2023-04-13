#ifndef BN_BG_PALETTE_ITEMS_TXTPAL6_H
#define BN_BG_PALETTE_ITEMS_TXTPAL6_H

#include "bn_bg_palette_item.h"

//{{BLOCK(txtpal6_bn_gfx)

//======================================================================
//
//	txtpal6_bn_gfx, 24x24@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-04-13, 13:47:49
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TXTPAL6_BN_GFX_H
#define GRIT_TXTPAL6_BN_GFX_H

#define txtpal6_bn_gfxPalLen 32
extern const bn::color txtpal6_bn_gfxPal[16];

#endif // GRIT_TXTPAL6_BN_GFX_H

//}}BLOCK(txtpal6_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item txtpal6(span<const color>(txtpal6_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

