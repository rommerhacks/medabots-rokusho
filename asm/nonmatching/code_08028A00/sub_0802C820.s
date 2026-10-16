	.syntax unified

	thumb_func_start sub_0802C820
sub_0802C820: @ 0x0802C820
	push {lr}
	ldr r1, _0802C840 @ =0x03002C30
	ldr r0, _0802C844 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #4
	bne _0802C84C
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0802C848 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0802C858
	.align 2, 0
_0802C840: .4byte 0x03002C30
_0802C844: .4byte 0x00000848
_0802C848: .4byte 0x03001800
_0802C84C:
	subs r0, #4
	strb r0, [r2]
	ldr r0, _0802C860 @ =0x00000849
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #4
_0802C858:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802C860: .4byte 0x00000849
	.syntax divided
