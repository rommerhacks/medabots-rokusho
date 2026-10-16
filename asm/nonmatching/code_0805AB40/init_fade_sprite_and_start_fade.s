	.syntax unified

	thumb_func_start init_fade_sprite_and_start_fade
init_fade_sprite_and_start_fade: @ 0x0805D338
	push {r4, r5, lr}
	ldr r5, _0805D370 @ =0x03006F74
	ldr r4, _0805D374 @ =0x03004130
	adds r0, r4, #0
	bl calc_fade_sprite_position
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	ldr r1, [r5]
	movs r0, #1
	strb r0, [r1, #0x12]
	ldr r1, [r5]
	ldrb r0, [r1, #0xc]
	strb r0, [r1, #0x13]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805D370: .4byte 0x03006F74
_0805D374: .4byte 0x03004130
	.syntax divided
