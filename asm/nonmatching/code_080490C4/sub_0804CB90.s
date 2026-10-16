	.syntax unified

	thumb_func_start sub_0804CB90
sub_0804CB90: @ 0x0804CB90
	push {r4, lr}
	ldr r4, _0804CBB8 @ =0x030057E0
	ldr r1, _0804CBBC @ =0x00000C8A
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0804CBC0 @ =0x00000C8C
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #3
	bl read_map_script_bytes
	ldr r3, _0804CBC4 @ =0x00000C94
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0804CBCC
	ldr r1, _0804CBC8 @ =0x00000CBC
	adds r0, r4, r1
	b _0804CBD0
	.align 2, 0
_0804CBB8: .4byte 0x030057E0
_0804CBBC: .4byte 0x00000C8A
_0804CBC0: .4byte 0x00000C8C
_0804CBC4: .4byte 0x00000C94
_0804CBC8: .4byte 0x00000CBC
_0804CBCC:
	ldr r3, _0804CBFC @ =0x00000CBD
	adds r0, r4, r3
_0804CBD0:
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r2, _0804CC00 @ =0x00000C95
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	bge _0804CBF4
	ldr r1, _0804CC04 @ =0x030057E0
	ldr r3, _0804CC08 @ =0x00000C8C
	adds r0, r1, r3
	adds r3, #0xa
	adds r2, r1, r3
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r2, _0804CC0C @ =0x00000C8A
	adds r1, r1, r2
	strh r0, [r1]
_0804CBF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804CBFC: .4byte 0x00000CBD
_0804CC00: .4byte 0x00000C95
_0804CC04: .4byte 0x030057E0
_0804CC08: .4byte 0x00000C8C
_0804CC0C: .4byte 0x00000C8A
	.syntax divided
