	.syntax unified

	thumb_func_start advance_text_display
	.global advance_text_display
advance_text_display: @ 0x08044A3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r1, _08044AF4 @ =0x0807E77C
	ldr r0, _08044AF8 @ =0x083CABF8
	adds r2, r2, r0
	lsls r0, r4, #3
	subs r0, r0, r4
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	movs r6, #0
	ldr r1, _08044AFC @ =0x083D1E98
	lsls r0, r4, #2
	adds r2, r0, r1
	ldr r0, [r2]
	ldrb r0, [r0]
	mov sb, r1
	cmp r0, #0
	beq _08044A82
	adds r1, r2, #0
_08044A72:
	adds r6, #1
	cmp r6, #0xfe
	bhi _08044A82
	ldr r0, [r1]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _08044A72
_08044A82:
	ldr r0, _08044B00 @ =0x020260CC
	adds r7, r3, r0
	ldrb r0, [r7]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	strb r0, [r7]
	ldr r1, _08044B04 @ =0x02026000
	ldr r2, _08044B08 @ =0x020260CE
	adds r5, r3, r2
	ldrb r0, [r5]
	cmp r0, r6
	bhs _08044AD4
	lsls r0, r3, #6
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r2, #2
	adds r0, r0, r2
	str r0, [r1, #8]
	ldr r1, _08044B0C @ =0x083D1CC0
	lsls r3, r4, #2
	adds r1, r3, r1
	ldr r1, [r1]
	ldr r2, _08044B10 @ =0x083D1DAC
	adds r2, r3, r2
	ldr r2, [r2]
	add r3, sb
	ldr r3, [r3]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	ldrb r4, [r7]
	str r4, [sp, #4]
	ldrb r4, [r5]
	str r4, [sp, #8]
	movs r4, #0x40
	str r4, [sp, #0xc]
	str r6, [sp, #0x10]
	bl interpolate_entity_positions
	mov ip, r0
_08044AD4:
	mov r0, ip
	cmp r0, #0
	beq _08044B18
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r6
	blo _08044B14
	mov r1, r8
	strb r1, [r5]
	strb r1, [r7]
	movs r0, #1
	b _08044B1A
	.align 2, 0
_08044AF4: .4byte 0x0807E77C
_08044AF8: .4byte 0x083CABF8
_08044AFC: .4byte 0x083D1E98
_08044B00: .4byte 0x020260CC
_08044B04: .4byte 0x02026000
_08044B08: .4byte 0x020260CE
_08044B0C: .4byte 0x083D1CC0
_08044B10: .4byte 0x083D1DAC
_08044B14:
	mov r2, r8
	strb r2, [r7]
_08044B18:
	movs r0, #0
_08044B1A:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
