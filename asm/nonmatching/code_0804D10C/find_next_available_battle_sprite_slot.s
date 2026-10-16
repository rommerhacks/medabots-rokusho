	.syntax unified

	thumb_func_start find_next_available_battle_sprite_slot
	.global find_next_available_battle_sprite_slot
find_next_available_battle_sprite_slot: @ 0x080506C4
	push {r4, lr}
	movs r4, #0
	ldr r2, _080506E4 @ =0x03002C30
	movs r1, #0x9e
	lsls r1, r1, #5
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080506EC
	ldr r1, _080506E8 @ =0x000013EE
	adds r0, r2, r1
	b _0805070A
	.align 2, 0
_080506E4: .4byte 0x03002C30
_080506E8: .4byte 0x000013EE
_080506EC:
	adds r4, #1
	cmp r4, #5
	bgt _08050710
	adds r0, r4, #0
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r3, r0, r2
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080506EC
	adds r0, r3, #0
	adds r0, #0x2e
_0805070A:
	ldrb r0, [r0]
	cmp r0, #0
	bne _080506EC
_08050710:
	cmp r4, #6
	beq _08050718
	adds r0, r4, #0
	b _0805071A
_08050718:
	movs r0, #5
_0805071A:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
