	.syntax unified

	thumb_func_start sub_0800D90C
sub_0800D90C: @ 0x0800D90C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x24]
	ldr r1, _0800D9C4 @ =0x040000D4
	add r0, sp, #0x24
	str r0, [r1]
	ldr r0, _0800D9C8 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _0800D9CC @ =0x00000B84
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _0800D9D0 @ =0x85000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r6, _0800D9D4 @ =0x03000440
	adds r7, r6, #0
	adds r7, #0x39
	ldrb r3, [r7]
	str r3, [sp]
	movs r0, #0x38
	str r0, [sp, #4]
	movs r0, #0x68
	str r0, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r5, #1
	str r5, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	movs r0, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl init_scene_with_bg_and_palette
	ldrb r3, [r7]
	str r3, [sp]
	movs r0, #0xb8
	str r0, [sp, #4]
	movs r0, #0x30
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	str r5, [sp, #0x1c]
	movs r0, #0x28
	str r0, [sp, #0x20]
	movs r0, #1
	adds r1, r3, #0
	adds r2, r3, #0
	bl init_scene_with_bg_and_palette
	adds r5, r6, #0
	adds r5, #0x34
	ldrb r0, [r5]
	adds r4, r6, #0
	adds r4, #0x35
	adds r0, r0, r4
	ldrb r1, [r0]
	ldrb r2, [r7]
	movs r0, #0
	bl advance_text_display
	ldrb r0, [r5]
	adds r0, r0, r4
	ldrb r1, [r0]
	ldrb r2, [r7]
	movs r0, #1
	bl advance_text_display
	ldr r0, _0800D9D8 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D9BA
	adds r1, r6, #0
	adds r1, #0x33
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
_0800D9BA:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D9C4: .4byte 0x040000D4
_0800D9C8: .4byte 0x03002414
_0800D9CC: .4byte 0x00000B84
_0800D9D0: .4byte 0x85000100
_0800D9D4: .4byte 0x03000440
_0800D9D8: .4byte 0x0300058C
	.syntax divided
