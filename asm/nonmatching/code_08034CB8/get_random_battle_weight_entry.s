	.syntax unified

	thumb_func_start get_random_battle_weight_entry
	.global get_random_battle_weight_entry
get_random_battle_weight_entry: @ 0x0803556C
	push {r4, r5, lr}
	ldr r5, _0803558C @ =0x083AF330
	bl sub_08035590
	adds r4, r0, #0
	bl rng_next_080424B8
	lsls r4, r4, #3
	movs r1, #7
	ands r1, r0
	adds r4, r4, r1
	adds r4, r4, r5
	ldrb r0, [r4]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0803558C: .4byte 0x083AF330
	.syntax divided
