	.syntax unified

	thumb_func_start sub_08053418
sub_08053418: @ 0x08053418
	push {r4, r5, r6, lr}
	bl sub_0805378C
	ldr r6, _0805346C @ =0x03005350
	adds r5, r6, #0
	adds r5, #0xa4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, _08053470 @ =0x03004C30
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	subs r0, r0, r1
	subs r0, #0x70
	bl softfloat_int_to_double
	str r0, [r5]
	str r1, [r5, #4]
	adds r5, #8
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #2
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	subs r0, r0, r1
	subs r0, #0x50
	bl softfloat_int_to_double
	str r0, [r5]
	str r1, [r5, #4]
	ldr r0, _08053474 @ =0x03006D30
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	bl sub_080496C8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805346C: .4byte 0x03005350
_08053470: .4byte 0x03004C30
_08053474: .4byte 0x03006D30
	.syntax divided
