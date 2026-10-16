	.syntax unified

	thumb_func_start sub_0804FA50
sub_0804FA50: @ 0x0804FA50
	push {r4, lr}
	ldr r0, _0804FA64 @ =0x030057E0
	ldr r1, _0804FA68 @ =0x00000C93
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FA6C
	cmp r0, #1
	beq _0804FA78
	b _0804FA88
	.align 2, 0
_0804FA64: .4byte 0x030057E0
_0804FA68: .4byte 0x00000C93
_0804FA6C:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804FA88
_0804FA78:
	movs r0, #2
	movs r1, #0
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804FA88
	bl sub_08050244
_0804FA88:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
