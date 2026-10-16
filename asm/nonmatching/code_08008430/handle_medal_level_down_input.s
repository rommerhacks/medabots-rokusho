	.syntax unified

	thumb_func_start handle_medal_level_down_input
handle_medal_level_down_input: @ 0x0800B594
	push {lr}
	ldr r1, _0800B5D8 @ =0x03000BE0
	ldr r0, _0800B5DC @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800B5D2
	ldr r0, _0800B5E0 @ =0x03002B64
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0800B5D2
	ldr r0, _0800B5E4 @ =0x03001798
	ldrb r1, [r0, #1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800B5D2
	ldrh r0, [r2, #2]
	cmp r0, #0x63
	bls _0800B5D2
	subs r0, #0x64
	strh r0, [r2, #2]
	bl render_medal_level_display
_0800B5D2:
	pop {r0}
	bx r0
	.align 2, 0
_0800B5D8: .4byte 0x03000BE0
_0800B5DC: .4byte 0x03000440
_0800B5E0: .4byte 0x03002B64
_0800B5E4: .4byte 0x03001798
	.syntax divided
