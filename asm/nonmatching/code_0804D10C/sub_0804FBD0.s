	.syntax unified

	thumb_func_start sub_0804FBD0
sub_0804FBD0: @ 0x0804FBD0
	push {r4, r5, lr}
	ldr r0, _0804FBE4 @ =0x030057E0
	ldr r1, _0804FBE8 @ =0x00000C93
	adds r4, r0, r1
	ldrb r5, [r4]
	cmp r5, #0
	beq _0804FBEC
	cmp r5, #1
	beq _0804FBF8
	b _0804FC16
	.align 2, 0
_0804FBE4: .4byte 0x030057E0
_0804FBE8: .4byte 0x00000C93
_0804FBEC:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FC16
_0804FBF8:
	movs r0, #0x11
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FC16
	bl sub_0804B6EC
	cmp r0, #0
	beq _0804FC12
	ldr r0, _0804FC1C @ =0x03005310
	adds r0, #0x39
	strb r5, [r0]
_0804FC12:
	bl sub_08050244
_0804FC16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FC1C: .4byte 0x03005310
	.syntax divided
