	.syntax unified

	thumb_func_start sub_08022990
sub_08022990: @ 0x08022990
	push {lr}
	ldr r0, _080229B8 @ =0x083B5F80
	adds r0, #0xf8
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	movs r0, #0x21
	bl move_sprite_toward_target
	cmp r0, #0
	beq _080229B2
	ldr r1, _080229BC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080229B2:
	pop {r0}
	bx r0
	.align 2, 0
_080229B8: .4byte 0x083B5F80
_080229BC: .4byte 0x03001800
	.syntax divided
