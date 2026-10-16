	.syntax unified

	thumb_func_start sub_08047F70
	.global sub_08047F70
sub_08047F70: @ 0x08047F70
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r4, #0
	movs r3, #0
	ldr r2, _08047FB0 @ =0x030017A0
_08047F7C:
	ldrb r0, [r2]
	cmp r0, #3
	bne _08047F9C
	ldrb r0, [r2, #3]
	cmp r0, r1
	bne _08047F9C
	ldrb r0, [r2, #4]
	cmp r0, r1
	bne _08047F9C
	ldrb r0, [r2, #5]
	cmp r0, r1
	bne _08047F9C
	ldrb r0, [r2, #6]
	cmp r0, r1
	bne _08047F9C
	movs r4, #1
_08047F9C:
	cmp r4, #0
	bne _08047FA8
	adds r2, #8
	adds r3, #1
	cmp r3, #8
	ble _08047F7C
_08047FA8:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08047FB0: .4byte 0x030017A0
	.syntax divided
