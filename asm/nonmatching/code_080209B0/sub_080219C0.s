	.syntax unified

	thumb_func_start sub_080219C0
sub_080219C0: @ 0x080219C0
	push {r4, lr}
	ldr r4, _08021A00 @ =0x083B5F80
	adds r0, r4, #0
	adds r0, #0xe4
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _08021A04 @ =0x03002C30
	ldr r1, _08021A08 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080219FA
	adds r0, r4, #0
	adds r0, #0xec
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r0, _08021A0C @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _08021A10 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080219FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021A00: .4byte 0x083B5F80
_08021A04: .4byte 0x03002C30
_08021A08: .4byte 0x00000862
_08021A0C: .4byte 0x03000440
_08021A10: .4byte 0x03001800
	.syntax divided
