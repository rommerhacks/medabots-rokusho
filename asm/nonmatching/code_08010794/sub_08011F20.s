	.syntax unified

	thumb_func_start sub_08011F20
sub_08011F20: @ 0x08011F20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r6, r3, #0
	bl sub_08043C94
	cmp r0, #0x27
	bhi _08011F36
	adds r0, r4, #0
	b _08011F48
_08011F36:
	cmp r0, #0x45
	bhi _08011F3E
	adds r0, r5, #0
	b _08011F48
_08011F3E:
	cmp r0, #0x59
	bls _08011F46
	adds r0, r6, #0
	b _08011F48
_08011F46:
	adds r0, r7, #0
_08011F48:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
