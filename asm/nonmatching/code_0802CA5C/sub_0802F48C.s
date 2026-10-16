	.syntax unified

	thumb_func_start sub_0802F48C
sub_0802F48C: @ 0x0802F48C
	push {lr}
	ldr r1, _0802F4AC @ =0x03002C30
	ldr r0, _0802F4B0 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #4
	bne _0802F4B8
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0802F4B4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0802F4C4
	.align 2, 0
_0802F4AC: .4byte 0x03002C30
_0802F4B0: .4byte 0x00000848
_0802F4B4: .4byte 0x03001800
_0802F4B8:
	subs r0, #4
	strb r0, [r2]
	ldr r0, _0802F4CC @ =0x00000849
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #4
_0802F4C4:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802F4CC: .4byte 0x00000849
	.syntax divided
