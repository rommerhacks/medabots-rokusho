	.syntax unified

	thumb_func_start sub_08057550
sub_08057550: @ 0x08057550
	push {lr}
	ldr r1, _08057568 @ =0x00000000
	ldr r2, _0805756C @ =0x42000000
	ldr r3, _08057570 @ =0x41000000
	movs r0, #0
	bl setup_palette_fade_to_color_with_obj
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_08057568: .4byte 0x00000000
_0805756C: .4byte 0x42000000
_08057570: .4byte 0x41000000
	.syntax divided
