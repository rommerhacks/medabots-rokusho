	.syntax unified

	thumb_func_start load_part_data
	.global load_part_data
load_part_data: @ 0x08042B58
	push {r4, lr}
	adds r3, r2, #0
	movs r4, #0
	ldr r2, _08042B7C @ =0x083B827C
	lsls r0, r0, #6
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r0, r2
_08042B68:
	ldrb r0, [r1]
	strb r0, [r3]
	adds r3, #1
	adds r1, #1
	adds r4, #1
	cmp r4, #0xf
	bls _08042B68
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08042B7C: .4byte 0x083B827C
	.syntax divided
