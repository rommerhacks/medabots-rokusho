	.syntax unified

	thumb_func_start sub_08021AFC
sub_08021AFC: @ 0x08021AFC
	push {r4, r5, lr}
	ldr r5, _08021B70 @ =0x083B5F80
	adds r4, r5, #0
	adds r4, #0xec
	ldr r0, [r4]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, [r4]
	movs r1, #0x22
	bl process_sprite_anim_commands
	ldr r0, [r4]
	movs r1, #0x23
	bl process_sprite_anim_commands
	movs r0, #0x21
	bl move_sprite_toward_target
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r4, r1, #0x1f
	movs r0, #0x22
	bl move_sprite_toward_target
	cmp r0, #0
	beq _08021B34
	adds r4, #1
_08021B34:
	movs r0, #0x23
	bl move_sprite_toward_target
	cmp r0, #0
	beq _08021B40
	adds r4, #1
_08021B40:
	cmp r4, #3
	bne _08021B6A
	adds r4, r5, #0
	adds r4, #0xe8
	ldr r0, [r4]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, [r4]
	movs r1, #0x22
	bl init_battle_sprite_entry_08040B90
	ldr r0, [r4]
	movs r1, #0x23
	bl init_battle_sprite_entry_08040B90
	ldr r1, _08021B74 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021B6A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08021B70: .4byte 0x083B5F80
_08021B74: .4byte 0x03001800
	.syntax divided
