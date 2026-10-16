	.syntax unified

	thumb_func_start sub_080213E4
sub_080213E4: @ 0x080213E4
	push {lr}
	ldr r0, _08021404 @ =0x03002C30
	ldr r2, _08021408 @ =0x00000848
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #8
	bne _08021410
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0802140C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08021412
	.align 2, 0
_08021404: .4byte 0x03002C30
_08021408: .4byte 0x00000848
_0802140C: .4byte 0x03001800
_08021410:
	subs r0, #8
_08021412:
	strb r0, [r1]
	pop {r0}
	bx r0
	.syntax divided
