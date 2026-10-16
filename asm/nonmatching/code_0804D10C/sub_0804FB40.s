	.syntax unified

	thumb_func_start sub_0804FB40
sub_0804FB40: @ 0x0804FB40
	push {r4, r5, lr}
	ldr r0, _0804FB54 @ =0x030057E0
	ldr r1, _0804FB58 @ =0x00000C93
	adds r4, r0, r1
	ldrb r5, [r4]
	cmp r5, #0
	beq _0804FB5C
	cmp r5, #1
	beq _0804FB68
	b _0804FB86
	.align 2, 0
_0804FB54: .4byte 0x030057E0
_0804FB58: .4byte 0x00000C93
_0804FB5C:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FB86
_0804FB68:
	movs r0, #0x10
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FB86
	bl sub_0804B6EC
	cmp r0, #0
	beq _0804FB82
	ldr r0, _0804FB8C @ =0x03005310
	adds r0, #0x39
	strb r5, [r0]
_0804FB82:
	bl sub_08050244
_0804FB86:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FB8C: .4byte 0x03005310
	.syntax divided
