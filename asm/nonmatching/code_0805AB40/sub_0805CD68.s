	.syntax unified

	thumb_func_start sub_0805CD68
sub_0805CD68: @ 0x0805CD68
	push {r4, lr}
	ldr r0, _0805CD94 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #8
	bhi _0805CDD4
	ldr r0, _0805CD98 @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _0805CDA0
	ldrb r0, [r1]
	lsls r0, r0, #2
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _0805CD9C @ =0x00003FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	b _0805CDB0
	.align 2, 0
_0805CD94: .4byte 0x03000440
_0805CD98: .4byte 0x03006F74
_0805CD9C: .4byte 0x00003FFF
_0805CDA0:
	ldrb r0, [r1]
	lsls r0, r0, #2
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _0805CDCC @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
_0805CDB0:
	ldr r4, _0805CDD0 @ =0x03000440
	adds r4, #0x84
	ldrb r0, [r4]
	lsls r0, r0, #2
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _0805CDCC @ =0x0000FFFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0805CDE6
	.align 2, 0
_0805CDCC: .4byte 0x0000FFFF
_0805CDD0: .4byte 0x03000440
_0805CDD4:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0805CDEC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805CDE6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805CDEC: .4byte 0x0300137C
	.syntax divided
