	.syntax unified

	thumb_func_start update_battle_entity_status_chars
	.global update_battle_entity_status_chars
update_battle_entity_status_chars: @ 0x0804B164
	push {r4, r5, r6, r7, lr}
	ldr r1, _0804B19C @ =0x030057E0
	ldr r2, _0804B1A0 @ =0x00000C4C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804B1F6
	movs r3, #0x2e
	ldr r0, _0804B1A4 @ =0x03002C30
	adds r2, #0x24
	adds r6, r1, r2
	subs r2, #0x1c
	adds r5, r1, r2
	ldr r1, _0804B1A8 @ =0x00000C0B
	adds r4, r0, r1
	subs r1, #0x8b
	adds r2, r0, r1
	adds r1, #0x4b
	adds r1, r1, r0
	mov ip, r1
	ldr r1, _0804B1AC @ =0x0000164B
	adds r7, r0, r1
_0804B190:
	ldrb r1, [r2, #0xb]
	adds r0, r1, #0
	cmp r0, #0xff
	bne _0804B1B0
	movs r0, #0xff
	b _0804B1C6
	.align 2, 0
_0804B19C: .4byte 0x030057E0
_0804B1A0: .4byte 0x00000C4C
_0804B1A4: .4byte 0x03002C30
_0804B1A8: .4byte 0x00000C0B
_0804B1AC: .4byte 0x0000164B
_0804B1B0:
	cmp r0, #0
	beq _0804B1C6
	movs r0, #4
	ldrsh r1, [r2, r0]
	adds r0, r1, #0
	adds r0, #0x10
	cmp r0, #0
	bge _0804B1C2
	adds r0, #3
_0804B1C2:
	asrs r0, r0, #2
	adds r0, #0x40
_0804B1C6:
	strb r0, [r2, #0xb]
	cmp r3, #0x30
	bne _0804B1DC
	ldrh r0, [r6]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0804B1DC
	mov r1, ip
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r4]
_0804B1DC:
	cmp r3, #0x59
	bne _0804B1EE
	ldrh r0, [r6]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0804B1EE
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r7]
_0804B1EE:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #0x7f
	ble _0804B190
_0804B1F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
