	.syntax unified

	thumb_func_start sub_0802E948
sub_0802E948: @ 0x0802E948
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0802EA70 @ =0x084E1518
	ldr r1, _0802EA74 @ =0x06017000
	bl lz_decompress_dispatch
	ldr r0, _0802EA78 @ =0x0850EED8
	ldr r1, _0802EA7C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0802EA80 @ =0x084C8AC4
	ldr r1, _0802EA84 @ =0x06014E00
	bl lz_decompress_dispatch
	ldr r0, _0802EA88 @ =0x084E3018
	ldr r1, _0802EA8C @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	movs r6, #0
	ldr r5, _0802EA90 @ =0x03001800
	ldr r3, _0802EA94 @ =0x03002C30
	movs r0, #0xf8
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x84
	lsls r1, r1, #4
	adds r4, r3, r1
	ldr r2, _0802EA98 @ =0x00000863
	adds r2, r3, r2
	str r2, [sp, #4]
	movs r7, #0x87
	adds r7, r7, r5
	mov sb, r7
	movs r0, #0x60
	adds r0, r0, r5
	mov r8, r0
_0802E99C:
	adds r0, r5, #0
	adds r0, #0xd2
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EA46
	movs r1, #0x21
	adds r1, r1, r6
	mov ip, r1
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	lsls r0, r0, #0xa
	ldr r2, _0802EA9C @ =0xFFFFC004
	adds r1, r2, #0
	movs r2, #0
	orrs r0, r1
	strh r0, [r4]
	strb r2, [r4, #0x1c]
	mov r7, sb
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r7]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0x81
	strb r0, [r4, #0xb]
	mov r7, r8
	ldrb r0, [r7]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r4, #0x30]
	ldrb r0, [r7]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #0x32]
	movs r0, #6
	ldr r1, [sp, #4]
	strb r0, [r1, #1]
	strb r2, [r1]
	movs r0, #1
	strb r0, [r1, #6]
	mov r7, sl
	ldrb r7, [r7]
	ands r0, r7
	cmp r0, #0
	beq _0802EA2E
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
_0802EA2E:
	ldr r0, _0802EAA0 @ =0x083B5F80
	movs r7, #0xd4
	lsls r7, r7, #1
	adds r0, r0, r7
	ldr r0, [r0]
	mov r2, ip
	lsls r1, r2, #0x18
	lsrs r1, r1, #0x18
	str r3, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r3, [sp]
_0802EA46:
	adds r4, #0x40
	ldr r7, [sp, #4]
	adds r7, #0x40
	str r7, [sp, #4]
	adds r6, #1
	cmp r6, #2
	bls _0802E99C
	ldr r1, _0802EA90 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802EA70: .4byte 0x084E1518
_0802EA74: .4byte 0x06017000
_0802EA78: .4byte 0x0850EED8
_0802EA7C: .4byte 0x050002E0
_0802EA80: .4byte 0x084C8AC4
_0802EA84: .4byte 0x06014E00
_0802EA88: .4byte 0x084E3018
_0802EA8C: .4byte 0x050002C0
_0802EA90: .4byte 0x03001800
_0802EA94: .4byte 0x03002C30
_0802EA98: .4byte 0x00000863
_0802EA9C: .4byte 0xFFFFC004
_0802EAA0: .4byte 0x083B5F80
	.syntax divided
