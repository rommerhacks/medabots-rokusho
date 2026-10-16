	.syntax unified

	thumb_func_start sub_08039598
sub_08039598: @ 0x08039598
	push {lr}
	ldr r1, _080395AC @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #2
	bne _080395B0
	adds r1, #0xfd
	movs r0, #1
	b _080395B4
	.align 2, 0
_080395AC: .4byte 0x03001800
_080395B0:
	adds r1, #0xfd
	movs r0, #0
_080395B4:
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
