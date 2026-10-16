	.syntax unified

	thumb_func_start sub_0804BA50
sub_0804BA50: @ 0x0804BA50
	push {r4, lr}
	ldr r4, _0804BA84 @ =0x030057E0
	ldr r1, _0804BA88 @ =0x03002C30
	ldr r2, _0804BA8C @ =0x00000BC4
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0804BA90 @ =0x00000C94
	adds r0, r4, r3
	movs r3, #0
	strb r2, [r0]
	ldr r2, _0804BA94 @ =0x00000BE6
	adds r0, r1, r2
	strb r3, [r0]
	ldr r0, _0804BA98 @ =0x00000BE8
	adds r1, r1, r0
	strb r3, [r1]
	movs r0, #0x70
	bl sub_08047BA8
	ldr r2, _0804BA9C @ =0x00000C89
	adds r4, r4, r2
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804BA84: .4byte 0x030057E0
_0804BA88: .4byte 0x03002C30
_0804BA8C: .4byte 0x00000BC4
_0804BA90: .4byte 0x00000C94
_0804BA94: .4byte 0x00000BE6
_0804BA98: .4byte 0x00000BE8
_0804BA9C: .4byte 0x00000C89
	.syntax divided
