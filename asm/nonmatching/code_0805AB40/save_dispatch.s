	.syntax unified

	thumb_func_start save_dispatch
	.global save_dispatch
save_dispatch: @ 0x0805DC84
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	str r5, [sp]
	ldr r6, _0805DCBC @ =0x02030000
	ldr r2, _0805DCC0 @ =0x0500072E
	mov r0, sp
	adds r1, r6, #0
	bl CpuSet
	ldr r2, _0805DCC4 @ =0x04000208
	strh r5, [r2]
	ldr r1, _0805DCC8 @ =0x04000200
	ldrh r0, [r1]
	adds r7, r0, #0
	ldr r3, _0805DCCC @ =0x00002020
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #1
	strh r0, [r2]
	cmp r4, #1
	beq _0805DCEC
	cmp r4, #1
	bgt _0805DCD0
	cmp r4, #0
	beq _0805DCD6
	b _0805DD26
	.align 2, 0
_0805DCBC: .4byte 0x02030000
_0805DCC0: .4byte 0x0500072E
_0805DCC4: .4byte 0x04000208
_0805DCC8: .4byte 0x04000200
_0805DCCC: .4byte 0x00002020
_0805DCD0:
	cmp r4, #2
	beq _0805DCFC
	b _0805DD26
_0805DCD6:
	ldr r0, _0805DCE8 @ =0x03001784
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	adds r0, r6, #0
	bl serialize_save_data
	b _0805DD1C
	.align 2, 0
_0805DCE8: .4byte 0x03001784
_0805DCEC:
	adds r0, r6, #0
	bl validate_save_data
	adds r5, r0, #0
	adds r0, r6, #0
	bl load_save_data
	b _0805DD26
_0805DCFC:
	ldr r2, _0805DD38 @ =0x03001784
	ldrb r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r2, #0
	adds r4, r6, #0
	ldr r3, _0805DD3C @ =0x08483C31
_0805DD0E:
	adds r0, r2, r4
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xf
	ble _0805DD0E
_0805DD1C:
	ldr r0, _0805DD40 @ =0x02030000
	movs r1, #0
	bl write_save_to_eeprom
	adds r5, r0, #0
_0805DD26:
	ldr r1, _0805DD44 @ =0x04000200
	ldrh r0, [r1]
	orrs r7, r0
	strh r7, [r1]
	adds r0, r5, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805DD38: .4byte 0x03001784
_0805DD3C: .4byte 0x08483C31
_0805DD40: .4byte 0x02030000
_0805DD44: .4byte 0x04000200
	.syntax divided
