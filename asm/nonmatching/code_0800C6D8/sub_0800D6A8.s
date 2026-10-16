	.syntax unified

	thumb_func_start sub_0800D6A8
sub_0800D6A8: @ 0x0800D6A8
	push {r4, r5, r6, lr}
	sub sp, #0x20
	bl init_scene_buffers_080445F4
	ldr r5, _0800D70C @ =0x03000440
	adds r6, r5, #0
	adds r6, #0x39
	ldrb r3, [r6]
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
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r0, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl setup_scene_with_bg_and_sprites
	ldrb r3, [r6]
	str r3, [sp]
	movs r0, #0xb8
	str r0, [sp, #4]
	movs r0, #0x30
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	str r0, [sp, #0x1c]
	adds r1, r3, #0
	adds r2, r3, #0
	bl setup_scene_with_bg_and_sprites
	adds r5, #0x33
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D70C: .4byte 0x03000440
	.syntax divided
