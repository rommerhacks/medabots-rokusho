	.syntax unified

	thumb_func_start sub_0804FA10
sub_0804FA10: @ 0x0804FA10
	push {r4, lr}
	ldr r0, _0804FA24 @ =0x030057E0
	ldr r1, _0804FA28 @ =0x00000C93
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FA2C
	cmp r0, #1
	beq _0804FA38
	b _0804FA48
	.align 2, 0
_0804FA24: .4byte 0x030057E0
_0804FA28: .4byte 0x00000C93
_0804FA2C:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FA48
_0804FA38:
	movs r0, #0
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FA48
	bl sub_08050244
_0804FA48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
