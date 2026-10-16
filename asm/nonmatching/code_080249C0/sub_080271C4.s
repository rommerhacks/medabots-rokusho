	.syntax unified

	thumb_func_start sub_080271C4
sub_080271C4: @ 0x080271C4
	push {r4, lr}
	ldr r3, _080271DC @ =0x03002C30
	ldr r0, _080271E0 @ =0x00000848
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	beq _080271E8
	subs r0, #8
	strb r0, [r1]
	ldr r1, _080271E4 @ =0x00000849
	b _0802720A
	.align 2, 0
_080271DC: .4byte 0x03002C30
_080271E0: .4byte 0x00000848
_080271E4: .4byte 0x00000849
_080271E8:
	movs r4, #0x88
	lsls r4, r4, #4
	adds r2, r3, r4
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08027224 @ =0x00000888
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	beq _0802722C
	subs r0, #8
	strb r0, [r1]
	ldr r1, _08027228 @ =0x00000889
_0802720A:
	adds r2, r3, r1
	ldrb r1, [r2]
	subs r1, #8
	strb r1, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _0802723E
	movs r0, #0x30
	bl play_sound_effect
	b _0802723E
	.align 2, 0
_08027224: .4byte 0x00000888
_08027228: .4byte 0x00000889
_0802722C:
	ldr r0, _08027244 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08027248 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802723E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027244: .4byte 0x03000440
_08027248: .4byte 0x03001800
	.syntax divided
