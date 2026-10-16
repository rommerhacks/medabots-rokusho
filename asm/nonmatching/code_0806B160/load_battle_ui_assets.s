	.syntax unified

	thumb_func_start load_battle_ui_assets
load_battle_ui_assets: @ 0x0806EF58
	push {lr}
	ldr r0, _0806EF78 @ =0x08485FD0
	ldr r0, [r0, #4]
	ldr r1, _0806EF7C @ =0x06010000
	bl LZ77UnCompVram
	ldr r0, _0806EF80 @ =0x087C8D54
	ldr r1, _0806EF84 @ =0x03001830
	bl LZ77UnCompVram
	ldr r1, _0806EF88 @ =0x0300137C
	movs r0, #6
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0806EF78: .4byte 0x08485FD0
_0806EF7C: .4byte 0x06010000
_0806EF80: .4byte 0x087C8D54
_0806EF84: .4byte 0x03001830
_0806EF88: .4byte 0x0300137C
	.syntax divided
