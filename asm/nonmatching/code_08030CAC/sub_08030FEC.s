	.syntax unified

	thumb_func_start sub_08030FEC
sub_08030FEC: @ 0x08030FEC
	push {lr}
	ldr r0, _08031028 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x5a
	bne _0803103E
	ldr r0, _0803102C @ =0x03002C30
	ldr r2, _08031030 @ =0x00000849
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #8
	bne _08031038
	movs r0, #0x1c
	bl play_song
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _08031034 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08031042
	.align 2, 0
_08031028: .4byte 0x03000440
_0803102C: .4byte 0x03002C30
_08031030: .4byte 0x00000849
_08031034: .4byte 0x0300137C
_08031038:
	subs r0, #8
	strb r0, [r1]
	b _08031042
_0803103E:
	adds r0, #1
	strh r0, [r1]
_08031042:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
