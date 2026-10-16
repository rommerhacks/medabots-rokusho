	.syntax unified

	thumb_func_start sub_080189EC
	.global sub_080189EC
sub_080189EC: @ 0x080189EC
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _08018A14 @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_080189F6:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08018A02
	adds r0, r4, #0
	bl sub_08018900
_08018A02:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	bls _080189F6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08018A14: .4byte 0x03000590
	.syntax divided
