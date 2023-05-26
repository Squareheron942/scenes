#ifndef BN_BG_PALETTE_ITEMS_TXTPAL17_H
#define BN_BG_PALETTE_ITEMS_TXTPAL17_H

#include "bn_bg_palette_item.h"

//{{BLOCK(txtpal17_bn_gfx)

//======================================================================
//
//	txtpal17_bn_gfx, 24x24@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-05-24, 20:06:20
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TXTPAL17_BN_GFX_H
#define GRIT_TXTPAL17_BN_GFX_H

#define txtpal17_bn_gfxPalLen 32
extern const bn::color txtpal17_bn_gfxPal[16];

#endif // GRIT_TXTPAL17_BN_GFX_H

//}}BLOCK(txtpal17_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item txtpal17(span<const color>(txtpal17_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

