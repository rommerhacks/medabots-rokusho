	.syntax unified

	thumb_func_start sub_0802BE44
sub_0802BE44: @ 0x0802BE44
	push {r4, r5, lr}
	ldr r0, _0802BED0 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r1, [r5]
	cmp r1, #2
	bhi _0802BE82
	adds r4, r0, #0
	adds r4, #0x86
	ldrh r0, [r4]
	cmp r0, #0
	bne _0802BE66
	adds r0, r1, #1
	strb r0, [r5]
	movs r0, #0x4c
	bl play_sound_effect
_0802BE66:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	ldr r2, _0802BED4 @ =0x083AE7D0
	ldrb r1, [r5]
	subs r1, #1
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1]
	cmp r0, r1
	bne _0802BE82
	movs r0, #0
	strh r0, [r4]
_0802BE82:
	ldr r2, _0802BED8 @ =0x03002C30
	ldr r0, _0802BEDC @ =0x00000858
	adds r3, r2, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _0802BE98
	ldr r4, _0802BEE0 @ =0x0000086E
	adds r1, r2, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802BE98:
	ldr r0, _0802BEE0 @ =0x0000086E
	adds r1, r2, r0
	ldrb r0, [r1]
	lsls r0, r0, #4
	ldrh r4, [r3]
	adds r2, r0, r4
	ldr r4, _0802BEE4 @ =0x000003FF
	adds r0, r4, #0
	ands r2, r0
	strh r2, [r3]
	ldrb r0, [r1]
	cmp r0, #5
	bne _0802BEC8
	cmp r2, #0
	bne _0802BEC8
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0802BEE8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802BEC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802BED0: .4byte 0x03000440
_0802BED4: .4byte 0x083AE7D0
_0802BED8: .4byte 0x03002C30
_0802BEDC: .4byte 0x00000858
_0802BEE0: .4byte 0x0000086E
_0802BEE4: .4byte 0x000003FF
_0802BEE8: .4byte 0x03001800
	.syntax divided
