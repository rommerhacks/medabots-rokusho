	.syntax unified

	thumb_func_start sub_0804CC10
sub_0804CC10: @ 0x0804CC10
	push {r4, r5, r6, lr}
	ldr r4, _0804CC4C @ =0x030057E0
	ldr r0, _0804CC50 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CC54 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #2
	bl read_map_script_bytes
	ldr r2, _0804CC58 @ =0x00000C94
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, #0x46
	subs r2, #0x34
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r0, r1
	beq _0804CC44
	ldr r0, _0804CC5C @ =0x00000C95
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CC44:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CC4C: .4byte 0x030057E0
_0804CC50: .4byte 0x00000C8A
_0804CC54: .4byte 0x00000C8C
_0804CC58: .4byte 0x00000C94
_0804CC5C: .4byte 0x00000C95
	.syntax divided
