	.syntax unified

	thumb_func_start sub_0803C680
sub_0803C680: @ 0x0803C680
	push {r4, r5, lr}
	ldr r4, _0803C6A0 @ =0x03002C30
	ldr r0, _0803C6A4 @ =0x03000440
	ldr r1, _0803C6A8 @ =0x0000012F
	adds r3, r0, r1
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r2, r0, r4
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C6AC
	subs r0, #1
	strb r0, [r1]
	b _0803C6CE
	.align 2, 0
_0803C6A0: .4byte 0x03002C30
_0803C6A4: .4byte 0x03000440
_0803C6A8: .4byte 0x0000012F
_0803C6AC:
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #8
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0803C6EC @ =0x083B5F80
	ldrb r1, [r3]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
_0803C6CE:
	ldr r5, _0803C6F0 @ =0x03002C30
	ldr r0, _0803C6F4 @ =0x03000440
	ldr r1, _0803C6F8 @ =0x0000012F
	adds r4, r0, r1
	ldrb r2, [r4]
	lsls r0, r2, #6
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C6FC
	subs r0, #1
	strb r0, [r1]
	b _0803C72E
	.align 2, 0
_0803C6EC: .4byte 0x083B5F80
_0803C6F0: .4byte 0x03002C30
_0803C6F4: .4byte 0x03000440
_0803C6F8: .4byte 0x0000012F
_0803C6FC:
	adds r0, r2, #0
	bl update_sprite_animation_position
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r5
	ldr r2, _0803C734 @ =0x083AFAB8
	adds r0, r1, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x23
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #0x1f
	ands r1, r2
	strb r1, [r0]
_0803C72E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803C734: .4byte 0x083AFAB8
	.syntax divided
