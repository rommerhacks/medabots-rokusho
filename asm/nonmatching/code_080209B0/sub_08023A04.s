	.syntax unified

	thumb_func_start sub_08023A04
sub_08023A04: @ 0x08023A04
	push {lr}
	ldr r1, _08023A24 @ =0x03002C30
	ldr r0, _08023A28 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #8
	bne _08023A30
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08023A2C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08023A3C
	.align 2, 0
_08023A24: .4byte 0x03002C30
_08023A28: .4byte 0x00000848
_08023A2C: .4byte 0x03001800
_08023A30:
	subs r0, #8
	strb r0, [r2]
	ldr r0, _08023A44 @ =0x00000849
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #8
_08023A3C:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08023A44: .4byte 0x00000849
	.syntax divided
