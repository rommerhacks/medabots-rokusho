	.syntax unified

	thumb_func_start sub_08004AF8
sub_08004AF8: @ 0x08004AF8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl medabots_scroll_bg3
	bl setup_overworld_scene_from_position
	ldr r0, _08004C30 @ =0x03001800
	mov ip, r0
	mov r6, ip
	adds r6, #0x51
	ldrb r1, [r6]
	mov r8, r1
	mov r3, r8
	cmp r3, #3
	beq _08004B7E
	ldrb r0, [r6]
	lsls r0, r0, #8
	ldr r1, _08004C34 @ =0x03000590
	ldr r3, _08004C38 @ =0x03005010
	mov r5, ip
	adds r5, #0x52
	adds r0, r0, r1
	ldrb r7, [r5]
	adds r0, r0, r7
	ldrb r2, [r0]
	ldr r4, _08004C3C @ =0x000001AF
	add r4, ip
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r7, #0x80
	lsls r7, r7, #1
	adds r1, r7, #0
	ands r0, r1
	ldr r7, _08004C40 @ =0xFFFF8000
	adds r1, r7, #0
	adds r0, r0, r1
	adds r2, r2, r0
	strh r2, [r3, #6]
	ldr r0, _08004C44 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _08004B7E
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4]
	movs r1, #1
	eors r0, r1
	strb r0, [r4]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x48
	bne _08004B7E
	mov r0, r8
	adds r0, #1
	strb r0, [r6]
	movs r0, #0
	strb r0, [r5]
_08004B7E:
	ldr r1, _08004C30 @ =0x03001800
	adds r5, r1, #0
	adds r5, #0x53
	ldrb r0, [r5]
	mov ip, r1
	cmp r0, #3
	beq _08004C02
	ldr r1, _08004C38 @ =0x03005010
	ldr r0, _08004C48 @ =0x03000B90
	ldrb r0, [r0]
	movs r4, #1
	eors r0, r4
	lsls r0, r0, #2
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r3
	cmp r0, #0
	beq _08004C02
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	lsls r0, r0, #0x10
	movs r2, #0xd8
	lsls r2, r2, #1
	add r2, ip
	ldrb r1, [r2]
	lsrs r0, r0, #0x18
	cmp r0, r1
	beq _08004C02
	eors r1, r4
	strb r1, [r2]
	ldrb r0, [r5]
	lsls r0, r0, #8
	ldr r1, _08004C4C @ =0x03000890
	mov r4, ip
	adds r4, #0x54
	adds r0, r0, r1
	ldrb r1, [r4]
	adds r0, r0, r1
	strb r3, [r0]
	movs r2, #0xd4
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0xff
	ands r3, r0
	ldrh r7, [r2]
	adds r0, r3, r7
	ldr r3, _08004C50 @ =0x00007FFF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x48
	bne _08004C02
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	movs r0, #0
	strb r0, [r4]
_08004C02:
	mov r0, ip
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	bne _08004C24
	mov r0, ip
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #3
	bne _08004C24
	ldr r1, _08004C54 @ =0x0300137C
	movs r0, #0x3a
	str r0, [r1]
	ldr r0, _08004C44 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
_08004C24:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004C30: .4byte 0x03001800
_08004C34: .4byte 0x03000590
_08004C38: .4byte 0x03005010
_08004C3C: .4byte 0x000001AF
_08004C40: .4byte 0xFFFF8000
_08004C44: .4byte 0x03000440
_08004C48: .4byte 0x03000B90
_08004C4C: .4byte 0x03000890
_08004C50: .4byte 0x00007FFF
_08004C54: .4byte 0x0300137C
	.syntax divided
