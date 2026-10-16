	.syntax unified

	thumb_func_start serial_link_receive_packets
serial_link_receive_packets: @ 0x08002328
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldr r0, _080023C8 @ =0x03005250
	movs r4, #0
	str r4, [sp]
	bl _call_via_r0
	lsls r0, r0, #0x18
	ldr r1, _080023CC @ =0x03005170
	strb r4, [r1, #3]
	cmp r0, #0
	beq _080023AA
	movs r5, #0
	add r0, sp, #4
	mov r8, r0
	adds r7, r1, #0
	movs r0, #1
	rsbs r0, r0, #0
	mov sl, r0
_08002358:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [r7, #0x2c]
	adds r1, r1, r0
	movs r4, #0
	movs r3, #0
	adds r6, r5, #1
	adds r2, r1, #0
_0800236A:
	ldrh r0, [r2]
	adds r4, r4, r0
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	bls _0800236A
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r4, r1, #4
	cmp r0, sl
	bne _08002396
	lsls r1, r5, #2
	add r1, sb
	adds r0, r4, #0
	ldr r2, _080023D0 @ =0x04000001
	bl CpuSet
	movs r0, #1
	lsls r0, r5
	ldrb r1, [r7, #3]
	orrs r0, r1
	strb r0, [r7, #3]
_08002396:
	movs r0, #0
	str r0, [sp, #4]
	mov r0, r8
	adds r1, r4, #0
	ldr r2, _080023D4 @ =0x05000001
	bl CpuSet
	adds r5, r6, #0
	cmp r5, #3
	ble _08002358
_080023AA:
	ldr r1, _080023CC @ =0x03005170
	ldrb r0, [r1, #2]
	ldrb r2, [r1, #3]
	orrs r0, r2
	strb r0, [r1, #2]
	ldrb r0, [r1, #3]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080023C8: .4byte 0x03005250
_080023CC: .4byte 0x03005170
_080023D0: .4byte 0x04000001
_080023D4: .4byte 0x05000001
	.syntax divided
