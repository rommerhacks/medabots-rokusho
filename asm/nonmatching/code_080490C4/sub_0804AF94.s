	.syntax unified

	thumb_func_start sub_0804AF94
sub_0804AF94: @ 0x0804AF94
	push {lr}
	ldr r0, _0804AFAC @ =0x00007FFF
	ldr r1, _0804AFB0 @ =0x00000000
	ldr r2, _0804AFB4 @ =0x42000000
	ldr r3, _0804AFB8 @ =0x41000000
	bl setup_palette_fade_to_color_with_obj
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_0804AFAC: .4byte 0x00007FFF
_0804AFB0: .4byte 0x00000000
_0804AFB4: .4byte 0x42000000
_0804AFB8: .4byte 0x41000000
	.syntax divided
