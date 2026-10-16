	.syntax unified

	thumb_func_start sub_08012BC0
sub_08012BC0: @ 0x08012BC0
	push {lr}
	bl update_all_battle_status_sprites
	ldr r0, _08012BDC @ =0x03001800
	adds r0, #0x80
	ldrb r0, [r0]
	bl sub_08016370
	ldr r1, _08012BE0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08012BDC: .4byte 0x03001800
_08012BE0: .4byte 0x0300137C
	.syntax divided
