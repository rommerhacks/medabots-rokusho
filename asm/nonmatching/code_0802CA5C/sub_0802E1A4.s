	.syntax unified

	thumb_func_start sub_0802E1A4
sub_0802E1A4: @ 0x0802E1A4
	push {lr}
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _0802E1C4 @ =0x03001800
	adds r2, r1, #0
	adds r2, #0xa6
	movs r0, #0x43
	strb r0, [r2]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802E1C4: .4byte 0x03001800
	.syntax divided
