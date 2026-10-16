	.syntax unified

	thumb_func_start sub_0802DA60
sub_0802DA60: @ 0x0802DA60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0
	ldr r0, _0802DAC4 @ =0x030018D2
	mov r8, r0
	movs r7, #0
	movs r6, #0x84
	lsls r6, r6, #4
	movs r5, #0x84
	lsls r5, r5, #0x16
_0802DA76:
	mov r1, r8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DAA0
	lsrs r0, r5, #0x18
	movs r1, #1
	bl set_sprite_hidden_flags
	ldr r1, _0802DAC8 @ =0x03002C30
	adds r1, r6, r1
	ldrh r2, [r1]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	movs r0, #0x80
	strb r0, [r1, #8]
	strb r0, [r1, #9]
	strh r7, [r1, #0x18]
_0802DAA0:
	adds r6, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	bls _0802DA76
	ldr r1, _0802DACC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DAC4: .4byte 0x030018D2
_0802DAC8: .4byte 0x03002C30
_0802DACC: .4byte 0x03001800
	.syntax divided
