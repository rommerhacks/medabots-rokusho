	.syntax unified

	thumb_func_start sub_08021608
sub_08021608: @ 0x08021608
	push {lr}
	movs r1, #0x40
	rsbs r1, r1, #0
	movs r2, #0x30
	rsbs r2, r2, #0
	movs r0, #0x21
	bl update_sprite_deceleration
	cmp r0, #0
	beq _0802162E
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08021634 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802162E:
	pop {r0}
	bx r0
	.align 2, 0
_08021634: .4byte 0x03001800
	.syntax divided
