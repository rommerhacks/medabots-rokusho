	.syntax unified

	thumb_func_start sub_08027D98
sub_08027D98: @ 0x08027D98
	push {r4, lr}
	ldr r1, _08027DD4 @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _08027DD8 @ =0x03002C30
	ldr r0, _08027DDC @ =0x00000858
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r0, #0x40
	ldr r4, _08027DE0 @ =0x000003FF
	adds r1, r4, #0
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08027DE4 @ =0x00000848
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #4
	bne _08027DEC
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _08027DE8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _08027E0C
	.align 2, 0
_08027DD4: .4byte 0x03000440
_08027DD8: .4byte 0x03002C30
_08027DDC: .4byte 0x00000858
_08027DE0: .4byte 0x000003FF
_08027DE4: .4byte 0x00000848
_08027DE8: .4byte 0x03001800
_08027DEC:
	subs r0, #4
	strb r0, [r1]
	ldr r4, _08027E14 @ =0x00000849
	adds r1, r3, r4
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	ldr r0, _08027E18 @ =0x00000888
	adds r1, r3, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	adds r4, #0x40
	adds r1, r3, r4
	ldrb r0, [r1]
	subs r0, #4
_08027E0C:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08027E14: .4byte 0x00000849
_08027E18: .4byte 0x00000888
	.syntax divided
