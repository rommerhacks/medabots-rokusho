	.syntax unified

	thumb_func_start sub_08020530
sub_08020530: @ 0x08020530
	push {lr}
	ldr r0, _08020568 @ =0x083B5F80
	adds r0, #0x98
	ldr r0, [r0]
	movs r1, #0xa
	bl process_sprite_anim_commands
	ldr r0, _0802056C @ =0x03002C30
	ldr r1, _08020570 @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08020564
	ldr r0, _08020574 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	movs r0, #0xa
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08020578 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08020564:
	pop {r0}
	bx r0
	.align 2, 0
_08020568: .4byte 0x083B5F80
_0802056C: .4byte 0x03002C30
_08020570: .4byte 0x000002A2
_08020574: .4byte 0x03000440
_08020578: .4byte 0x03001800
	.syntax divided
