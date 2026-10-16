	.syntax unified

	thumb_func_start sub_08014B34
sub_08014B34: @ 0x08014B34
	push {r4, r5, r6, r7, lr}
	ldr r0, _08014C10 @ =0x03001800
	adds r5, r0, #0
	adds r5, #0x51
	ldrb r6, [r5]
	adds r4, r0, #0
	cmp r6, #3
	beq _08014B90
	ldr r3, _08014C14 @ =0x03005010
	ldr r1, _08014C18 @ =0x03000590
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xdd
	ldrb r2, [r0]
	ldr r0, _08014C1C @ =0x000001AF
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r7, #0x80
	lsls r7, r7, #1
	adds r1, r7, #0
	ands r0, r1
	ldr r7, _08014C20 @ =0xFFFF8000
	adds r1, r7, #0
	adds r0, r0, r1
	adds r2, r2, r0
	strh r2, [r3, #6]
	ldr r1, _08014C24 @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08014B90
	mov r1, ip
	ldrb r0, [r1]
	movs r1, #1
	eors r0, r1
	mov r3, ip
	strb r0, [r3]
	adds r0, r6, #1
	strb r0, [r5]
_08014B90:
	movs r7, #0x53
	adds r7, r7, r4
	ldrb r0, [r7]
	cmp r0, #3
	beq _08014BE4
	ldr r1, _08014C14 @ =0x03005010
	ldr r0, _08014C28 @ =0x03000B90
	ldrb r0, [r0]
	movs r5, #1
	eors r0, r5
	lsls r0, r0, #2
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08014BE4
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrb r1, [r3]
	lsrs r0, r0, #0x18
	cmp r0, r1
	beq _08014BE4
	eors r1, r5
	strb r1, [r3]
	ldr r0, _08014C18 @ =0x03000590
	ldrb r1, [r7]
	adds r1, #3
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r1, #0xdd
	strb r2, [r1]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
_08014BE4:
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	bne _08014C08
	adds r0, r4, #0
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #3
	bne _08014C08
	ldr r1, _08014C2C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _08014C24 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
_08014C08:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014C10: .4byte 0x03001800
_08014C14: .4byte 0x03005010
_08014C18: .4byte 0x03000590
_08014C1C: .4byte 0x000001AF
_08014C20: .4byte 0xFFFF8000
_08014C24: .4byte 0x03000440
_08014C28: .4byte 0x03000B90
_08014C2C: .4byte 0x0300137C
	.syntax divided
