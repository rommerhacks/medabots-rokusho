	.syntax unified

	thumb_func_start sub_08035BD4
	.global sub_08035BD4
sub_08035BD4: @ 0x08035BD4
	push {r4, lr}
	ldr r0, _08035BF8 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0xec
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #2
	bgt _08035BF2
	bl rng_next_080424B8
	movs r1, #3
	ands r0, r1
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
_08035BF2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08035BF8: .4byte 0x03001800
	.syntax divided
