	.syntax unified

	thumb_func_start sub_0801FF9C
sub_0801FF9C: @ 0x0801FF9C
	push {r4, r5, lr}
	ldr r0, _0801FFF4 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0801FFF8 @ =0x03002C30
	ldr r1, _0801FFFC @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801FFEC
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r4, _08020000 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x51
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	movs r1, #0xb4
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_sprite_table_mask
	ldrb r0, [r5]
	adds r0, #0x72
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_sprite_table_mask
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801FFEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801FFF4: .4byte 0x083B5F80
_0801FFF8: .4byte 0x03002C30
_0801FFFC: .4byte 0x00000862
_08020000: .4byte 0x03001800
	.syntax divided
