	.syntax unified

	thumb_func_start sub_0802DAD0
sub_0802DAD0: @ 0x0802DAD0
	push {r4, r5, r6, lr}
	movs r4, #0
	movs r3, #0
	movs r2, #0
	ldr r5, _0802DAF8 @ =0x030018D2
	ldr r0, _0802DAFC @ =0x03002C30
	movs r6, #0x84
	lsls r6, r6, #4
	adds r1, r0, r6
_0802DAE2:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DB0A
	adds r3, #1
	ldrb r0, [r1, #8]
	cmp r0, #0x40
	bne _0802DB00
	adds r4, #1
	b _0802DB0A
	.align 2, 0
_0802DAF8: .4byte 0x030018D2
_0802DAFC: .4byte 0x03002C30
_0802DB00:
	subs r0, #8
	strb r0, [r1, #8]
	ldrb r0, [r1, #9]
	subs r0, #8
	strb r0, [r1, #9]
_0802DB0A:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802DAE2
	cmp r4, r3
	bne _0802DB2E
	movs r0, #0x3c
	bl play_sound_effect
	ldr r0, _0802DB34 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	ldr r1, _0802DB38 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802DB2E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DB34: .4byte 0x03000440
_0802DB38: .4byte 0x03001800
	.syntax divided
