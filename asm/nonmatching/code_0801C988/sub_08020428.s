	.syntax unified

	thumb_func_start sub_08020428
sub_08020428: @ 0x08020428
	push {lr}
	ldr r0, _08020460 @ =0x083B5F80
	adds r0, #0x94
	ldr r0, [r0]
	movs r1, #0xa
	bl process_sprite_anim_commands
	ldr r0, _08020464 @ =0x03002C30
	ldr r1, _08020468 @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0802045C
	ldr r0, _0802046C @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	movs r0, #0xa
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08020470 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802045C:
	pop {r0}
	bx r0
	.align 2, 0
_08020460: .4byte 0x083B5F80
_08020464: .4byte 0x03002C30
_08020468: .4byte 0x000002A2
_0802046C: .4byte 0x03000440
_08020470: .4byte 0x03001800
	.syntax divided
