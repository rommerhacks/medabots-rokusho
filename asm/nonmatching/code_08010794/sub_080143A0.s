	.syntax unified

	thumb_func_start sub_080143A0
sub_080143A0: @ 0x080143A0
	push {r4, r5, lr}
	bl update_all_battle_status_sprites
	ldr r1, _080143E8 @ =0x03000590
	ldr r5, _080143EC @ =0x03001800
	adds r4, r5, #0
	adds r4, #0x87
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r2, #4
	eors r1, r2
	strb r1, [r0]
	bl iterate_bots_setup_battle_sprites
	bl sub_0801A678
	ldrb r0, [r4]
	bl sub_08015414
	bl sub_0801A6B0
	cmp r0, #0
	beq _080143F4
	adds r0, r5, #0
	adds r0, #0x45
	movs r1, #0xc
	movs r2, #0
	bl sub_0803F624
	ldr r1, _080143F0 @ =0x0300137C
	movs r0, #0x4c
	b _080143F8
	.align 2, 0
_080143E8: .4byte 0x03000590
_080143EC: .4byte 0x03001800
_080143F0: .4byte 0x0300137C
_080143F4:
	ldr r1, _08014400 @ =0x0300137C
	movs r0, #0x45
_080143F8:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014400: .4byte 0x0300137C
	.syntax divided
