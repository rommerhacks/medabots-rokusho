	.syntax unified

	thumb_func_start sub_08065020
sub_08065020: @ 0x08065020
	push {r4, r5, r6, lr}
	ldr r0, _08065058 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _08065060
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _0806505C @ =0x0000FFFF
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
	b _08065080
	.align 2, 0
_08065058: .4byte 0x03000440
_0806505C: .4byte 0x0000FFFF
_08065060:
	ldr r5, _08065088 @ =0x03006F74
	ldr r0, [r5]
	adds r0, #0x4c
	movs r4, #0
	strb r4, [r0]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r0, [r5]
	strb r4, [r0, #6]
	ldr r1, _0806508C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08065080:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08065088: .4byte 0x03006F74
_0806508C: .4byte 0x0300137C
	.syntax divided
