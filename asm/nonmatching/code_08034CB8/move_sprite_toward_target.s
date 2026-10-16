	.syntax unified

	thumb_func_start move_sprite_toward_target
	.global move_sprite_toward_target
move_sprite_toward_target: @ 0x080355F0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08035614 @ =0x03002C30
	lsls r1, r5, #6
	adds r2, r1, r0
	movs r3, #2
	ldrsh r1, [r2, r3]
	adds r3, r0, #0
	ldrh r0, [r2, #0x30]
	cmp r1, r0
	bne _08035618
	movs r1, #4
	ldrsh r0, [r2, r1]
	ldrh r2, [r2, #0x32]
	cmp r0, r2
	bne _08035618
	movs r0, #1
	b _08035650
	.align 2, 0
_08035614: .4byte 0x03002C30
_08035618:
	lsls r0, r5, #6
	adds r4, r0, r3
	movs r2, #2
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	ldrh r2, [r4, #0x30]
	ldrh r3, [r4, #0x32]
	bl calculate_direction_index
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	adds r0, r5, #0
	bl update_sprite_animation_position
	adds r0, r5, #0
	bl check_sprite_in_range
	cmp r0, #0
	beq _0803564E
	ldrh r0, [r4, #0x30]
	strh r0, [r4, #2]
	ldrh r0, [r4, #0x32]
	strh r0, [r4, #4]
	movs r0, #1
	b _08035650
_0803564E:
	movs r0, #0
_08035650:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
