	.syntax unified

	thumb_func_start battle_advance_sequence_counter
	.global battle_advance_sequence_counter
battle_advance_sequence_counter: @ 0x0803D4AC
	push {r4, lr}
	ldr r1, _0803D4E0 @ =0x083CDFE4
	ldr r3, _0803D4E4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf9
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r4, _0803D4E8 @ =0x083CE1F4
	movs r0, #0x80
	lsls r0, r0, #1
	adds r3, r3, r0
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, r0, r4
	adds r1, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	strh r1, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4E0: .4byte 0x083CDFE4
_0803D4E4: .4byte 0x03001800
_0803D4E8: .4byte 0x083CE1F4
	.syntax divided
