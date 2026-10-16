	.syntax unified

	thumb_func_start sub_0803A310
sub_0803A310: @ 0x0803A310
	push {lr}
	bl load_battle_sequence_commands
	ldr r3, _0803A368 @ =0x03001800
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _0803A36C @ =0x03002C30
	lsls r0, r0, #6
	adds r2, r0, r1
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	strb r0, [r2, #0xa]
	subs r1, #6
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x2d
	strb r0, [r1]
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x2b
	strb r0, [r1]
	subs r1, #2
	movs r0, #0x20
	strb r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x2e
	strb r1, [r0]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803A368: .4byte 0x03001800
_0803A36C: .4byte 0x03002C30
	.syntax divided
