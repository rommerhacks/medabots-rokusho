	.syntax unified

	thumb_func_start sub_0804CFD8
sub_0804CFD8: @ 0x0804CFD8
	push {r4, r5, lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r4, _0804D024 @ =0x030057E0
	ldr r1, _0804D028 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0804D02C @ =0x00000C95
	adds r1, r4, r2
	ldrb r3, [r1]
	movs r2, #0x7f
	adds r1, r2, #0
	ands r1, r3
	ldr r5, _0804D030 @ =0x00000C48
	adds r3, r4, r5
	lsls r1, r1, #4
	ldrh r3, [r3]
	adds r1, r1, r3
	adds r5, #0x4e
	adds r3, r4, r5
	ldrb r3, [r3]
	ands r2, r3
	subs r5, #0x4c
	adds r3, r4, r5
	lsls r2, r2, #4
	ldrh r3, [r3]
	adds r2, r2, r3
	movs r3, #0
	bl init_sprite_affine_matrices_and_state
	ldr r0, _0804D034 @ =0x00000C89
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804D024: .4byte 0x030057E0
_0804D028: .4byte 0x00000C94
_0804D02C: .4byte 0x00000C95
_0804D030: .4byte 0x00000C48
_0804D034: .4byte 0x00000C89
	.syntax divided
