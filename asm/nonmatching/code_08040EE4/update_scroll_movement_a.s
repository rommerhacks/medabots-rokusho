	.syntax unified

	thumb_func_start update_scroll_movement_a
	.global update_scroll_movement_a
update_scroll_movement_a: @ 0x08043CD4
	push {r4, lr}
	ldr r1, _08043D28 @ =0x03001800
	adds r4, r1, #0
	adds r4, #0x39
	ldrb r0, [r4]
	mov ip, r1
	cmp r0, #0
	bne _08043CE6
	b _08043DEE
_08043CE6:
	mov r2, ip
	adds r2, #0x3f
	mov r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	cmp r0, #0
	bne _08043D00
	b _08043DEE
_08043D00:
	mov r3, ip
	adds r3, #0x40
	strb r0, [r3]
	ldrb r0, [r2]
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x3a
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08043D3E
	ldrb r0, [r4]
	cmp r0, #1
	beq _08043D2C
	cmp r0, #2
	beq _08043D34
	b _08043D3E
	.align 2, 0
_08043D28: .4byte 0x03001800
_08043D2C:
	ldr r1, _08043D30 @ =0x0300057C
	b _08043D36
	.align 2, 0
_08043D30: .4byte 0x0300057C
_08043D34:
	ldr r1, _08043D5C @ =0x03001C04
_08043D36:
	ldrh r0, [r1, #2]
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r1, #2]
_08043D3E:
	mov r0, ip
	adds r0, #0x3a
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08043D76
	mov r0, ip
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq _08043D60
	cmp r0, #2
	beq _08043D68
	b _08043D76
	.align 2, 0
_08043D5C: .4byte 0x03001C04
_08043D60:
	ldr r2, _08043D64 @ =0x0300057C
	b _08043D6A
	.align 2, 0
_08043D64: .4byte 0x0300057C
_08043D68:
	ldr r2, _08043D94 @ =0x03001C04
_08043D6A:
	mov r0, ip
	adds r0, #0x40
	ldrb r1, [r0]
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
_08043D76:
	mov r0, ip
	adds r0, #0x3a
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08043DAE
	mov r0, ip
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq _08043D98
	cmp r0, #2
	beq _08043DA0
	b _08043DAE
	.align 2, 0
_08043D94: .4byte 0x03001C04
_08043D98:
	ldr r2, _08043D9C @ =0x0300057C
	b _08043DA2
	.align 2, 0
_08043D9C: .4byte 0x0300057C
_08043DA0:
	ldr r2, _08043DD0 @ =0x03001C04
_08043DA2:
	mov r1, ip
	adds r1, #0x40
	ldrh r0, [r2]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
_08043DAE:
	mov r3, ip
	adds r0, r3, #0
	adds r0, #0x3a
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08043DEE
	adds r0, r3, #0
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #1
	beq _08043DD4
	cmp r0, #2
	beq _08043DE0
	b _08043DEE
	.align 2, 0
_08043DD0: .4byte 0x03001C04
_08043DD4:
	ldr r2, _08043DDC @ =0x0300057C
	adds r0, r3, #0
	b _08043DE4
	.align 2, 0
_08043DDC: .4byte 0x0300057C
_08043DE0:
	ldr r2, _08043DF4 @ =0x03001C04
	mov r0, ip
_08043DE4:
	adds r0, #0x40
	ldrb r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
_08043DEE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08043DF4: .4byte 0x03001C04
	.syntax divided
