	.syntax unified

	thumb_func_start serial_multiplayer_transfer_handler
serial_multiplayer_transfer_handler: @ 0x08002438
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _08002518 @ =0x04000120
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0800251C @ =0x03005170
	ldr r0, _08002520 @ =0x04000128
	ldr r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1f
	movs r5, #0
	strb r0, [r2, #7]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, _08002524 @ =0x0000FEFE
	adds r4, r2, #0
	cmp r1, r0
	bne _08002498
	ldr r0, [r4, #0x18]
	cmp r0, #3
	ble _08002498
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	str r0, [r4, #0x28]
	str r1, [r4, #0x24]
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _08002486
	ldr r1, [r4, #0x20]
	ldr r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	str r1, [r4, #0x1c]
	strb r5, [r4, #4]
	str r5, [r4, #0x14]
_08002486:
	ldr r3, _08002528 @ =0x04000208
	strh r5, [r3]
	ldr r2, _0800252C @ =0x03007FF8
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
_08002498:
	ldr r0, [r4, #0x14]
	cmp r0, #3
	bgt _080024AA
	ldr r2, _08002520 @ =0x04000128
	ldr r1, [r4, #0x20]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2, #2]
_080024AA:
	ldr r0, [r4, #0x14]
	cmp r0, #4
	bgt _080024B4
	adds r0, #1
	str r0, [r4, #0x14]
_080024B4:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	blt _080024DC
	ldr r1, [r4, #0x24]
	mov r2, sp
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r3, #3
_080024C4:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #0xc
	subs r3, #1
	cmp r3, #0
	bge _080024C4
	ldr r0, [r4, #0x18]
	cmp r0, #3
	bne _080024DC
	movs r0, #1
	strb r0, [r4, #5]
_080024DC:
	adds r1, r4, #0
	ldr r0, [r1, #0x18]
	cmp r0, #4
	bgt _080024E8
	adds r0, #1
	str r0, [r1, #0x18]
_080024E8:
	ldrb r2, [r1]
	cmp r2, #0
	beq _080024F4
	ldr r1, _08002530 @ =0x0400010E
	movs r0, #0
	strh r0, [r1]
_080024F4:
	ldr r0, [r4, #0x14]
	cmp r0, #4
	bgt _0800250E
	cmp r2, #0
	beq _0800250E
	ldr r2, _08002520 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08002530 @ =0x0400010E
	movs r0, #0xc0
	strh r0, [r1]
_0800250E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002518: .4byte 0x04000120
_0800251C: .4byte 0x03005170
_08002520: .4byte 0x04000128
_08002524: .4byte 0x0000FEFE
_08002528: .4byte 0x04000208
_0800252C: .4byte 0x03007FF8
_08002530: .4byte 0x0400010E
	.syntax divided
