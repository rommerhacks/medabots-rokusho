	.syntax unified

	thumb_func_start sub_0805EE6C
sub_0805EE6C: @ 0x0805EE6C
	push {lr}
	movs r0, #7
	bl is_sound_playing_with_lock
	adds r1, r0, #0
	cmp r1, #0
	bne _0805EE88
	ldr r0, _0805EE8C @ =0x03000440
	adds r0, #0x84
	strb r1, [r0]
	ldr r1, _0805EE90 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805EE88:
	pop {r0}
	bx r0
	.align 2, 0
_0805EE8C: .4byte 0x03000440
_0805EE90: .4byte 0x0300137C
	.syntax divided
