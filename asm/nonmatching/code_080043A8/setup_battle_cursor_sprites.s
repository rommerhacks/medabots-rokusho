	.syntax unified

	thumb_func_start setup_battle_cursor_sprites
	.global setup_battle_cursor_sprites
setup_battle_cursor_sprites: @ 0x08006494
	push {r4, r5, r6, lr}
	ldr r0, _08006500 @ =0x03002C30
	mov ip, r0
	adds r0, #0x40
	movs r6, #0
	ldr r5, _08006504 @ =0x0000C804
	strh r5, [r0]
	mov r1, ip
	adds r1, #0x42
	movs r0, #0x6c
	strh r0, [r1]
	ldr r2, _08006508 @ =0x03000440
	adds r2, #0x5a
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #0x50
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	ldr r0, _0800650C @ =0x00000302
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	movs r4, #0xe
	strb r4, [r0]
	adds r0, #0x12
	strb r6, [r0]
	subs r0, #0x11
	movs r3, #0x40
	strb r3, [r0]
	adds r0, #0x35
	strh r5, [r0]
	adds r1, #0x3c
	movs r0, #0xe4
	strh r0, [r1]
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, #0x50
	adds r1, #2
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08006510 @ =0x00000303
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x8a
	strb r4, [r0]
	adds r0, #0x12
	strb r6, [r0]
	subs r0, #0x11
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006500: .4byte 0x03002C30
_08006504: .4byte 0x0000C804
_08006508: .4byte 0x03000440
_0800650C: .4byte 0x00000302
_08006510: .4byte 0x00000303
	.syntax divided
