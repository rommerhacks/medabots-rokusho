	.syntax unified

	thumb_func_start sub_0803CB54
sub_0803CB54: @ 0x0803CB54
	push {r4, r5, lr}
	ldr r5, _0803CB70 @ =0x03002C30
	ldr r0, _0803CB74 @ =0x03000440
	ldr r1, _0803CB78 @ =0x0000012F
	adds r4, r0, r1
	ldrb r3, [r4]
	lsls r0, r3, #6
	adds r1, r0, r5
	ldrh r0, [r1, #0x30]
	cmp r0, #0
	beq _0803CB7C
	subs r0, #1
	strh r0, [r1, #0x30]
	b _0803CBC8
	.align 2, 0
_0803CB70: .4byte 0x03002C30
_0803CB74: .4byte 0x03000440
_0803CB78: .4byte 0x0000012F
_0803CB7C:
	adds r2, r1, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803CB8C
	subs r0, #1
	strb r0, [r2]
	b _0803CBC8
_0803CB8C:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803CBC0
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	bl play_sound_effect
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r1, [r1]
	adds r0, #0x2c
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2e
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
	b _0803CBC8
_0803CBC0:
	adds r0, r3, #0
	movs r1, #1
	bl clear_battle_sprite_slot
_0803CBC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
