	.syntax unified

	thumb_func_start sound_init
	.global sound_init
sound_init: @ 0x0800058C
	push {lr}
	bl sound_engine_init
	ldr r0, _080005BC @ =0x080AFFB8
	bl sub_08074900
	ldr r0, _080005C0 @ =0x080B06EC
	bl sub_08074BC4
	ldr r0, _080005C4 @ =0x080B1788
	bl sub_08074E70
	ldr r0, _080005C8 @ =0x080B1570
	bl sub_08073AE4
	ldr r0, _080005CC @ =0x080B1718
	bl sub_08073AF8
	movs r0, #0
	bl play_song
	pop {r0}
	bx r0
	.align 2, 0
_080005BC: .4byte 0x080AFFB8
_080005C0: .4byte 0x080B06EC
_080005C4: .4byte 0x080B1788
_080005C8: .4byte 0x080B1570
_080005CC: .4byte 0x080B1718
	.syntax divided
