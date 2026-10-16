	.syntax unified

	thumb_func_start sub_08025E88
sub_08025E88: @ 0x08025E88
	push {r4, r5, lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	ldr r0, _08025ED0 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl battle_increment_bot_level
	adds r4, r0, #0
	ldr r1, _08025ED4 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r1, r0
	ldrh r2, [r3]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08025EF0
	movs r5, #0x88
	lsls r5, r5, #2
	adds r0, r5, #0
	orrs r0, r2
	strh r0, [r3]
	ldr r0, _08025ED8 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #1
	bne _08025EDC
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	b _08025EF2
	.align 2, 0
_08025ED0: .4byte 0x03001800
_08025ED4: .4byte 0x03002C30
_08025ED8: .4byte 0x00000848
_08025EDC:
	subs r0, #1
	strb r0, [r2]
	ldr r5, _08025EEC @ =0x00000849
	adds r1, r1, r5
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08025EF2
	.align 2, 0
_08025EEC: .4byte 0x00000849
_08025EF0:
	adds r4, #1
_08025EF2:
	cmp r4, #2
	bne _08025F08
	bl clear_battle_ui_tilemaps
	bl sub_0801AEB4
	ldr r1, _08025F10 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08025F08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025F10: .4byte 0x03001800
_08025F14:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x75, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
