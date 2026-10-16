	.syntax unified

	thumb_func_start sub_080500D8
sub_080500D8: @ 0x080500D8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _08050118 @ =0x03002C30
	lsls r3, r0, #6
	adds r5, r3, r4
	movs r3, #0xf
	ands r3, r1
	adds r4, r5, #0
	adds r4, #0x27
	strb r3, [r4]
	lsrs r1, r1, #4
	adds r3, r5, #0
	adds r3, #0x20
	strb r1, [r3]
	adds r1, r5, #0
	adds r1, #0x2a
	strb r2, [r1]
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	adds r1, r5, #0
	adds r1, #0x28
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050118: .4byte 0x03002C30
	.syntax divided
