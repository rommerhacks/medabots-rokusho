	.syntax unified

	thumb_func_start sub_0804C72C
sub_0804C72C: @ 0x0804C72C
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r2, _0804C75C @ =0x030057E0
	ldr r1, _0804C760 @ =0x00000C94
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804C76C
	ldr r3, _0804C764 @ =0x00000CBC
	adds r1, r2, r3
	subs r3, #0x27
	adds r0, r2, r3
	ldrb r0, [r0]
	ldrb r3, [r1]
	adds r0, r0, r3
	strb r0, [r1]
	ldr r0, _0804C768 @ =0x00000CBD
	adds r1, r2, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	b _0804C780
	.align 2, 0
_0804C75C: .4byte 0x030057E0
_0804C760: .4byte 0x00000C94
_0804C764: .4byte 0x00000CBC
_0804C768: .4byte 0x00000CBD
_0804C76C:
	ldr r3, _0804C78C @ =0x00000CBD
	adds r1, r2, r3
	subs r3, #0x28
	adds r0, r2, r3
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
_0804C780:
	cmp r0, #0x20
	ble _0804C788
	movs r0, #0x20
	strb r0, [r1]
_0804C788:
	pop {r0}
	bx r0
	.align 2, 0
_0804C78C: .4byte 0x00000CBD
	.syntax divided
