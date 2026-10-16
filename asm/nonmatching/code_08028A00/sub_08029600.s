	.syntax unified

	thumb_func_start sub_08029600
sub_08029600: @ 0x08029600
	push {r4, r5, r6, lr}
	movs r5, #0
	bl sub_0803836C
	ldr r4, _08029668 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r3, #0
	ldr r6, _0802966C @ =0x03000590
	mov ip, r4
	adds r1, #0x72
_08029622:
	mov r0, ip
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r3
	lsls r0, r0, #8
	adds r2, r0, r6
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029652
	adds r0, r2, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029652
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _08029652
	movs r5, #1
	adds r0, r3, r1
	strb r5, [r0]
_08029652:
	adds r3, #1
	cmp r3, #2
	bls _08029622
	cmp r5, #0
	bne _08029670
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08029678
	.align 2, 0
_08029668: .4byte 0x03001800
_0802966C: .4byte 0x03000590
_08029670:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #2
_08029678:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
