	.syntax unified

	thumb_func_start sub_0803EC98
sub_0803EC98: @ 0x0803EC98
	push {r4, lr}
	bl sub_0803EC50
	ldr r2, _0803ECBC @ =0x03002C30
	adds r3, r2, #0
	adds r3, #0x84
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _0803ECC0 @ =0x03001800
	ldr r4, _0803ECC4 @ =0x000001A1
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	bgt _0803ECC8
	strh r0, [r3]
	movs r0, #1
	b _0803ECEA
	.align 2, 0
_0803ECBC: .4byte 0x03002C30
_0803ECC0: .4byte 0x03001800
_0803ECC4: .4byte 0x000001A1
_0803ECC8:
	adds r1, r2, #0
	adds r1, #0xa7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0803ECE8
	adds r1, r2, #0
	adds r1, #0xa4
	ldrb r0, [r1]
	cmp r0, #1
	beq _0803ECE8
	subs r0, #1
	strb r0, [r1]
_0803ECE8:
	movs r0, #0
_0803ECEA:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
