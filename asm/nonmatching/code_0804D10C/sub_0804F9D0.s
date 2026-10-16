	.syntax unified

	thumb_func_start sub_0804F9D0
sub_0804F9D0: @ 0x0804F9D0
	push {r4, lr}
	ldr r0, _0804F9E4 @ =0x030057E0
	ldr r1, _0804F9E8 @ =0x00000C93
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804F9EC
	cmp r0, #1
	beq _0804F9F8
	b _0804FA08
	.align 2, 0
_0804F9E4: .4byte 0x030057E0
_0804F9E8: .4byte 0x00000C93
_0804F9EC:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FA08
_0804F9F8:
	movs r0, #0x13
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FA08
	bl sub_08050244
_0804FA08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
