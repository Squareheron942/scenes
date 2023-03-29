
@{{BLOCK(bgwood_bn_gfx)

@=======================================================================
@
@	bgwood_bn_gfx, 8x8@4, 
@	+ palette 16 entries, not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2023-03-28, 18:06:53
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bgwood_bn_gfxPal		@ 32 unsigned chars
	.hidden bgwood_bn_gfxPal
bgwood_bn_gfxPal:
	.hword 0x03E0,0x2DE4,0x2181,0x0210,0x09A0,0x09A0,0x2DE4,0x2181
	.hword 0x01C3,0x1DA0,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(bgwood_bn_gfx)
