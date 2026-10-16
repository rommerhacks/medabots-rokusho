	.syntax unified

	thumb_func_start sub_08034910
sub_08034910: @ 0x08034910
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r0, _08034964 @ =0x03001800
	mov ip, r0
	ldr r6, _08034968 @ =0x03000590
	mov r5, ip
	adds r5, #0x87
	mov r4, ip
	adds r4, #0xec
	movs r2, #0
_08034924:
	lsls r1, r3, #1
	mov r0, ip
	adds r0, #0xd6
	adds r1, r1, r0
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r2, r0
	adds r0, r0, r6
	adds r0, #0x59
	ldrb r0, [r0]
	lsrs r0, r0, #1
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r2, r0
	adds r0, r0, r6
	adds r0, #0x59
	ldrb r0, [r0]
	lsrs r0, r0, #1
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r2, #0x18
	adds r3, #1
	cmp r3, #3
	bls _08034924
	bl sub_08034F08
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08034964: .4byte 0x03001800
_08034968: .4byte 0x03000590
	.syntax divided
