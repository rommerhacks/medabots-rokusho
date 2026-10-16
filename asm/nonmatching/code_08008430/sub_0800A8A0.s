	.syntax unified

	thumb_func_start sub_0800A8A0
	.global sub_0800A8A0
sub_0800A8A0: @ 0x0800A8A0
	push {lr}
	ldr r2, _0800A8C0 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800A8CC
	ldr r0, _0800A8C4 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x46
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800A8C8
	movs r0, #2
	b _0800A8CA
	.align 2, 0
_0800A8C0: .4byte 0x03001798
_0800A8C4: .4byte 0x03000440
_0800A8C8:
	subs r0, #1
_0800A8CA:
	strb r0, [r1]
_0800A8CC:
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800A8F0
	ldr r0, _0800A8E8 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x46
	ldrb r0, [r1]
	cmp r0, #2
	bne _0800A8EC
	movs r0, #0
	b _0800A8EE
	.align 2, 0
_0800A8E8: .4byte 0x03000440
_0800A8EC:
	adds r0, #1
_0800A8EE:
	strb r0, [r1]
_0800A8F0:
	ldrb r1, [r2]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	bne _0800A8FE
	movs r0, #0
	b _0800A91A
_0800A8FE:
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0800A920 @ =0x03002C30
	ldr r1, _0800A924 @ =0x03000440
	adds r1, #0x46
	ldrb r1, [r1]
	lsls r1, r1, #4
	adds r1, #0x38
	adds r0, #0xc4
	strh r1, [r0]
	bl sub_0800A594
	movs r0, #1
_0800A91A:
	pop {r1}
	bx r1
	.align 2, 0
_0800A920: .4byte 0x03002C30
_0800A924: .4byte 0x03000440
	.syntax divided
