	.syntax unified

	thumb_func_start sub_0804FC30
sub_0804FC30: @ 0x0804FC30
	push {r4, r5, lr}
	ldr r4, _0804FCA8 @ =0x03002C30
	ldr r5, _0804FCAC @ =0x030057E0
	ldr r1, _0804FCB0 @ =0x00000C6E
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r3, _0804FCB4 @ =0x00000C0C
	adds r2, r4, r3
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc7
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r3, #4
	adds r2, r4, r3
	lsls r1, r1, #8
	ldrb r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r2, _0804FCB8 @ =0x00000C94
	adds r5, r5, r2
	ldrb r1, [r5]
	lsls r1, r1, #6
	movs r3, #0x9e
	lsls r3, r3, #5
	adds r2, r4, r3
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_u8
	ldr r1, _0804FCBC @ =0x030055A0
	ldrb r0, [r5]
	adds r0, #0x4f
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, _0804FCC0 @ =0x0000FFFF
	strh r1, [r0]
	movs r1, #0xb4
	lsls r1, r1, #5
	adds r0, r4, r1
	ldrb r1, [r5]
	lsls r1, r1, #6
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r4, r4, r2
	adds r1, r1, r4
	movs r2, #0x40
	bl memcpy_u8
	bl map_script_command_done
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804FCA8: .4byte 0x03002C30
_0804FCAC: .4byte 0x030057E0
_0804FCB0: .4byte 0x00000C6E
_0804FCB4: .4byte 0x00000C0C
_0804FCB8: .4byte 0x00000C94
_0804FCBC: .4byte 0x030055A0
_0804FCC0: .4byte 0x0000FFFF
	.syntax divided
