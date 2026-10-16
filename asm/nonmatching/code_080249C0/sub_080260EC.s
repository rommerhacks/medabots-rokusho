	.syntax unified

	thumb_func_start sub_080260EC
sub_080260EC: @ 0x080260EC
	push {lr}
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _08026104 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08026104: .4byte 0x03001800
	.syntax divided
