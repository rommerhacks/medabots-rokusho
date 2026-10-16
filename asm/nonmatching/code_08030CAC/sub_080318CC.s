	.syntax unified

	thumb_func_start sub_080318CC
sub_080318CC: @ 0x080318CC
	push {r4, lr}
	ldr r2, _08031904 @ =0x083B7338
	ldr r1, _08031908 @ =0x03000590
	ldr r4, _0803190C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xa8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _08031910 @ =0x030004DE
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	adds r4, #0xa6
	movs r0, #0x38
	strb r0, [r4]
	ldr r1, _08031914 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031904: .4byte 0x083B7338
_08031908: .4byte 0x03000590
_0803190C: .4byte 0x03001800
_08031910: .4byte 0x030004DE
_08031914: .4byte 0x0300137C
	.syntax divided
