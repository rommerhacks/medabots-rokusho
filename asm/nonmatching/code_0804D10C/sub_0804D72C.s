	.syntax unified

	thumb_func_start sub_0804D72C
sub_0804D72C: @ 0x0804D72C
	push {r4, lr}
	ldr r4, _0804D75C @ =0x030064A0
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #2
	movs r1, #8
	bl sub_080496C8
	adds r0, r4, #0
	adds r0, #0xa
	movs r1, #8
	bl sub_080496C8
	adds r4, #0x12
	adds r0, r4, #0
	movs r1, #0x40
	bl sub_080496C8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804D75C: .4byte 0x030064A0
	.syntax divided
