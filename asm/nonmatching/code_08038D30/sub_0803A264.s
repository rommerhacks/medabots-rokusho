	.syntax unified

	thumb_func_start sub_0803A264
sub_0803A264: @ 0x0803A264
	push {lr}
	bl load_battle_sequence_commands
	ldr r3, _0803A2A4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803A2AC
	ldr r1, _0803A2A8 @ =0x03002C30
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r0, r0, r1
	movs r1, #0x81
	lsls r1, r1, #1
	adds r2, r3, r1
	movs r3, #2
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	blt _0803A2D6
	bl battle_advance_sequence_counter
	b _0803A2D6
	.align 2, 0
_0803A2A4: .4byte 0x03001800
_0803A2A8: .4byte 0x03002C30
_0803A2AC:
	ldr r1, _0803A2E4 @ =0x03002C30
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	adds r0, r0, r1
	movs r1, #2
	ldrsh r2, [r0, r1]
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xf0
	subs r0, r0, r1
	cmp r2, r0
	bgt _0803A2D6
	bl battle_advance_sequence_counter
_0803A2D6:
	ldr r0, _0803A2E4 @ =0x03002C30
	adds r0, #0x2a
	movs r1, #1
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0803A2E4: .4byte 0x03002C30
	.syntax divided
