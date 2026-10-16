	.syntax unified

	thumb_func_start sub_0804B77C
sub_0804B77C: @ 0x0804B77C
	push {r4, lr}
	ldr r0, _0804B7E0 @ =0x030057E0
	ldr r2, _0804B7E4 @ =0x00000C88
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _0804B7E8 @ =0x00000C89
	adds r1, r0, r3
	strb r2, [r1]
	ldr r4, _0804B7EC @ =0x00000C93
	adds r1, r0, r4
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	movs r3, #0
	strh r2, [r1]
	subs r4, #5
	adds r1, r0, r4
	strh r2, [r1]
	ldr r2, _0804B7F0 @ =0x00000C5F
	adds r1, r0, r2
	strb r3, [r1]
	subs r4, #0x2e
	adds r1, r0, r4
	strb r3, [r1]
	ldr r1, _0804B7F4 @ =0x03006D38
	strb r3, [r1, #6]
	ldr r1, _0804B7F8 @ =0x03005310
	adds r1, #0x38
	strb r3, [r1]
	ldr r1, _0804B7FC @ =0x00000CA4
	adds r0, r0, r1
	movs r1, #0x10
	bl sub_080496C8
	ldr r0, _0804B800 @ =0x03006D20
	movs r1, #0x10
	bl sub_080496C8
	ldr r0, _0804B804 @ =0x03002C30
	ldr r2, _0804B808 @ =0x00000BE5
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	bl set_battle_state_cancel_flag
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804B7E0: .4byte 0x030057E0
_0804B7E4: .4byte 0x00000C88
_0804B7E8: .4byte 0x00000C89
_0804B7EC: .4byte 0x00000C93
_0804B7F0: .4byte 0x00000C5F
_0804B7F4: .4byte 0x03006D38
_0804B7F8: .4byte 0x03005310
_0804B7FC: .4byte 0x00000CA4
_0804B800: .4byte 0x03006D20
_0804B804: .4byte 0x03002C30
_0804B808: .4byte 0x00000BE5
	.syntax divided
