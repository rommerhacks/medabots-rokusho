	.syntax unified

	thumb_func_start sub_0801922C
sub_0801922C: @ 0x0801922C
	push {lr}
	adds r3, r0, #0
	ldr r1, _08019260 @ =0x03000590
	lsls r0, r3, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r1, r0, #0
	cmp r1, #0
	beq _0801925C
	subs r0, #0x11
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08019250
	cmp r1, #0x29
	bne _0801925C
_08019250:
	adds r0, r2, #0
	adds r0, #0xcc
	ldrb r1, [r0]
	adds r0, r3, #0
	bl sub_08019184
_0801925C:
	pop {r0}
	bx r0
	.align 2, 0
_08019260: .4byte 0x03000590
	.syntax divided
