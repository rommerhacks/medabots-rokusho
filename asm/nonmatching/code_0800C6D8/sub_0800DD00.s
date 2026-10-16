	.syntax unified

	thumb_func_start sub_0800DD00
sub_0800DD00: @ 0x0800DD00
	push {r4, r5, lr}
	bl sub_0800EBFC
	bl sub_0800EF58
	ldr r0, _0800DD58 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x50
	bl sub_08041C14
	bl load_medapart_sprite_by_slot
	ldr r1, _0800DD5C @ =0x03000440
	adds r4, r1, #0
	adds r4, #0x42
	ldrb r0, [r4]
	cmp r0, #1
	bne _0800DD68
	adds r5, r1, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _0800DD70
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _0800DD60 @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _0800DD64 @ =0x0000F0FF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0800DD7C
	.align 2, 0
_0800DD58: .4byte 0x03001780
_0800DD5C: .4byte 0x03000440
_0800DD60: .4byte 0x0000FFFF
_0800DD64: .4byte 0x0000F0FF
_0800DD68:
	bl update_blend_effect
	cmp r0, #0
	beq _0800DD7C
_0800DD70:
	movs r0, #0
	strb r0, [r4]
	ldr r1, _0800DD84 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800DD7C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800DD84: .4byte 0x0300137C
	.syntax divided
