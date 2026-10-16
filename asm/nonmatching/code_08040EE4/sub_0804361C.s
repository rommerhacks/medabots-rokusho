	.syntax unified

	thumb_func_start sub_0804361C
	.global sub_0804361C
sub_0804361C: @ 0x0804361C
	sub sp, #8
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _08043664
	ldr r0, [sp]
	cmp r0, #0
	beq _080436A4
	ldr r2, _08043660 @ =0x03000BE0
	adds r3, r2, #0
_08043632:
	ldr r0, [sp]
	subs r0, #1
	str r0, [sp]
	ldr r0, [sp]
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08043658
	ldr r0, [sp]
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804369C
_08043658:
	ldr r0, [sp]
	cmp r0, #0
	bne _08043632
	b _080436A4
	.align 2, 0
_08043660: .4byte 0x03000BE0
_08043664:
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	ldr r0, [sp]
	cmp r0, #0x1f
	bne _08043674
	movs r0, #0
	str r0, [sp]
_08043674:
	ldr r0, [sp]
	cmp r0, #0x1e
	beq _080436A4
	ldr r2, _080436A0 @ =0x03000BE0
	ldr r0, [sp]
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08043664
	ldr r0, [sp]
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08043664
_0804369C:
	ldr r0, [sp]
	b _080436A6
	.align 2, 0
_080436A0: .4byte 0x03000BE0
_080436A4:
	movs r0, #0x1e
_080436A6:
	add sp, #8
	bx lr
	.align 2, 0
	.syntax divided
