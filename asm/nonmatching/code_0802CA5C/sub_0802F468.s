	.syntax unified

	thumb_func_start sub_0802F468
sub_0802F468: @ 0x0802F468
	push {lr}
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802F484
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _0802F488 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802F484:
	pop {r0}
	bx r0
	.align 2, 0
_0802F488: .4byte 0x03001800
	.syntax divided
