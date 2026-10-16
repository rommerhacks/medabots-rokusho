	.syntax unified

	thumb_func_start sub_0803B328
sub_0803B328: @ 0x0803B328
	push {lr}
	bl load_battle_sequence_commands
	ldr r1, _0803B368 @ =0x03002C30
	ldr r2, _0803B36C @ =0x03001800
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r2, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #6
	adds r0, r0, r1
	movs r1, #0x81
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r0, #0x2e
	strb r1, [r0]
	ldr r1, _0803B370 @ =0x083CEC74
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	movs r2, #0
	bl sub_0801BF78
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803B368: .4byte 0x03002C30
_0803B36C: .4byte 0x03001800
_0803B370: .4byte 0x083CEC74
	.syntax divided
