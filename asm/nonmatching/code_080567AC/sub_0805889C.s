	.syntax unified

	thumb_func_start sub_0805889C
sub_0805889C: @ 0x0805889C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, _08058900 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	adds r5, r2, #0
	cmp r0, #0
	beq _080588CE
	ldr r2, _08058904 @ =0x030057A0
	ldrb r1, [r2, #0x14]
	adds r3, r2, #0
	adds r3, #0x16
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r2, #0x14]
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _080588CE
	subs r0, r4, #1
	strb r0, [r1]
_080588CE:
	ldrb r1, [r5]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080588F8
	ldr r2, _08058904 @ =0x030057A0
	ldrb r1, [r2, #0x14]
	adds r3, r2, #0
	adds r3, #0x16
	adds r1, r1, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r2, #0x14]
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r4
	blt _080588F8
	movs r0, #0
	strb r0, [r1]
_080588F8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08058900: .4byte 0x03001798
_08058904: .4byte 0x030057A0
	.syntax divided
