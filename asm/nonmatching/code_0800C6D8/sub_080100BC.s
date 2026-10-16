	.syntax unified

	thumb_func_start sub_080100BC
sub_080100BC: @ 0x080100BC
	push {lr}
	ldr r2, _080100DC @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080100E8
	ldr r0, _080100E0 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x4a
	ldrb r0, [r1]
	cmp r0, #0
	bne _080100E4
	movs r0, #2
	b _080100E6
	.align 2, 0
_080100DC: .4byte 0x03001798
_080100E0: .4byte 0x03000440
_080100E4:
	subs r0, #1
_080100E6:
	strb r0, [r1]
_080100E8:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0801010C
	ldr r0, _08010104 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x4a
	ldrb r0, [r1]
	cmp r0, #2
	bne _08010108
	movs r0, #0
	b _0801010A
	.align 2, 0
_08010104: .4byte 0x03000440
_08010108:
	adds r0, #1
_0801010A:
	strb r0, [r1]
_0801010C:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _08010130
	movs r0, #2
	bl play_sound_effect
	ldr r0, _08010134 @ =0x03002C30
	ldr r1, _08010138 @ =0x03000440
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x38
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_08010130:
	pop {r0}
	bx r0
	.align 2, 0
_08010134: .4byte 0x03002C30
_08010138: .4byte 0x03000440
	.syntax divided
