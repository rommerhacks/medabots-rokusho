	.syntax unified

	thumb_func_start sub_0802DB3C
sub_0802DB3C: @ 0x0802DB3C
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r7, _0802DB80 @ =0x03000440
	ldr r0, _0802DB84 @ =0x03001800
	mov ip, r0
	adds r6, r7, #0
	adds r6, #0x86
	ldr r4, _0802DB88 @ =0x03002C30
	mov r5, ip
	adds r5, #0x60
	movs r1, #0x84
	lsls r1, r1, #4
	adds r3, r4, r1
_0802DB56:
	mov r0, ip
	adds r0, #0xd2
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802DBA0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802DB8C
	ldrb r0, [r5]
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	subs r0, #2
	b _0802DB9E
	.align 2, 0
_0802DB80: .4byte 0x03000440
_0802DB84: .4byte 0x03001800
_0802DB88: .4byte 0x03002C30
_0802DB8C:
	ldrb r0, [r5]
	adds r0, r0, r2
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	adds r0, #2
_0802DB9E:
	strh r0, [r3, #2]
_0802DBA0:
	adds r3, #0x40
	adds r2, #1
	cmp r2, #2
	bls _0802DB56
	adds r1, r7, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x3c
	bne _0802DBCC
	movs r0, #0x21
	movs r1, #6
	bl clear_battle_sprite_slot
	ldr r1, _0802DBC8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802DBD0
	.align 2, 0
_0802DBC8: .4byte 0x03001800
_0802DBCC:
	adds r0, #1
	strh r0, [r1]
_0802DBD0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
