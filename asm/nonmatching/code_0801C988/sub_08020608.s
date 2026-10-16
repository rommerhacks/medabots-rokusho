	.syntax unified

	thumb_func_start sub_08020608
sub_08020608: @ 0x08020608
	push {lr}
	movs r0, #0x21
	movs r1, #4
	bl update_sprite_animations_tick_080370AC
	cmp r0, #0
	beq _08020620
	ldr r1, _08020624 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08020620:
	pop {r0}
	bx r0
	.align 2, 0
_08020624: .4byte 0x03001800
	.syntax divided
