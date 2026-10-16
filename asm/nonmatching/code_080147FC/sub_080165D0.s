	.syntax unified

	thumb_func_start sub_080165D0
	.global sub_080165D0
sub_080165D0: @ 0x080165D0
	push {r4, lr}
	movs r4, #0
_080165D4:
	ldr r0, _080165EC @ =0x03002C30
	lsls r1, r4, #6
	adds r1, r1, r0
	ldrb r0, [r1, #9]
	cmp r0, #1
	bne _080165F0
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_sprite_table_mask
	b _08016606
	.align 2, 0
_080165EC: .4byte 0x03002C30
_080165F0:
	ldrb r0, [r1, #9]
	subs r0, #8
	cmp r0, #0
	bgt _080165FE
	movs r0, #1
	strb r0, [r1, #9]
	b _08016604
_080165FE:
	strb r0, [r1, #9]
	ldrb r0, [r1, #8]
	subs r0, #8
_08016604:
	strb r0, [r1, #8]
_08016606:
	adds r4, #1
	cmp r4, #5
	bls _080165D4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
