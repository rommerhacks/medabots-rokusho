	.syntax unified

	thumb_func_start sub_080239C0
sub_080239C0: @ 0x080239C0
	push {lr}
	ldr r1, _080239F0 @ =0x083B5F80
	ldr r0, _080239F4 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _080239F8 @ =0x03002C30
	ldr r1, _080239FC @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080239EC
	ldr r1, _08023A00 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080239EC:
	pop {r0}
	bx r0
	.align 2, 0
_080239F0: .4byte 0x083B5F80
_080239F4: .4byte 0x03000440
_080239F8: .4byte 0x03002C30
_080239FC: .4byte 0x00000862
_08023A00: .4byte 0x03001800
	.syntax divided
