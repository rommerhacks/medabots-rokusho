	.syntax unified

	thumb_func_start sub_08039568
sub_08039568: @ 0x08039568
	push {lr}
	ldr r2, _08039584 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf6
	ldrb r0, [r0]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	cmp r1, #0
	beq _08039588
	adds r0, r2, #0
	adds r0, #0xfd
	strb r3, [r0]
	b _0803958E
	.align 2, 0
_08039584: .4byte 0x03001800
_08039588:
	adds r0, r2, #0
	adds r0, #0xfd
	strb r1, [r0]
_0803958E:
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
