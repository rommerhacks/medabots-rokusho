	.syntax unified

	thumb_func_start sub_0805E878
sub_0805E878: @ 0x0805E878
	push {r4, r5, r6, lr}
	ldr r0, _0805E8B0 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _0805E8B8
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _0805E8B4 @ =0x0000FFFF
	movs r0, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r6]
	lsls r0, r0, #2
	subs r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _0805E8CC
	.align 2, 0
_0805E8B0: .4byte 0x03000440
_0805E8B4: .4byte 0x0000FFFF
_0805E8B8:
	ldr r0, _0805E8D4 @ =0x03006F74
	ldr r1, [r0]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #2]
	strb r2, [r1, #6]
	ldr r1, _0805E8D8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805E8CC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805E8D4: .4byte 0x03006F74
_0805E8D8: .4byte 0x0300137C
	.syntax divided
