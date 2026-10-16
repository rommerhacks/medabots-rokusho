	.syntax unified

	thumb_func_start serial_link_init_and_status
serial_link_init_and_status: @ 0x080021F4
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r6, _0800220C @ =0x04000128
	ldr r5, [r6]
	ldr r7, _08002210 @ =0x03005170
	ldrb r0, [r7, #1]
	cmp r0, #0
	beq _08002214
	cmp r0, #1
	beq _08002274
	b _0800227A
	.align 2, 0
_0800220C: .4byte 0x04000128
_08002210: .4byte 0x03005170
_08002214:
	movs r1, #0x30
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _08002274
	movs r0, #0x88
	adds r4, r5, #0
	ands r4, r0
	cmp r4, #8
	bne _0800227A
	movs r1, #4
	adds r0, r5, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0800226E
	ldr r0, [r7, #0x14]
	cmp r0, #6
	bne _0800226E
	ldr r3, _08002298 @ =0x04000208
	strh r1, [r3]
	ldr r2, _0800229C @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _080022A0 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldrb r1, [r6, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r6, #1]
	ldr r1, _080022A4 @ =0x0400010C
	ldr r0, _080022A8 @ =0x000063F7
	str r0, [r1]
	adds r1, #0xf6
	movs r0, #0xc0
	strh r0, [r1]
	strb r4, [r7]
_0800226E:
	ldr r1, _080022AC @ =0x03005170
	movs r0, #1
	strb r0, [r1, #1]
_08002274:
	mov r0, ip
	bl serial_link_receive_packets
_0800227A:
	ldr r1, _080022AC @ =0x03005170
	ldrb r0, [r1, #0xb]
	adds r0, #1
	strb r0, [r1, #0xb]
	ldrb r3, [r1, #3]
	ldrb r0, [r1, #2]
	lsls r2, r0, #8
	ldrb r0, [r1]
	cmp r0, #8
	bne _080022B0
	movs r0, #0x80
	orrs r0, r2
	orrs r0, r3
	b _080022B4
	.align 2, 0
_08002298: .4byte 0x04000208
_0800229C: .4byte 0x04000200
_080022A0: .4byte 0x0000FF7F
_080022A4: .4byte 0x0400010C
_080022A8: .4byte 0x000063F7
_080022AC: .4byte 0x03005170
_080022B0:
	adds r0, r3, #0
	orrs r0, r2
_080022B4:
	adds r2, r0, #0
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _080022C2
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
_080022C2:
	adds r1, r2, #0
	lsls r0, r5, #0x1a
	lsrs r0, r0, #0x1e
	cmp r0, #3
	bls _080022D2
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
_080022D2:
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
