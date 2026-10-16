	.syntax unified

	thumb_func_start sub_08070EB8
sub_08070EB8: @ 0x08070EB8
	push {lr}
	movs r0, #4
	bl play_song
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl sub_08071C40
	movs r0, #2
	movs r1, #0xb
	movs r2, #0
	bl sub_08071C40
	ldr r1, _08070EE0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08070EE0: .4byte 0x0300137C
	.syntax divided
