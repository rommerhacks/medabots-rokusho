	.syntax unified

	thumb_func_start sub_0802CC74
sub_0802CC74: @ 0x0802CC74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802CD28 @ =0x084D6464
	ldr r1, _0802CD2C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802CD30 @ =0x0850E838
	ldr r1, _0802CD34 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	ldr r0, _0802CD38 @ =0x03001800
	mov ip, r0
	ldr r0, _0802CD3C @ =0x03002C30
	mov sl, r5
	ldr r1, _0802CD40 @ =0x0000C624
	mov sb, r1
	movs r7, #0xf0
	movs r3, #0xf8
	add r3, ip
	mov r8, r3
	movs r1, #0x84
	lsls r1, r1, #4
	adds r2, r0, r1
	ldr r3, _0802CD44 @ =0x00000864
	adds r4, r0, r3
	movs r6, #0x40
_0802CCB2:
	mov r0, ip
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CCFE
	movs r3, #0
	mov r0, sb
	strh r0, [r2]
	strb r3, [r2, #0x1c]
	movs r0, #0x78
	strh r0, [r2, #2]
	strh r7, [r2, #4]
	strb r6, [r2, #8]
	strb r6, [r2, #9]
	movs r0, #7
	strb r0, [r2, #0xa]
	strb r7, [r2, #0xb]
	movs r0, #0x9a
	lsls r0, r0, #7
	strh r0, [r2, #6]
	movs r0, #4
	strb r0, [r4]
	strb r3, [r4, #1]
	mov r1, sl
	strh r1, [r2, #0x30]
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802CCFE
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
_0802CCFE:
	adds r2, #0x40
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802CCB2
	movs r0, #0x61
	bl play_sound_effect
	ldr r1, _0802CD38 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CD28: .4byte 0x084D6464
_0802CD2C: .4byte 0x06014800
_0802CD30: .4byte 0x0850E838
_0802CD34: .4byte 0x050002E0
_0802CD38: .4byte 0x03001800
_0802CD3C: .4byte 0x03002C30
_0802CD40: .4byte 0x0000C624
_0802CD44: .4byte 0x00000864
	.syntax divided
