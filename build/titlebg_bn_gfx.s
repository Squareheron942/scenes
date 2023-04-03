
@{{BLOCK(titlebg_bn_gfx)

@=======================================================================
@
@	titlebg_bn_gfx, 256x256@4, 
@	+ palette 16 entries, not compressed
@	+ 14 tiles (t|f|p reduced) not compressed
@	+ regular map (flat), not compressed, 32x32 
@	Total size: 32 + 448 + 2048 = 2528
@
@	Time-stamp: 2023-03-31, 11:31:36
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global titlebg_bn_gfxTiles		@ 448 unsigned chars
	.hidden titlebg_bn_gfxTiles
titlebg_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777,0x77777777
	.word 0x77777777,0x77777777,0x76767676,0x67676767,0x76767676,0x66666666,0x66666666,0x66666666
	.word 0x66666666,0x66666666,0x66666666,0x66666666,0x66666666,0x66666666,0x66666666,0x66666666
	.word 0x66666666,0x66666666,0x65656565,0x56565656,0x65656565,0x55555555,0x55555555,0x55555555
	.word 0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555,0x55555555
	.word 0x55555555,0x55555555,0x54545454,0x45454545,0x54545454,0x44444444,0x44444444,0x44444444
	.word 0x44444444,0x44444444,0x44444444,0x44444444,0x44444444,0x44444444,0x44444444,0x44444444

	.word 0x44444444,0x44444444,0x34343434,0x43434343,0x34343434,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333,0x33333333
	.word 0x33333333,0x33333333,0x33333333,0x23232323,0x32323232,0x23232323,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222,0x22222222
	.word 0x22222222,0x22222222,0x22222222,0x12121212,0x21212121,0x12121212,0x11111111,0x11111111
	.word 0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111

	.section .rodata
	.align	2
	.global titlebg_bn_gfxMap		@ 2048 unsigned chars
	.hidden titlebg_bn_gfxMap
titlebg_bn_gfxMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0000,0x0000
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000,0x0000

	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0000,0x0000
	.hword 0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004
	.hword 0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004
	.hword 0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004
	.hword 0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0000,0x0000

	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0005
	.hword 0x0005,0x0005,0x0005,0x0005,0x0005,0x0005,0x0000,0x0000
	.hword 0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0006
	.hword 0x0006,0x0006,0x0006,0x0006,0x0006,0x0006,0x0000,0x0000

	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0007
	.hword 0x0007,0x0007,0x0007,0x0007,0x0007,0x0007,0x0000,0x0000

	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0000,0x0000
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0000,0x0000

	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0009
	.hword 0x0009,0x0009,0x0009,0x0009,0x0009,0x0009,0x0000,0x0000
	.hword 0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x000A
	.hword 0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x000A
	.hword 0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x000A
	.hword 0x000A,0x000A,0x000A,0x000A,0x000A,0x000A,0x0000,0x0000

	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x0000,0x0000
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x0000,0x0000

	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x000B
	.hword 0x000B,0x000B,0x000B,0x000B,0x000B,0x000B,0x0000,0x0000
	.hword 0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C
	.hword 0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C
	.hword 0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x000C
	.hword 0x000C,0x000C,0x000C,0x000C,0x000C,0x000C,0x0000,0x0000

	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x0000,0x0000
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x0000,0x0000

	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x0000,0x0000
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x000D
	.hword 0x000D,0x000D,0x000D,0x000D,0x000D,0x000D,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.section .rodata
	.align	2
	.global titlebg_bn_gfxPal		@ 32 unsigned chars
	.hidden titlebg_bn_gfxPal
titlebg_bn_gfxPal:
	.hword 0x0800,0x3681,0x3A41,0x3DE1,0x45C0,0x4980,0x4D40,0x5520
	.hword 0x4210,0x001F,0x03E0,0x03FF,0x7C00,0x7C1F,0x7FE0,0x7FFF

@}}BLOCK(titlebg_bn_gfx)
