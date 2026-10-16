	.syntax unified

	thumb_func_start sub_08039540
sub_08039540: @ 0x08039540
	push {lr}
	ldr r0, _08039554 @ =0x03001800
	adds r2, r0, #0
	adds r2, #0xb7
	ldrb r2, [r2]
	cmp r2, #1
	bne _08039558
	adds r0, #0xfd
	strb r2, [r0]
	b _08039560
	.align 2, 0
_08039554: .4byte 0x03001800
_08039558:
	adds r1, r0, #0
	adds r1, #0xfd
	movs r0, #0
	strb r0, [r1]
_08039560:
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.syntax divided
