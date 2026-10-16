	.syntax unified

	thumb_func_start init_battle_cursor_sprite_08017B24
	.global init_battle_cursor_sprite_08017B24
init_battle_cursor_sprite_08017B24: @ 0x08017B24
	push {r4, r5, lr}
	ldr r4, _08017B88 @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r5, #0
	ldr r0, _08017B8C @ =0x0000C404
	strh r0, [r1]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08017B90 @ =0x0000020A
	adds r1, r4, r2
	movs r0, #0xe
	strb r0, [r1]
	ldr r0, _08017B94 @ =0x0000020B
	adds r1, r4, r0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r3, _08017B98 @ =0x083AD3A4
	ldr r0, _08017B9C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x3d
	adds r0, #0x3c
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r0, #1
	adds r0, r0, r3
	ldrb r3, [r0]
	cmp r2, #0
	bne _08017BA8
	adds r1, #0x10
	ldr r2, _08017BA0 @ =0x00000202
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #4
	adds r1, r4, r2
	ldr r0, _08017BA4 @ =0x00000306
	b _08017BBE
	.align 2, 0
_08017B88: .4byte 0x03002C30
_08017B8C: .4byte 0x0000C404
_08017B90: .4byte 0x0000020A
_08017B94: .4byte 0x0000020B
_08017B98: .4byte 0x083AD3A4
_08017B9C: .4byte 0x03000440
_08017BA0: .4byte 0x00000202
_08017BA4: .4byte 0x00000306
_08017BA8:
	subs r1, #0x10
	ldr r2, _08017BC8 @ =0x00000202
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #4
	adds r1, r4, r2
	ldr r0, _08017BCC @ =0x00000307
_08017BBE:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017BC8: .4byte 0x00000202
_08017BCC: .4byte 0x00000307
	.syntax divided
