	.syntax unified

	thumb_func_start sub_0803CF7C
sub_0803CF7C: @ 0x0803CF7C
	push {lr}
	ldr r3, _0803CFB0 @ =0x03002C30
	ldr r0, _0803CFB4 @ =0x03000440
	ldr r1, _0803CFB8 @ =0x0000012F
	adds r2, r0, r1
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r3
	adds r1, r0, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803CF9A
	subs r0, #1
	strb r0, [r1]
_0803CF9A:
	ldrb r2, [r2]
	lsls r0, r2, #6
	adds r0, r0, r3
	adds r1, r0, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803CFBC
	subs r0, #1
	strb r0, [r1]
	b _0803CFC2
	.align 2, 0
_0803CFB0: .4byte 0x03002C30
_0803CFB4: .4byte 0x03000440
_0803CFB8: .4byte 0x0000012F
_0803CFBC:
	adds r0, r2, #0
	bl update_sprite_animation_position
_0803CFC2:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
