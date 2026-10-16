	.syntax unified

	thumb_func_start sub_08038804
sub_08038804: @ 0x08038804
	push {r4, lr}
	ldr r0, _0803883C @ =0x083B5F80
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08038840 @ =0x03000440
	ldr r2, _08038844 @ =0x0000012F
	adds r4, r1, r2
	ldrb r1, [r4]
	bl process_sprite_anim_commands
	ldr r1, _08038848 @ =0x03002C30
	ldrb r2, [r4]
	lsls r0, r2, #6
	adds r0, r0, r1
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08038834
	adds r0, r2, #0
	movs r1, #1
	bl clear_battle_sprite_slot
_08038834:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803883C: .4byte 0x083B5F80
_08038840: .4byte 0x03000440
_08038844: .4byte 0x0000012F
_08038848: .4byte 0x03002C30
	.syntax divided
