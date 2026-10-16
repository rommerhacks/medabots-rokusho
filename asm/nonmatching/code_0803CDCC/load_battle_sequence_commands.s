	.syntax unified

	thumb_func_start load_battle_sequence_commands
	.global load_battle_sequence_commands
load_battle_sequence_commands: @ 0x0803D450
	push {r4, r5, lr}
	ldr r1, _0803D4A0 @ =0x083CDFE4
	ldr r2, _0803D4A4 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r1, _0803D4A8 @ =0x083CE1F4
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r2, r0
	ldrh r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r1, #0
	cmp r1, r3
	bhs _0803D498
	movs r0, #0x81
	lsls r0, r0, #1
	adds r2, r2, r0
_0803D484:
	ldrh r0, [r5]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, r3
	blo _0803D484
_0803D498:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4A0: .4byte 0x083CDFE4
_0803D4A4: .4byte 0x03001800
_0803D4A8: .4byte 0x083CE1F4
	.syntax divided
