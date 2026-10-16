	.syntax unified

	thumb_func_start sub_080206E8
sub_080206E8: @ 0x080206E8
	push {lr}
	ldr r0, _08020718 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802071C @ =0x03002C30
	ldr r1, _08020720 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08020714
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08020724 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08020714:
	pop {r0}
	bx r0
	.align 2, 0
_08020718: .4byte 0x083B5F80
_0802071C: .4byte 0x03002C30
_08020720: .4byte 0x00000862
_08020724: .4byte 0x03001800
	.syntax divided
