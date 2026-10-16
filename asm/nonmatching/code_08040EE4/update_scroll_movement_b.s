	.syntax unified

	thumb_func_start update_scroll_movement_b
update_scroll_movement_b: @ 0x08043E78
	push {r4, lr}
	ldr r1, _08043ECC @ =0x03001800
	adds r4, r1, #0
	adds r4, #0x74
	ldrb r0, [r4]
	mov ip, r1
	cmp r0, #0
	bne _08043E8A
	b _08043F92
_08043E8A:
	mov r2, ip
	adds r2, #0x7a
	mov r0, ip
	adds r0, #0x76
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldrb r0, [r2]
	lsrs r0, r0, #2
	cmp r0, #0
	bne _08043EA4
	b _08043F92
_08043EA4:
	mov r3, ip
	adds r3, #0x7b
	strb r0, [r3]
	ldrb r0, [r2]
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	mov r0, ip
	adds r0, #0x75
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08043EE2
	ldrb r0, [r4]
	cmp r0, #1
	beq _08043ED0
	cmp r0, #2
	beq _08043ED8
	b _08043EE2
	.align 2, 0
_08043ECC: .4byte 0x03001800
_08043ED0:
	ldr r1, _08043ED4 @ =0x0300057C
	b _08043EDA
	.align 2, 0
_08043ED4: .4byte 0x0300057C
_08043ED8:
	ldr r1, _08043F00 @ =0x03001C04
_08043EDA:
	ldrh r0, [r1, #2]
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r1, #2]
_08043EE2:
	mov r0, ip
	adds r0, #0x75
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08043F1A
	mov r0, ip
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #1
	beq _08043F04
	cmp r0, #2
	beq _08043F0C
	b _08043F1A
	.align 2, 0
_08043F00: .4byte 0x03001C04
_08043F04:
	ldr r2, _08043F08 @ =0x0300057C
	b _08043F0E
	.align 2, 0
_08043F08: .4byte 0x0300057C
_08043F0C:
	ldr r2, _08043F38 @ =0x03001C04
_08043F0E:
	mov r0, ip
	adds r0, #0x7b
	ldrb r1, [r0]
	ldrh r0, [r2, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
_08043F1A:
	mov r0, ip
	adds r0, #0x75
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08043F52
	mov r0, ip
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #1
	beq _08043F3C
	cmp r0, #2
	beq _08043F44
	b _08043F52
	.align 2, 0
_08043F38: .4byte 0x03001C04
_08043F3C:
	ldr r1, _08043F40 @ =0x0300057C
	b _08043F46
	.align 2, 0
_08043F40: .4byte 0x0300057C
_08043F44:
	ldr r1, _08043F74 @ =0x03001C04
_08043F46:
	mov r2, ip
	adds r2, #0x7b
	ldrh r0, [r1]
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
_08043F52:
	mov r3, ip
	adds r0, r3, #0
	adds r0, #0x75
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08043F92
	adds r0, r3, #0
	adds r0, #0x74
	ldrb r0, [r0]
	cmp r0, #1
	beq _08043F78
	cmp r0, #2
	beq _08043F84
	b _08043F92
	.align 2, 0
_08043F74: .4byte 0x03001C04
_08043F78:
	ldr r2, _08043F80 @ =0x0300057C
	adds r0, r3, #0
	b _08043F88
	.align 2, 0
_08043F80: .4byte 0x0300057C
_08043F84:
	ldr r2, _08043F98 @ =0x03001C04
	mov r0, ip
_08043F88:
	adds r0, #0x7b
	ldrb r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
_08043F92:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08043F98: .4byte 0x03001C04
	.syntax divided
