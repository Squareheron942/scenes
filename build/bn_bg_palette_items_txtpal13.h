#ifndef BN_BG_PALETTE_ITEMS_TXTPAL13_H
#define BN_BG_PALETTE_ITEMS_TXTPAL13_H

#include "bn_bg_palette_item.h"

//{{BLOCK(txtpal13_bn_gfx)

//======================================================================
//
//	txtpal13_bn_gfx, 24x24@4, 
//	+ palette 16 entries, not compressed
//	Total size: 32 = 32
//
//	Time-stamp: 2023-06-11, 20:19:48
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TXTPAL13_BN_GFX_H
#define GRIT_TXTPAL13_BN_GFX_H

#define txtpal13_bn_gfxPalLen 32
extern const bn::color txtpal13_bn_gfxPal[16];

#endif // GRIT_TXTPAL13_BN_GFX_H

//}}BLOCK(txtpal13_bn_gfx)

namespace bn::bg_palette_items
{
    constexpr inline bg_palette_item txtpal13(span<const color>(txtpal13_bn_gfxPal, 16), 
            bpp_mode::BPP_4, compression_type::NONE);
}

#endif

