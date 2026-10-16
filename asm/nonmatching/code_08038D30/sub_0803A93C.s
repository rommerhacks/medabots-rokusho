	.syntax unified

	thumb_func_start sub_0803A93C
sub_0803A93C: @ 0x0803A93C
	push {r4, lr}
	bl load_battle_sequence_commands
	movs r3, #0
	ldr r0, _0803A954 @ =0x03002C30
	ldr r1, _0803A958 @ =0x00000329
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803A95C
	movs r4, #0xc
	b _0803A976
	.align 2, 0
_0803A954: .4byte 0x03002C30
_0803A958: .4byte 0x00000329
_0803A95C:
	adds r3, #1
	cmp r3, #1
	bhi _0803A976
	ldr r0, _0803A9F8 @ =0x03002C30
	adds r2, r3, #0
	adds r2, #0xc
	lsls r1, r2, #6
	adds r1, r1, r0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803A95C
	adds r4, r2, #0
_0803A976:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0803A9F8 @ =0x03002C30
	lsls r0, r4, #6
	adds r3, r0, r1
	ldr r0, _0803A9FC @ =0x03001800
	mov ip, r0
	movs r0, #0x81
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x2b
	strb r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, #3
	strb r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r2, #0
	strh r0, [r3, #0x30]
	movs r0, #0x84
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r3, #0x32]
	movs r0, #0x85
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x2d
	strb r0, [r1]
	movs r0, #0x87
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	subs r1, #6
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x28
	strb r2, [r0]
	adds r1, #2
	movs r0, #0x22
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A9F8: .4byte 0x03002C30
_0803A9FC: .4byte 0x03001800
	.syntax divided
