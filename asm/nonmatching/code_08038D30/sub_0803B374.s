	.syntax unified

	thumb_func_start sub_0803B374
sub_0803B374: @ 0x0803B374
	push {r4, lr}
	ldr r4, _0803B3A8 @ =0x03000590
	ldr r3, _0803B3AC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r1, r2, r4
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0803B3B0
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, #0x49
	ldrb r0, [r0]
	bl decompress_indexed_graphics_to_ewram
	b _0803B3BC
	.align 2, 0
_0803B3A8: .4byte 0x03000590
_0803B3AC: .4byte 0x03001800
_0803B3B0:
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
	bl decompress_indexed_graphics_to_ewram
_0803B3BC:
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
