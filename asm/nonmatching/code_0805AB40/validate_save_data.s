	.syntax unified

	thumb_func_start validate_save_data
validate_save_data: @ 0x0805DFD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #2
	mov r8, r0
	adds r4, r7, #0
	movs r6, #0
	mov r5, sp
_0805DFE6:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl ReadEepromDword
	ldrh r0, [r5]
	strh r0, [r4]
	adds r4, #2
	ldrh r0, [r5, #2]
	strh r0, [r4]
	adds r4, #2
	ldrh r0, [r5, #4]
	strh r0, [r4]
	adds r4, #2
	ldrh r0, [r5, #6]
	strh r0, [r4]
	adds r4, #2
	adds r6, #1
	cmp r6, r8
	blt _0805DFE6
	movs r6, #0
	ldr r2, _0805E0B0 @ =0x08483C20
_0805E012:
	adds r0, r6, r2
	adds r1, r7, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805E0CC
	adds r6, #1
	cmp r6, #0xf
	ble _0805E012
	movs r4, #1
	movs r6, #0
	ldrb r0, [r7, #0x14]
	cmp r0, #0xfe
	beq _0805E04A
	cmp r0, #0
	bne _0805E04E
_0805E032:
	adds r6, #1
	cmp r6, #0xf
	bgt _0805E04A
	adds r0, r7, #0
	adds r0, #0x14
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805E04A
	cmp r0, #0
	beq _0805E032
	movs r4, #0
_0805E04A:
	cmp r4, #0
	bne _0805E0D0
_0805E04E:
	ldr r1, [r7, #0x10]
	ldr r0, _0805E0B4 @ =0x0001869F
	cmp r1, r0
	bhi _0805E0D0
	ldrh r1, [r7, #0x24]
	ldr r0, _0805E0B8 @ =0x0000270F
	cmp r1, r0
	bhi _0805E0D0
	ldrh r0, [r7, #0x26]
	cmp r1, r0
	blo _0805E0D0
	ldr r1, [r7, #0x28]
	ldr r0, _0805E0BC @ =0x014996FF
	cmp r1, r0
	bhi _0805E0D0
	ldr r1, _0805E0C0 @ =0x00001CB8
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #2
	bhi _0805E0D0
	lsrs r0, r1, #3
	movs r1, #3
	ands r0, r1
	cmp r0, #2
	bhi _0805E0D0
	ldr r0, _0805E0C4 @ =0x00000FF4
	adds r1, r7, r0
	ldrh r4, [r1]
	movs r0, #0
	strh r0, [r1]
	movs r2, #0
	adds r1, r7, #0
	movs r6, #0
	ldr r3, _0805E0C8 @ =0x00001CBB
_0805E096:
	ldrb r0, [r1]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r1, #1
	adds r6, #1
	cmp r6, r3
	bls _0805E096
	cmp r2, r4
	bne _0805E0D0
	movs r0, #0
	b _0805E0D4
	.align 2, 0
_0805E0B0: .4byte 0x08483C20
_0805E0B4: .4byte 0x0001869F
_0805E0B8: .4byte 0x0000270F
_0805E0BC: .4byte 0x014996FF
_0805E0C0: .4byte 0x00001CB8
_0805E0C4: .4byte 0x00000FF4
_0805E0C8: .4byte 0x00001CBB
_0805E0CC:
	movs r0, #1
	b _0805E0D4
_0805E0D0:
	movs r0, #1
	rsbs r0, r0, #0
_0805E0D4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
