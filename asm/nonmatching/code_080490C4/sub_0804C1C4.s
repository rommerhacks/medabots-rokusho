	.syntax unified

	thumb_func_start sub_0804C1C4
sub_0804C1C4: @ 0x0804C1C4
	push {r4, r5, r6, lr}
	movs r0, #3
	bl read_map_script_bytes
	ldr r5, _0804C208 @ =0x030057E0
	ldr r1, _0804C20C @ =0x00000C94
	adds r0, r5, r1
	ldrb r0, [r0]
	bl sub_0804DBA4
	ldr r4, _0804C210 @ =0x03006D20
	adds r0, #0x4f
	movs r6, #0
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xa]
	ldr r2, _0804C214 @ =0x00000C95
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #0xf
	ands r1, r2
	bl set_sprite_animation_state
	strb r6, [r4]
	ldr r1, _0804C218 @ =0x00000C96
	adds r0, r5, r1
	ldrb r0, [r0]
	strb r0, [r4, #2]
	ldr r2, _0804C21C @ =0x00000C89
	adds r5, r5, r2
	movs r0, #1
	strb r0, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804C208: .4byte 0x030057E0
_0804C20C: .4byte 0x00000C94
_0804C210: .4byte 0x03006D20
_0804C214: .4byte 0x00000C95
_0804C218: .4byte 0x00000C96
_0804C21C: .4byte 0x00000C89
	.syntax divided
