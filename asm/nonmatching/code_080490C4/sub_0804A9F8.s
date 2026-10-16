	.syntax unified

	thumb_func_start sub_0804A9F8
sub_0804A9F8: @ 0x0804A9F8
	push {lr}
	ldr r0, _0804AA1C @ =0x030057E0
	ldr r1, _0804AA20 @ =0x00000C5C
	adds r2, r0, r1
	ldr r3, _0804AA24 @ =0x00000C69
	adds r1, r0, r3
	ldrb r0, [r2]
	ldrb r3, [r1]
	cmp r0, r3
	bne _0804AA10
	movs r0, #0
	strb r0, [r2]
_0804AA10:
	strb r0, [r1]
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_0804AA1C: .4byte 0x030057E0
_0804AA20: .4byte 0x00000C5C
_0804AA24: .4byte 0x00000C69
	.syntax divided
