	.syntax unified

	thumb_func_start sub_0804D10C
sub_0804D10C: @ 0x0804D10C
	push {r4, r5, r6, lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r6, _0804D154 @ =0x030057E0
	ldr r1, _0804D158 @ =0x00000C94
	adds r0, r6, r1
	ldr r2, _0804D15C @ =0x00000C5B
	adds r4, r6, r2
	ldrb r1, [r0]
	ldrb r0, [r4]
	cmp r1, r0
	bne _0804D1A6
	movs r0, #1
	eors r0, r1
	strb r0, [r4]
	ldrb r0, [r4]
	bl sub_08052BA0
	ldr r1, _0804D160 @ =0x00000C95
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804D1A6
	ldrb r5, [r4]
	cmp r5, #0
	beq _0804D168
	ldr r2, _0804D164 @ =0x00000C18
	adds r0, r6, r2
	subs r2, #8
	adds r1, r6, r2
	movs r2, #8
	bl memcpy_u8
	b _0804D1A6
	.align 2, 0
_0804D154: .4byte 0x030057E0
_0804D158: .4byte 0x00000C94
_0804D15C: .4byte 0x00000C5B
_0804D160: .4byte 0x00000C95
_0804D164: .4byte 0x00000C18
_0804D168:
	movs r0, #0xc1
	lsls r0, r0, #4
	adds r4, r6, r0
	ldr r2, _0804D1AC @ =0x00000C18
	adds r1, r6, r2
	adds r0, r4, #0
	movs r2, #8
	bl memcpy_u8
	strb r5, [r4]
	ldr r1, _0804D1B0 @ =0x00000C11
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _0804D1B4 @ =0x00000C12
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
_0804D1A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D1AC: .4byte 0x00000C18
_0804D1B0: .4byte 0x00000C11
_0804D1B4: .4byte 0x00000C12

	.syntax divided
