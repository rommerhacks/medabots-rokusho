	.syntax unified

	thumb_func_start sub_08019078
	.global sub_08019078
sub_08019078: @ 0x08019078
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _080190B4 @ =0x03000590
	adds r6, r0, #0
	adds r6, #0xc9
	adds r5, r0, #0
	adds r5, #0x40
_08019086:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801909E
	ldrb r0, [r6]
	subs r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0801909E
	adds r0, r4, #0
	bl sub_08019544
_0801909E:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _08019086
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080190B4: .4byte 0x03000590
	.syntax divided
