	.syntax unified

	thumb_func_start sub_0803C738
sub_0803C738: @ 0x0803C738
	push {r4, r5, lr}
	ldr r5, _0803C758 @ =0x03002C30
	ldr r0, _0803C75C @ =0x03000440
	ldr r1, _0803C760 @ =0x0000012F
	adds r4, r0, r1
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r2, r0, r5
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C764
	subs r0, #1
	strb r0, [r1]
	b _0803C79E
	.align 2, 0
_0803C758: .4byte 0x03002C30
_0803C75C: .4byte 0x03000440
_0803C760: .4byte 0x0000012F
_0803C764:
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0803C7BC @ =0x083B5F80
	ldrb r1, [r4]
	lsls r0, r1, #6
	adds r0, r0, r5
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldr r1, _0803C7C0 @ =0x083CEC74
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	bl sub_0801BFB4
_0803C79E:
	ldr r1, _0803C7C4 @ =0x03002C30
	ldr r0, _0803C7C8 @ =0x03000440
	ldr r2, _0803C7CC @ =0x0000012F
	adds r0, r0, r2
	ldrb r2, [r0]
	lsls r0, r2, #6
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C7D0
	subs r0, #1
	strb r0, [r1]
	b _0803C7D6
	.align 2, 0
_0803C7BC: .4byte 0x083B5F80
_0803C7C0: .4byte 0x083CEC74
_0803C7C4: .4byte 0x03002C30
_0803C7C8: .4byte 0x03000440
_0803C7CC: .4byte 0x0000012F
_0803C7D0:
	adds r0, r2, #0
	bl update_sprite_animation_position
_0803C7D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
