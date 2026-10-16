	.syntax unified

	thumb_func_start sub_0802494C
sub_0802494C: @ 0x0802494C
	push {r4, lr}
	ldr r0, _08024988 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802498C @ =0x03002C30
	ldr r1, _08024990 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08024982
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r4, _08024994 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl load_bot_part_sprite
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_08024982:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08024988: .4byte 0x083B5F80
_0802498C: .4byte 0x03002C30
_08024990: .4byte 0x00000862
_08024994: .4byte 0x03001800
	.syntax divided
