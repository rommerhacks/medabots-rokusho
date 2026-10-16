	.syntax unified

	thumb_func_start sub_08030354
sub_08030354: @ 0x08030354
	push {lr}
	ldr r0, _08030390 @ =0x083B5F80
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x25
	bl process_sprite_anim_commands
	ldr r0, _08030394 @ =0x03002C30
	ldr r1, _08030398 @ =0x00000962
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0803038C
	ldr r0, _0803039C @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x25
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _080303A0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803038C:
	pop {r0}
	bx r0
	.align 2, 0
_08030390: .4byte 0x083B5F80
_08030394: .4byte 0x03002C30
_08030398: .4byte 0x00000962
_0803039C: .4byte 0x03000440
_080303A0: .4byte 0x03001800
	.syntax divided
