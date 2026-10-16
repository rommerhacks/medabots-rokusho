	.syntax unified

	thumb_func_start sub_08022708
sub_08022708: @ 0x08022708
	push {lr}
	ldr r0, _08022738 @ =0x083B5F80
	ldr r0, [r0, #0x70]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802273C @ =0x03002C30
	ldr r1, _08022740 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08022732
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08022744 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08022732:
	pop {r0}
	bx r0
	.align 2, 0
_08022738: .4byte 0x083B5F80
_0802273C: .4byte 0x03002C30
_08022740: .4byte 0x00000862
_08022744: .4byte 0x03001800
	.syntax divided
