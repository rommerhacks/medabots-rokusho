	.syntax unified

	thumb_func_start sub_0803A760
sub_0803A760: @ 0x0803A760
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r2, _0803A798 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0803A7D4
	ldr r3, _0803A79C @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0x6b
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0803A7A0
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r2, r1
	b _0803A7A4
	.align 2, 0
_0803A798: .4byte 0x03001800
_0803A79C: .4byte 0x03002C30
_0803A7A0:
	adds r0, r2, #0
	adds r0, #0xa7
_0803A7A4:
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #1
	movs r4, #0x81
	lsls r4, r4, #1
	adds r1, r2, r4
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x6c
	strb r1, [r0]
	ldr r0, _0803A7D0 @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x70
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0x6d
	b _0803A82E
	.align 2, 0
_0803A7D0: .4byte 0x03001800
_0803A7D4:
	ldr r3, _0803A7FC @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xab
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0803A800
	movs r4, #0xb1
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	adds r0, #4
	lsls r0, r0, #1
	subs r4, #0x60
	b _0803A80E
	.align 2, 0
_0803A7FC: .4byte 0x03002C30
_0803A800:
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	adds r0, #4
	lsls r0, r0, #1
	movs r4, #0x81
	lsls r4, r4, #1
_0803A80E:
	adds r1, r2, r4
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xac
	strb r1, [r0]
	ldr r0, _0803A83C @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0xb0
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0xad
_0803A82E:
	movs r0, #1
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A83C: .4byte 0x03001800
	.syntax divided
