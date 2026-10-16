	.syntax unified

	thumb_func_start sub_0802AF6C
sub_0802AF6C: @ 0x0802AF6C
	push {lr}
	ldr r0, _0802AFA0 @ =0x083B5F80
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802AFA4 @ =0x03002C30
	ldr r1, _0802AFA8 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0802AF9C
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0802AFAC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802AF9C:
	pop {r0}
	bx r0
	.align 2, 0
_0802AFA0: .4byte 0x083B5F80
_0802AFA4: .4byte 0x03002C30
_0802AFA8: .4byte 0x00000862
_0802AFAC: .4byte 0x03001800
	.syntax divided
