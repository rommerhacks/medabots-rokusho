	.syntax unified

	thumb_func_start sub_080579C4
sub_080579C4: @ 0x080579C4
	push {r4, lr}
	ldr r0, _080579EC @ =0x030064A0
	adds r4, r0, #0
	adds r4, #0x65
	ldrb r0, [r4]
	cmp r0, #2
	beq _080579DA
	bl sub_0804B1FC
	bl sub_08057EBC
_080579DA:
	movs r0, #0x7f
	bl clear_battle_sprite_entry
	ldrb r0, [r4]
	cmp r0, #0
	bne _080579F0
	movs r0, #0x41
	b _080579F6
	.align 2, 0
_080579EC: .4byte 0x030064A0
_080579F0:
	cmp r0, #1
	bne _080579FE
	movs r0, #0x43
_080579F6:
	movs r1, #0
	bl sub_08047878
	b _08057A1C
_080579FE:
	cmp r0, #2
	bne _08057A10
	ldr r1, _08057A0C @ =0x0300137C
	movs r0, #5
	str r0, [r1]
	b _08057A1C
	.align 2, 0
_08057A0C: .4byte 0x0300137C
_08057A10:
	cmp r0, #3
	bne _08057A1C
	movs r0, #0x42
	movs r1, #0
	bl sub_08047878
_08057A1C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
