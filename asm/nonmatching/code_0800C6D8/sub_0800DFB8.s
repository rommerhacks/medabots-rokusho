	.syntax unified

	thumb_func_start sub_0800DFB8
sub_0800DFB8: @ 0x0800DFB8
	push {r4, lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800E000 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	ldr r0, _0800E004 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #8
	bhi _0800E010
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r2, _0800E008 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r4]
	lsls r1, r1, #2
	ldr r2, _0800E00C @ =0x0000F0FF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0800E016
	.align 2, 0
_0800E000: .4byte 0x03001780
_0800E004: .4byte 0x03000440
_0800E008: .4byte 0x0000FFFF
_0800E00C: .4byte 0x0000F0FF
_0800E010:
	ldr r1, _0800E01C @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
_0800E016:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E01C: .4byte 0x0300137C
	.syntax divided
