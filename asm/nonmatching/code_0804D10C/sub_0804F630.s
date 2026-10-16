	.syntax unified

	thumb_func_start sub_0804F630
sub_0804F630: @ 0x0804F630
	push {r4, lr}
	ldr r0, _0804F644 @ =0x030057E0
	ldr r1, _0804F648 @ =0x00000C93
	adds r4, r0, r1
	ldrb r1, [r4]
	cmp r1, #0
	beq _0804F64C
	cmp r1, #1
	beq _0804F658
	b _0804F66C
	.align 2, 0
_0804F644: .4byte 0x030057E0
_0804F648: .4byte 0x00000C93
_0804F64C:
	bl sub_08050C74
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804F66C
_0804F658:
	ldr r1, _0804F674 @ =0x00000C94
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #3
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804F66C
	bl sub_08050244
_0804F66C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F674: .4byte 0x00000C94

	.syntax divided
