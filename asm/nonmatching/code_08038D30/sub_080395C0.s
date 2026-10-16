	.syntax unified

	thumb_func_start sub_080395C0
sub_080395C0: @ 0x080395C0
	push {lr}
	ldr r1, _080395D4 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xb8
	ldrb r0, [r0]
	cmp r0, #4
	bne _080395D8
	adds r1, #0xfd
	movs r0, #1
	b _080395DC
	.align 2, 0
_080395D4: .4byte 0x03001800
_080395D8:
	adds r1, #0xfd
	movs r0, #0
_080395DC:
	strb r0, [r1]
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
