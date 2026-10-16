	.syntax unified

	thumb_func_start sub_080068EC
sub_080068EC: @ 0x080068EC
	push {lr}
	ldr r2, _0800690C @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08006918
	ldr r0, _08006910 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r0, [r1]
	cmp r0, #0
	bne _08006914
	movs r0, #4
	b _08006916
	.align 2, 0
_0800690C: .4byte 0x03001798
_08006910: .4byte 0x03000440
_08006914:
	subs r0, #1
_08006916:
	strb r0, [r1]
_08006918:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800693C
	ldr r0, _08006934 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r0, [r1]
	cmp r0, #4
	bne _08006938
	movs r0, #0
	b _0800693A
	.align 2, 0
_08006934: .4byte 0x03000440
_08006938:
	adds r0, #1
_0800693A:
	strb r0, [r1]
_0800693C:
	ldr r0, [r2]
	lsls r1, r0, #0x19
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1f
	orrs r1, r0
	cmp r1, #0
	bne _08006950
	movs r0, #0
	b _0800697A
_08006950:
	movs r0, #2
	bl play_sound_effect
	movs r0, #0
	bl sub_08006238
	movs r0, #0
	bl sub_08006284
	movs r0, #0
	bl sub_080062D0
	movs r0, #0
	bl sub_0800631C
	movs r0, #0
	bl sub_08006368
	bl setup_battle_cursor_sprites
	movs r0, #1
_0800697A:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
