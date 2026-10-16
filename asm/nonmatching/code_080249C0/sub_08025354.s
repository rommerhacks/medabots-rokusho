	.syntax unified

	thumb_func_start sub_08025354
sub_08025354: @ 0x08025354
	push {lr}
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _0802536A
	ldr r1, _08025374 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802536A:
	movs r0, #0x21
	bl sub_08037424
	pop {r0}
	bx r0
	.align 2, 0
_08025374: .4byte 0x03001800
	.syntax divided
