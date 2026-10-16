	.syntax unified

	thumb_func_start sub_08038178
sub_08038178: @ 0x08038178
	push {r4, lr}
	ldr r0, _080381AC @ =0x083B5F80
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _080381B0 @ =0x03000440
	ldr r2, _080381B4 @ =0x0000012F
	adds r4, r1, r2
	ldrb r1, [r4]
	bl process_sprite_anim_commands
	ldr r3, _080381B8 @ =0x03002C30
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r2, [r0]
	cmp r2, #0x5a
	bne _080381BC
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080381D8
	.align 2, 0
_080381AC: .4byte 0x083B5F80
_080381B0: .4byte 0x03000440
_080381B4: .4byte 0x0000012F
_080381B8: .4byte 0x03002C30
_080381BC:
	movs r0, #7
	ands r0, r2
	cmp r0, #0
	bne _080381CA
	ldrh r0, [r1, #4]
	subs r0, #1
	strh r0, [r1, #4]
_080381CA:
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_080381D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
