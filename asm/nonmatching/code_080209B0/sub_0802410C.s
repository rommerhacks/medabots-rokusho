	.syntax unified

	thumb_func_start sub_0802410C
sub_0802410C: @ 0x0802410C
	push {r4, r5, r6, r7, lr}
	ldr r0, _080241C4 @ =0x084D6464
	ldr r1, _080241C8 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080241CC @ =0x0850E838
	ldr r1, _080241D0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _080241D4 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r5, r2, r0
	ldrh r1, [r5]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r3, #0
	movs r6, #0
	movs r3, #0
	adds r4, r0, #0
	orrs r4, r1
	strh r4, [r5]
	ldr r7, _080241D8 @ =0x00000848
	adds r0, r2, r7
	movs r1, #0x40
	strb r1, [r0]
	adds r7, #1
	adds r0, r2, r7
	strb r1, [r0]
	ldr r1, _080241DC @ =0x00000858
	adds r0, r2, r1
	strh r3, [r0]
	ldr r3, _080241E0 @ =0x00000846
	adds r1, r2, r3
	movs r0, #0x9a
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r7, _080241E4 @ =0x03001800
	mov ip, r7
	mov r3, ip
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r7, #0x87
	lsls r7, r7, #4
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _080241E8 @ =0x00000872
	adds r1, r2, r3
	strh r0, [r1]
	subs r7, #0xc
	adds r2, r2, r7
	movs r0, #6
	strb r0, [r2]
	mov r0, ip
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080241AC
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r4, r0
	strh r4, [r5]
_080241AC:
	ldr r0, _080241EC @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	mov r1, ip
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080241C4: .4byte 0x084D6464
_080241C8: .4byte 0x06014800
_080241CC: .4byte 0x0850E838
_080241D0: .4byte 0x050002E0
_080241D4: .4byte 0x03002C30
_080241D8: .4byte 0x00000848
_080241DC: .4byte 0x00000858
_080241E0: .4byte 0x00000846
_080241E4: .4byte 0x03001800
_080241E8: .4byte 0x00000872
_080241EC: .4byte 0x03000440
	.syntax divided
