	.syntax unified

	thumb_func_start sub_08026BF8
sub_08026BF8: @ 0x08026BF8
	push {r4, lr}
	movs r4, #0
	ldr r0, _08026CA0 @ =0x03001800
	adds r0, #0xd2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026C1E
	ldr r0, _08026CA4 @ =0x083B5F80
	ldr r0, [r0, #0x78]
	movs r1, #0xa
	bl process_sprite_anim_commands
	ldr r0, _08026CA8 @ =0x03002C30
	ldr r1, _08026CAC @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08026C1E
	movs r4, #1
_08026C1E:
	ldr r0, _08026CA0 @ =0x03001800
	adds r0, #0xd3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026C40
	ldr r0, _08026CA4 @ =0x083B5F80
	ldr r0, [r0, #0x78]
	movs r1, #0xb
	bl process_sprite_anim_commands
	ldr r0, _08026CA8 @ =0x03002C30
	ldr r1, _08026CB0 @ =0x000002E2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08026C40
	movs r4, #1
_08026C40:
	ldr r0, _08026CA0 @ =0x03001800
	adds r0, #0xd4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026C62
	ldr r0, _08026CA4 @ =0x083B5F80
	ldr r0, [r0, #0x78]
	movs r1, #0xc
	bl process_sprite_anim_commands
	ldr r0, _08026CA8 @ =0x03002C30
	ldr r1, _08026CB4 @ =0x00000322
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08026C62
	movs r4, #1
_08026C62:
	ldr r0, _08026CA0 @ =0x03001800
	adds r0, #0xd5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026C84
	ldr r0, _08026CA4 @ =0x083B5F80
	ldr r0, [r0, #0x78]
	movs r1, #0xd
	bl process_sprite_anim_commands
	ldr r0, _08026CA8 @ =0x03002C30
	ldr r1, _08026CB8 @ =0x00000362
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08026C84
	movs r4, #1
_08026C84:
	cmp r4, #0
	beq _08026C9A
	movs r0, #0xa
	movs r1, #4
	bl clear_battle_sprite_slot
	ldr r1, _08026CA0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08026C9A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026CA0: .4byte 0x03001800
_08026CA4: .4byte 0x083B5F80
_08026CA8: .4byte 0x03002C30
_08026CAC: .4byte 0x000002A2
_08026CB0: .4byte 0x000002E2
_08026CB4: .4byte 0x00000322
_08026CB8: .4byte 0x00000362
	.syntax divided
