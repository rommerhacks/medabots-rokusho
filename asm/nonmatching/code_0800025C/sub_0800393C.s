	.syntax unified

	thumb_func_start sub_0800393C
sub_0800393C: @ 0x0800393C
	push {r4, lr}
	ldr r0, _08003994 @ =0x084C7174
	ldr r1, _08003998 @ =0x06016C00
	bl lz_decompress_dispatch
	ldr r1, _0800399C @ =0x040000D4
	ldr r0, _080039A0 @ =0x084E2E58
	str r0, [r1]
	ldr r0, _080039A4 @ =0x050003C0
	str r0, [r1, #4]
	ldr r0, _080039A8 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _080039AC @ =0x03002C30
	movs r4, #0
	ldr r0, _080039B0 @ =0x0000C004
	strh r0, [r3]
	ldr r2, _080039B4 @ =0x03000440
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r1, r1, #3
	movs r0, #0x88
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r3, #4]
	movs r0, #0xe
	strb r0, [r3, #0xa]
	strb r4, [r3, #0x1c]
	movs r0, #0xff
	strb r0, [r3, #0xb]
	ldr r0, _080039B8 @ =0x083B5F80
	ldr r0, [r0]
	movs r1, #0
	bl init_battle_sprite_entry_08040B90
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08003994: .4byte 0x084C7174
_08003998: .4byte 0x06016C00
_0800399C: .4byte 0x040000D4
_080039A0: .4byte 0x084E2E58
_080039A4: .4byte 0x050003C0
_080039A8: .4byte 0x84000008
_080039AC: .4byte 0x03002C30
_080039B0: .4byte 0x0000C004
_080039B4: .4byte 0x03000440
_080039B8: .4byte 0x083B5F80
	.syntax divided
