	.syntax unified

	thumb_func_start sub_0800F08C
sub_0800F08C: @ 0x0800F08C
	push {lr}
	sub sp, #8
	ldr r2, _0800F0AC @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800F0B8
	ldr r0, _0800F0B0 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3f
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800F0B4
	movs r0, #0x1d
	b _0800F0B6
	.align 2, 0
_0800F0AC: .4byte 0x03001798
_0800F0B0: .4byte 0x03000440
_0800F0B4:
	subs r0, #1
_0800F0B6:
	strb r0, [r1]
_0800F0B8:
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800F0DC
	ldr r0, _0800F0D4 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3f
	ldrb r0, [r1]
	cmp r0, #0x1d
	bne _0800F0D8
	movs r0, #0
	b _0800F0DA
	.align 2, 0
_0800F0D4: .4byte 0x03000440
_0800F0D8:
	adds r0, #1
_0800F0DA:
	strb r0, [r1]
_0800F0DC:
	ldrb r1, [r2]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	bne _0800F0EA
	movs r0, #0
	b _0800F136
_0800F0EA:
	movs r0, #2
	bl play_sound_effect
	ldr r2, _0800F13C @ =0x03000440
	adds r3, r2, #0
	adds r3, #0x3f
	ldrb r0, [r3]
	adds r1, r2, #0
	adds r1, #0x40
	lsls r0, r0, #2
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x3d
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, #1
	ldr r1, _0800F140 @ =0x0400000A
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, _0800F144 @ =0x00007360
	str r1, [sp, #4]
	movs r1, #0xb
	movs r2, #2
	movs r3, #2
	bl sub_08042950
	bl sub_0800EC44
	bl sub_0800ED10
	bl sub_0800EDA0
	bl sub_0800EE34
	bl load_overworld_sprite_by_direction
	movs r0, #1
_0800F136:
	add sp, #8
	pop {r1}
	bx r1
	.align 2, 0
_0800F13C: .4byte 0x03000440
_0800F140: .4byte 0x0400000A
_0800F144: .4byte 0x00007360
	.syntax divided
