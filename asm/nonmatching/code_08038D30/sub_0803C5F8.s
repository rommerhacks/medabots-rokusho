	.syntax unified

	thumb_func_start sub_0803C5F8
sub_0803C5F8: @ 0x0803C5F8
	push {r4, r5, lr}
	ldr r4, _0803C618 @ =0x03002C30
	ldr r0, _0803C61C @ =0x03000440
	ldr r1, _0803C620 @ =0x0000012F
	adds r3, r0, r1
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r2, r0, r4
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C624
	subs r0, #1
	strb r0, [r1]
	b _0803C646
	.align 2, 0
_0803C618: .4byte 0x03002C30
_0803C61C: .4byte 0x03000440
_0803C620: .4byte 0x0000012F
_0803C624:
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #8
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0803C664 @ =0x083B5F80
	ldrb r1, [r3]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
_0803C646:
	ldr r1, _0803C668 @ =0x03002C30
	ldr r0, _0803C66C @ =0x03000440
	ldr r2, _0803C670 @ =0x0000012F
	adds r0, r0, r2
	ldrb r2, [r0]
	lsls r0, r2, #6
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C674
	subs r0, #1
	strb r0, [r1]
	b _0803C67A
	.align 2, 0
_0803C664: .4byte 0x083B5F80
_0803C668: .4byte 0x03002C30
_0803C66C: .4byte 0x03000440
_0803C670: .4byte 0x0000012F
_0803C674:
	adds r0, r2, #0
	bl update_sprite_animation_position
_0803C67A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
