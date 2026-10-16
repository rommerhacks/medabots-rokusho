	.syntax unified

	thumb_func_start sub_0804BF68
sub_0804BF68: @ 0x0804BF68
	push {r4, r5, r6, lr}
	bl read_map_script_byte
	adds r5, r0, #0
	ldr r4, _0804BFC4 @ =0x030057E0
	ldr r1, _0804BFC8 @ =0x00000C94
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0804BFCC @ =0x00000CB4
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r3, r0, r4
	ldr r6, _0804BFD0 @ =0x000005DE
	adds r0, r3, r6
	ldrh r2, [r0]
	ldr r0, _0804BFD4 @ =0x00000FFF
	ldr r6, _0804BFD8 @ =0x00000C8E
	adds r1, r4, r6
	ands r0, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804BFBC
	ldr r1, _0804BFDC @ =0x03006D20
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	adds r0, #0x31
	strb r0, [r1, #0xa]
	strb r5, [r1]
	movs r0, #0
	strb r0, [r1, #1]
	movs r0, #8
	strb r0, [r1, #2]
	strb r0, [r1, #3]
	subs r6, #5
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
_0804BFBC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BFC4: .4byte 0x030057E0
_0804BFC8: .4byte 0x00000C94
_0804BFCC: .4byte 0x00000CB4
_0804BFD0: .4byte 0x000005DE
_0804BFD4: .4byte 0x00000FFF
_0804BFD8: .4byte 0x00000C8E
_0804BFDC: .4byte 0x03006D20
	.syntax divided
