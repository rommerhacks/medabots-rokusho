	.syntax unified

	thumb_func_start sub_08018C38
	.global sub_08018C38
sub_08018C38: @ 0x08018C38
	push {lr}
	ldr r2, _08018C70 @ =0x03001800
	adds r3, r2, #0
	adds r3, #0x56
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r3]
	cmp r0, #0
	bne _08018C6A
	adds r1, r2, #0
	adds r1, #0x57
	ldrb r0, [r1]
	cmp r0, #0
	beq _08018C6A
	subs r0, #1
	strb r0, [r1]
	ldr r0, _08018C74 @ =0x0000016B
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bl sub_08018CBC
_08018C6A:
	pop {r0}
	bx r0
	.align 2, 0
_08018C70: .4byte 0x03001800
_08018C74: .4byte 0x0000016B
	.syntax divided
