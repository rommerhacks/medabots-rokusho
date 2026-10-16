	.syntax unified

	thumb_func_start sub_0804BBD4
sub_0804BBD4: @ 0x0804BBD4
	push {r4, lr}
	ldr r2, _0804BC08 @ =0x030057E0
	ldr r1, _0804BC0C @ =0x00000CB4
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r3, r0, #3
	adds r0, r3, r2
	ldr r4, _0804BC10 @ =0x000005DE
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r0, _0804BC14 @ =0x00000FFF
	ands r0, r1
	ldr r4, _0804BC18 @ =0x00000C8E
	adds r1, r2, r4
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804BC00
	ldr r1, _0804BC1C @ =0x000005DC
	adds r0, r2, r1
	adds r0, r3, r0
	bl sub_0804D934
_0804BC00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804BC08: .4byte 0x030057E0
_0804BC0C: .4byte 0x00000CB4
_0804BC10: .4byte 0x000005DE
_0804BC14: .4byte 0x00000FFF
_0804BC18: .4byte 0x00000C8E
_0804BC1C: .4byte 0x000005DC
	.syntax divided
