	.syntax unified

	thumb_func_start sub_0801F800
sub_0801F800: @ 0x0801F800
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, _0801F830 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801F834
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r0, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r2, r3
	b _0801F848
	.align 2, 0
_0801F830: .4byte 0x03001800
_0801F834:
	movs r5, #0xaa
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrh r0, [r0]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r2, r1
_0801F848:
	ldrh r5, [r0]
	ldr r0, _0801F860 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801F888
	cmp r0, #1
	bgt _0801F864
	cmp r0, #0
	beq _0801F86E
	b _0801F8D6
	.align 2, 0
_0801F860: .4byte 0x03001800
_0801F864:
	cmp r0, #2
	beq _0801F8A0
	cmp r0, #3
	beq _0801F8C4
	b _0801F8D6
_0801F86E:
	ldr r0, _0801F87C @ =0x084CAB58
	ldr r1, _0801F880 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801F884 @ =0x0850E1D8
	b _0801F8AA
	.align 2, 0
_0801F87C: .4byte 0x084CAB58
_0801F880: .4byte 0x06010000
_0801F884: .4byte 0x0850E1D8
_0801F888:
	ldr r0, _0801F894 @ =0x084CAFD8
	ldr r1, _0801F898 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801F89C @ =0x0850E1F8
	b _0801F8AA
	.align 2, 0
_0801F894: .4byte 0x084CAFD8
_0801F898: .4byte 0x06010000
_0801F89C: .4byte 0x0850E1F8
_0801F8A0:
	ldr r0, _0801F8B4 @ =0x084CB36C
	ldr r1, _0801F8B8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801F8BC @ =0x0850E218
_0801F8AA:
	ldr r1, _0801F8C0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	b _0801F8D6
	.align 2, 0
_0801F8B4: .4byte 0x084CB36C
_0801F8B8: .4byte 0x06010000
_0801F8BC: .4byte 0x0850E218
_0801F8C0: .4byte 0x050003C0
_0801F8C4:
	ldr r0, _0801F97C @ =0x084CB684
	ldr r1, _0801F980 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801F984 @ =0x0850E238
	ldr r1, _0801F988 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
_0801F8D6:
	ldr r1, _0801F98C @ =0x03002C30
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	mov sb, r3
	ldr r2, _0801F990 @ =0x0000C404
	mov r8, r2
	mov r3, r8
	strh r3, [r0]
	movs r2, #0xa7
	lsls r2, r2, #2
	adds r0, r1, r2
	mov r3, sb
	strb r3, [r0]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r2, r4, #0
	subs r2, #0x10
	ldr r3, _0801F994 @ =0x00000282
	adds r0, r1, r3
	strh r2, [r0]
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	adds r2, r3, #0
	subs r2, #8
	movs r5, #0xa1
	lsls r5, r5, #2
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _0801F998 @ =0x0000028A
	adds r0, r1, r2
	movs r6, #0xe
	strb r6, [r0]
	adds r5, #7
	adds r0, r1, r5
	movs r5, #0x80
	strb r5, [r0]
	ldr r0, _0801F99C @ =0x00000286
	adds r2, r1, r0
	movs r0, #0xb8
	lsls r0, r0, #5
	strh r0, [r2]
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r0, r1, r2
	mov r2, r8
	strh r2, [r0]
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r1, r2
	mov r2, sb
	strb r2, [r0]
	adds r4, #0x10
	ldr r2, _0801F9A0 @ =0x000002C2
	adds r0, r1, r2
	strh r4, [r0]
	adds r3, #8
	adds r2, #2
	adds r0, r1, r2
	strh r3, [r0]
	ldr r3, _0801F9A4 @ =0x000002CA
	adds r0, r1, r3
	strb r6, [r0]
	adds r2, #7
	adds r0, r1, r2
	strb r5, [r0]
	subs r3, #4
	adds r1, r1, r3
	ldr r0, _0801F9A8 @ =0x00001701
	strh r0, [r1]
	ldr r1, _0801F9AC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F97C: .4byte 0x084CB684
_0801F980: .4byte 0x06010000
_0801F984: .4byte 0x0850E238
_0801F988: .4byte 0x050003C0
_0801F98C: .4byte 0x03002C30
_0801F990: .4byte 0x0000C404
_0801F994: .4byte 0x00000282
_0801F998: .4byte 0x0000028A
_0801F99C: .4byte 0x00000286
_0801F9A0: .4byte 0x000002C2
_0801F9A4: .4byte 0x000002CA
_0801F9A8: .4byte 0x00001701
_0801F9AC: .4byte 0x03001800
	.syntax divided
