	.syntax unified

	thumb_func_start sub_08008478
sub_08008478: @ 0x08008478
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _0800849C @ =0x083B53F8
	ldr r0, [r0, #0x30]
	bl run_message
	cmp r0, #0
	beq _08008496
	ldr r1, _080084A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08008496:
	pop {r0}
	bx r0
	.align 2, 0
_0800849C: .4byte 0x083B53F8
_080084A0: .4byte 0x0300137C
	.syntax divided
