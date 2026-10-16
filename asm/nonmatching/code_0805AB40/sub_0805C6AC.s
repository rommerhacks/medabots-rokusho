	.syntax unified

	thumb_func_start sub_0805C6AC
sub_0805C6AC: @ 0x0805C6AC
	push {r4, r5, r6, lr}
	ldr r5, _0805C6E8 @ =0x03006F74
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805C6FC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0805C6EC
	ldr r0, [r5]
	ldrb r2, [r0, #5]
	adds r0, #0x48
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x1f
	ands r0, r1
	movs r1, #0
	cmp r0, #0xf
	bgt _0805C6DE
	movs r1, #0x20
_0805C6DE:
	adds r0, r2, #0
	bl sub_0805BEA0
	b _0805C792
	.align 2, 0
_0805C6E8: .4byte 0x03006F74
_0805C6EC:
	bl copy_obj_palette_to_buffer
	ldr r0, _0805C6F8 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	b _0805C792
	.align 2, 0
_0805C6F8: .4byte 0x03000440
_0805C6FC:
	movs r0, #4
	bl is_sound_playing_with_lock
	cmp r0, #0
	bne _0805C792
	ldr r0, _0805C740 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _0805C748
	movs r0, #0x1f
	lsls r4, r0, #0xa
	lsls r1, r0, #5
	orrs r4, r1
	orrs r4, r0
	ldrb r1, [r6]
	lsls r1, r1, #2
	ldr r5, _0805C744 @ =0x0000FFFF
	adds r0, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r6]
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _0805C792
	.align 2, 0
_0805C740: .4byte 0x03000440
_0805C744: .4byte 0x0000FFFF
_0805C748:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0805C764 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	ldr r0, [r5]
	ldrb r0, [r0, #5]
	cmp r0, #0
	beq _0805C768
	cmp r0, #1
	beq _0805C780
	b _0805C792
	.align 2, 0
_0805C764: .4byte 0x0000FDFF
_0805C768:
	ldr r2, _0805C778 @ =0x03001784
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0805C77C @ =0x0300137C
	movs r0, #8
	b _0805C790
	.align 2, 0
_0805C778: .4byte 0x03001784
_0805C77C: .4byte 0x0300137C
_0805C780:
	ldr r2, _0805C798 @ =0x03001784
	ldrb r1, [r2]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r1, _0805C79C @ =0x0300137C
	movs r0, #7
_0805C790:
	str r0, [r1]
_0805C792:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805C798: .4byte 0x03001784
_0805C79C: .4byte 0x0300137C
	.syntax divided
