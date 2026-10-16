	.syntax unified

	thumb_func_start sub_08025D6C
sub_08025D6C: @ 0x08025D6C
	push {r4, r5, lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	ldr r5, _08025DC0 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_0801AFB8
	adds r4, r0, #0
	ldr r1, _08025DC4 @ =0x083B5F80
	ldr r0, _08025DC8 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _08025DCC @ =0x03002C30
	ldr r1, _08025DD0 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08025DA4
	adds r4, #1
_08025DA4:
	cmp r4, #2
	bne _08025DBA
	bl clear_battle_ui_tilemaps
	bl sub_0801AEB4
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08025DBA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025DC0: .4byte 0x03001800
_08025DC4: .4byte 0x083B5F80
_08025DC8: .4byte 0x03000440
_08025DCC: .4byte 0x03002C30
_08025DD0: .4byte 0x00000862
	.syntax divided
