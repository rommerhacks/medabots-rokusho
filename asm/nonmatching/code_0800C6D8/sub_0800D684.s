	.syntax unified

	thumb_func_start sub_0800D684
sub_0800D684: @ 0x0800D684
	push {lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r1, _0800D6A4 @ =0x03000440
	adds r2, r1, #0
	adds r2, #0x39
	movs r0, #0
	strb r0, [r2]
	adds r1, #0x33
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800D6A4: .4byte 0x03000440
	.syntax divided
