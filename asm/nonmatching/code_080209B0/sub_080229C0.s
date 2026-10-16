	.syntax unified

	thumb_func_start sub_080229C0
sub_080229C0: @ 0x080229C0
	push {lr}
	ldr r0, _080229EC @ =0x083B5F80
	adds r0, #0xf8
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _080229F0 @ =0x03002C30
	ldr r2, _080229F4 @ =0x00000848
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #8
	bne _080229FC
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _080229F8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _080229FE
	.align 2, 0
_080229EC: .4byte 0x083B5F80
_080229F0: .4byte 0x03002C30
_080229F4: .4byte 0x00000848
_080229F8: .4byte 0x03001800
_080229FC:
	subs r0, #8
_080229FE:
	strb r0, [r1]
	pop {r0}
	bx r0
	.syntax divided
