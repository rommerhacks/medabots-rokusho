	.syntax unified

	thumb_func_start setup_battle_bot_count_sprites
setup_battle_bot_count_sprites: @ 0x0800FCF0
	push {r4, r5, lr}
	ldr r0, _0800FD60 @ =0x03000440
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #1
	bls _0800FD58
	ldr r0, _0800FD64 @ =0x03002C30
	mov ip, r0
	adds r0, #0x40
	movs r5, #0
	ldr r4, _0800FD68 @ =0x0000C804
	strh r4, [r0]
	mov r1, ip
	adds r1, #0x42
	movs r0, #0xc
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x44
	movs r3, #0x28
	strh r3, [r0]
	adds r1, #4
	ldr r0, _0800FD6C @ =0x00000302
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	movs r2, #0xe
	strb r2, [r0]
	adds r0, #0x12
	strb r5, [r0]
	subs r0, #0x11
	movs r1, #0x80
	strb r1, [r0]
	adds r0, #0x35
	strh r4, [r0]
	mov r4, ip
	adds r4, #0x82
	movs r0, #0x54
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x84
	strh r3, [r0]
	mov r3, ip
	adds r3, #0x86
	ldr r0, _0800FD70 @ =0x00000303
	strh r0, [r3]
	mov r0, ip
	adds r0, #0x8a
	strb r2, [r0]
	adds r0, #0x12
	strb r5, [r0]
	subs r0, #0x11
	strb r1, [r0]
_0800FD58:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD60: .4byte 0x03000440
_0800FD64: .4byte 0x03002C30
_0800FD68: .4byte 0x0000C804
_0800FD6C: .4byte 0x00000302
_0800FD70: .4byte 0x00000303
	.syntax divided
