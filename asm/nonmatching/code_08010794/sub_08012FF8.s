	.syntax unified

	thumb_func_start sub_08012FF8
sub_08012FF8: @ 0x08012FF8
	push {lr}
	bl update_all_battle_status_sprites
	ldr r0, _08013020 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08018900
	movs r0, #0
	bl init_battle_action_select_ui
	ldr r0, _08013024 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801302C
	ldr r1, _08013028 @ =0x0300137C
	movs r0, #0x45
	b _08013030
	.align 2, 0
_08013020: .4byte 0x03001800
_08013024: .4byte 0x03000440
_08013028: .4byte 0x0300137C
_0801302C:
	ldr r1, _08013038 @ =0x0300137C
	movs r0, #0xa0
_08013030:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08013038: .4byte 0x0300137C
	.syntax divided
