	.syntax unified

	thumb_func_start sub_080481C4
sub_080481C4: @ 0x080481C4
	cmp r0, #0
	bne _080481E4
	ldr r0, _080481D8 @ =0x083D29A6
	ldr r1, _080481DC @ =0x030057E0
	ldr r2, _080481E0 @ =0x00000C5C
	adds r1, r1, r2
	ldrb r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	b _0804821E
	.align 2, 0
_080481D8: .4byte 0x083D29A6
_080481DC: .4byte 0x030057E0
_080481E0: .4byte 0x00000C5C
_080481E4:
	cmp r0, #0xaf
	ble _0804821E
	cmp r0, #0xbf
	ble _0804821E
	cmp r0, #0xcf
	ble _0804821E
	cmp r0, #0xfe
	bgt _0804821C
	ldr r2, _08048210 @ =0x08414394
	adds r1, r0, #0
	subs r1, #0xd0
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, _08048214 @ =0x030057E0
	ldr r3, _08048218 @ =0x00000C38
	adds r0, r0, r3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r2, r2, r0
	ldrb r0, [r2]
	b _0804821E
	.align 2, 0
_08048210: .4byte 0x08414394
_08048214: .4byte 0x030057E0
_08048218: .4byte 0x00000C38
_0804821C:
	movs r0, #0xff
_0804821E:
	cmp r0, #0xff
	beq _08048234
	cmp r0, #0xbf
	ble _08048234
	adds r1, r0, #0
	subs r1, #0xc0
	lsls r1, r1, #1
	ldr r0, _08048238 @ =0x03006D38
	ldrb r0, [r0, #6]
	adds r0, #0x28
	adds r0, r1, r0
_08048234:
	bx lr
	.align 2, 0
_08048238: .4byte 0x03006D38
	.syntax divided
