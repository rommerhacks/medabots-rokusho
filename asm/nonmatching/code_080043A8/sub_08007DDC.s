	.syntax unified

	thumb_func_start sub_08007DDC
sub_08007DDC: @ 0x08007DDC
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _08007DFC @ =0x03000440
	adds r0, #0x42
	ldrb r0, [r0]
	cmp r0, #1
	beq _08007E10
	cmp r0, #1
	bgt _08007E00
	cmp r0, #0
	beq _08007E06
	b _08007E28
	.align 2, 0
_08007DFC: .4byte 0x03000440
_08007E00:
	cmp r0, #2
	beq _08007E1C
	b _08007E28
_08007E06:
	ldr r1, _08007E0C @ =0x0300137C
	movs r0, #8
	b _08007E2C
	.align 2, 0
_08007E0C: .4byte 0x0300137C
_08007E10:
	ldr r1, _08007E18 @ =0x0300137C
	movs r0, #0x18
	b _08007E2C
	.align 2, 0
_08007E18: .4byte 0x0300137C
_08007E1C:
	ldr r1, _08007E24 @ =0x0300137C
	movs r0, #0x28
	b _08007E2C
	.align 2, 0
_08007E24: .4byte 0x0300137C
_08007E28:
	ldr r1, _08007E34 @ =0x0300137C
	movs r0, #0x38
_08007E2C:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08007E34: .4byte 0x0300137C
	.syntax divided
