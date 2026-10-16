	.syntax unified

	thumb_func_start sub_0804D4B0
sub_0804D4B0: @ 0x0804D4B0
	push {r4, r5, r6, lr}
	ldr r6, _0804D520 @ =0x030064A0
	adds r5, r6, #0
	adds r5, #0x52
	movs r4, #0
	strb r4, [r5]
	adds r0, r6, #2
	movs r1, #8
	bl sub_080496C8
	adds r0, r6, #0
	adds r0, #0xa
	movs r1, #8
	bl sub_080496C8
	adds r0, r6, #0
	adds r0, #0x12
	movs r1, #0x40
	bl sub_080496C8
	adds r0, r5, #0
	movs r1, #1
	bl sub_080496C8
	adds r0, r6, #0
	adds r0, #0x53
	movs r1, #1
	bl sub_080496C8
	adds r0, r6, #0
	adds r0, #0x54
	movs r1, #8
	bl sub_080496C8
	bl read_map_script_byte
	ldr r1, _0804D524 @ =0x030057E0
	ldr r3, _0804D528 @ =0x00000C92
	adds r2, r1, r3
	strb r0, [r2]
	subs r3, #9
	adds r0, r1, r3
	strb r4, [r0]
	ldr r0, _0804D52C @ =0x00000C93
	adds r1, r1, r0
	strb r4, [r1]
	ldr r1, _0804D530 @ =0x083D20AC
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D520: .4byte 0x030064A0
_0804D524: .4byte 0x030057E0
_0804D528: .4byte 0x00000C92
_0804D52C: .4byte 0x00000C93
_0804D530: .4byte 0x083D20AC
	.syntax divided
