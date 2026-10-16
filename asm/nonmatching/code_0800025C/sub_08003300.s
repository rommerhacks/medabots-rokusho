	.syntax unified

	thumb_func_start sub_08003300
sub_08003300: @ 0x08003300
	push {lr}
	ldr r0, _0800334C @ =0x084C7174
	ldr r1, _08003350 @ =0x06016C00
	bl lz_decompress_dispatch
	ldr r1, _08003354 @ =0x040000D4
	ldr r0, _08003358 @ =0x084E2E58
	str r0, [r1]
	ldr r0, _0800335C @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _08003360 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08003364 @ =0x03002C30
	movs r2, #0
	ldr r0, _08003368 @ =0x0000C004
	strh r0, [r1]
	movs r0, #0x88
	strh r0, [r1, #2]
	ldr r0, _0800336C @ =0x03000440
	adds r0, #0x8e
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #8
	strh r0, [r1, #4]
	movs r0, #0xe
	strb r0, [r1, #0xa]
	strb r2, [r1, #0x1c]
	movs r0, #0xff
	strb r0, [r1, #0xb]
	ldr r0, _08003370 @ =0x083B5F80
	ldr r0, [r0]
	movs r1, #0
	bl init_battle_sprite_entry_08040B90
	pop {r0}
	bx r0
	.align 2, 0
_0800334C: .4byte 0x084C7174
_08003350: .4byte 0x06016C00
_08003354: .4byte 0x040000D4
_08003358: .4byte 0x084E2E58
_0800335C: .4byte 0x050003C0
_08003360: .4byte 0x84000008
_08003364: .4byte 0x03002C30
_08003368: .4byte 0x0000C004
_0800336C: .4byte 0x03000440
_08003370: .4byte 0x083B5F80
	.syntax divided
