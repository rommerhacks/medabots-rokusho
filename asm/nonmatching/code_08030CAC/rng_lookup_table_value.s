	.syntax unified

	thumb_func_start rng_lookup_table_value
	.global rng_lookup_table_value
rng_lookup_table_value: @ 0x08033074
	push {r4, lr}
	ldr r4, _0803308C @ =0x083AEF00
	bl rng_next_080424B8
	movs r1, #0xf
	ands r1, r0
	adds r1, r1, r4
	ldrb r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803308C: .4byte 0x083AEF00
	.syntax divided
