	.syntax unified

	thumb_func_start sub_08012BE4
sub_08012BE4: @ 0x08012BE4
	push {lr}
	bl update_all_battle_status_sprites
	ldr r0, _08012C04 @ =0x03001800
	adds r0, #0x80
	ldrb r0, [r0]
	bl sub_08016438
	cmp r0, #0
	beq _08012C00
	ldr r1, _08012C08 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08012C00:
	pop {r0}
	bx r0
	.align 2, 0
_08012C04: .4byte 0x03001800
_08012C08: .4byte 0x0300137C
	.syntax divided
