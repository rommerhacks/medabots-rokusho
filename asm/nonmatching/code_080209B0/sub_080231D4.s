	.syntax unified

	thumb_func_start sub_080231D4
sub_080231D4: @ 0x080231D4
	push {lr}
	ldr r2, _080231F8 @ =0x03002C30
	ldr r0, _080231FC @ =0x0000086D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	bne _08023204
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _08023200 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08023218
	.align 2, 0
_080231F8: .4byte 0x03002C30
_080231FC: .4byte 0x0000086D
_08023200: .4byte 0x03001800
_08023204:
	adds r0, #1
	strb r0, [r1]
	ldr r3, _0802321C @ =0x00000858
	adds r2, r2, r3
	ldrh r0, [r2]
	adds r0, #0x10
	ldr r3, _08023220 @ =0x000003FF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
_08023218:
	pop {r0}
	bx r0
	.align 2, 0
_0802321C: .4byte 0x00000858
_08023220: .4byte 0x000003FF
	.syntax divided
