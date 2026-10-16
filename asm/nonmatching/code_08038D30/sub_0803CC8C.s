	.syntax unified

	thumb_func_start sub_0803CC8C
sub_0803CC8C: @ 0x0803CC8C
	push {r4, r5, r6, lr}
	ldr r4, _0803CCB0 @ =0x03002C30
	ldr r0, _0803CCB4 @ =0x03000440
	ldr r1, _0803CCB8 @ =0x0000012F
	adds r5, r0, r1
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r1, r0, r4
	adds r2, r1, #0
	adds r2, #0x2b
	ldrb r0, [r2]
	adds r3, r0, #0
	cmp r3, #0
	beq _0803CCBC
	subs r0, #1
	strb r0, [r2]
	b _0803CDB2
	.align 2, 0
_0803CCB0: .4byte 0x03002C30
_0803CCB4: .4byte 0x03000440
_0803CCB8: .4byte 0x0000012F
_0803CCBC:
	adds r2, r1, #0
	adds r2, #0x28
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	beq _0803CCD2
	adds r0, r1, #1
	strb r0, [r2]
	b _0803CDB2
_0803CCD2:
	strb r3, [r2]
	movs r0, #0xe
	movs r1, #0x10
	bl find_next_free_sprite_slot
	adds r6, r0, #0
	lsls r0, r6, #6
	adds r2, r0, r4
	movs r1, #0
	ldr r0, _0803CD18 @ =0x0000C404
	strh r0, [r2]
	strb r1, [r2, #0x1c]
	ldr r0, _0803CD1C @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803CD24
	ldrb r1, [r5]
	lsls r1, r1, #6
	adds r1, r1, r4
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r1, [r1, #0x30]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldr r3, _0803CD20 @ =0x000001FF
	adds r0, r3, #0
	ands r1, r0
	strh r1, [r2, #2]
	b _0803CD42
	.align 2, 0
_0803CD18: .4byte 0x0000C404
_0803CD1C: .4byte 0x03001800
_0803CD20: .4byte 0x000001FF
_0803CD24:
	ldrb r1, [r5]
	lsls r1, r1, #6
	adds r1, r1, r4
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrh r1, [r1, #0x30]
	ldrh r0, [r0, #2]
	subs r0, r0, r1
	ldr r3, _0803CDB8 @ =0x000001FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2, #2]
_0803CD42:
	ldr r3, _0803CDBC @ =0x03002C30
	lsls r2, r6, #6
	adds r2, r2, r3
	ldr r0, _0803CDC0 @ =0x03000440
	ldr r1, _0803CDC4 @ =0x0000012F
	adds r1, r1, r0
	mov ip, r1
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r3
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r1, #0x32]
	ldrh r0, [r0, #4]
	adds r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	strh r1, [r2, #4]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x27
	ldrb r0, [r0]
	strb r0, [r2, #0xa]
	movs r0, #0x80
	strb r0, [r2, #0xb]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #0x23
	strb r0, [r1]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r2, #0x2d
	strb r0, [r2]
	ldr r1, _0803CDC8 @ =0x083B5F80
	mov r2, ip
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_0803CDB2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803CDB8: .4byte 0x000001FF
_0803CDBC: .4byte 0x03002C30
_0803CDC0: .4byte 0x03000440
_0803CDC4: .4byte 0x0000012F
_0803CDC8: .4byte 0x083B5F80
	.syntax divided
