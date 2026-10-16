	.syntax unified

	thumb_func_start increment_medal_level_on_input
increment_medal_level_on_input: @ 0x0800B4EC
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r6, _0800B580 @ =0x03000BE0
	ldr r4, _0800B584 @ =0x03000440
	adds r5, r4, #0
	adds r5, #0x3d
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r2, r0, r6
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800B576
	ldr r0, _0800B588 @ =0x03002B64
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800B576
	ldr r0, _0800B58C @ =0x03001798
	ldrb r1, [r0, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800B576
	ldrb r0, [r2, #5]
	cmp r0, #0x64
	beq _0800B576
	adds r0, #1
	strb r0, [r2, #5]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	lsls r0, r0, #4
	ldr r1, _0800B590 @ =0x083B6158
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xee
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r6
	ldrb r0, [r0, #5]
	adds r1, r4, #0
	adds r1, #0xf1
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xf2
	ldrb r2, [r2]
	adds r3, r4, #0
	adds r3, #0xf3
	ldrb r3, [r3]
	adds r4, #0xf4
	ldrb r4, [r4]
	str r4, [sp]
	bl sub_080420C4
	ldrb r1, [r5]
	lsls r1, r1, #6
	adds r1, r1, r6
	strb r0, [r1, #8]
	bl load_medal_sprite
	bl render_medal_slots_in_menu
_0800B576:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800B580: .4byte 0x03000BE0
_0800B584: .4byte 0x03000440
_0800B588: .4byte 0x03002B64
_0800B58C: .4byte 0x03001798
_0800B590: .4byte 0x083B6158
	.syntax divided
