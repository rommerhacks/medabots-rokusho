	.syntax unified

	thumb_func_start set_random_battle_formation
set_random_battle_formation: @ 0x080156D0
	push {lr}
	bl rng_next_080424B8
	adds r1, r0, #0
	movs r0, #0x1f
	ands r0, r1
	lsls r0, r0, #2
	ldr r1, _080156F0 @ =0x083AD2F0
	adds r0, r0, r1
	ldr r1, _080156F4 @ =0x03001864
	movs r2, #4
	bl memcpy_bytes_08041D04
	pop {r0}
	bx r0
	.align 2, 0
_080156F0: .4byte 0x083AD2F0
_080156F4: .4byte 0x03001864
	.syntax divided
