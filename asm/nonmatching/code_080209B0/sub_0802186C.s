	.syntax unified

	thumb_func_start sub_0802186C
sub_0802186C: @ 0x0802186C
	push {lr}
	ldr r2, _0802188C @ =0x03002C30
	ldr r0, _08021890 @ =0x00000848
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #8
	bne _08021898
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _08021894 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _080218AE
	.align 2, 0
_0802188C: .4byte 0x03002C30
_08021890: .4byte 0x00000848
_08021894: .4byte 0x03001800
_08021898:
	subs r0, #8
	strb r0, [r1]
	ldr r0, _080218B4 @ =0x00000888
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
	strb r0, [r1]
	ldr r0, _080218B8 @ =0x000008C8
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #8
_080218AE:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080218B4: .4byte 0x00000888
_080218B8: .4byte 0x000008C8
	.syntax divided
