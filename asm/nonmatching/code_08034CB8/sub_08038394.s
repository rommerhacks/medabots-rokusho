	.syntax unified

	thumb_func_start sub_08038394
	.global sub_08038394
sub_08038394: @ 0x08038394
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _080383BC
	ldr r1, _080383E4 @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	adds r2, r0, #0
	adds r2, #0xc9
	movs r1, #0
	strb r1, [r2]
	adds r2, #1
	strb r1, [r2]
	adds r2, #1
	strb r1, [r2]
	adds r0, #0xcc
	strb r1, [r0]
_080383BC:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _080383DE
	ldr r1, _080383E4 @ =0x03000590
	lsls r0, r4, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0xc4
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080383DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080383E4: .4byte 0x03000590
	.syntax divided
