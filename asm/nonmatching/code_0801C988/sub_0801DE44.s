	.syntax unified

	thumb_func_start sub_0801DE44
sub_0801DE44: @ 0x0801DE44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _0801DEC0 @ =0x083B6EC8
	ldr r5, _0801DEC4 @ =0x03000590
	ldr r6, _0801DEC8 @ =0x03001800
	movs r0, #0xa7
	adds r0, r0, r6
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r6, #0
	adds r7, #0x87
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x4a
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r4, _0801DECC @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	ldr r2, _0801DED0 @ =0x083BE6E8
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r7]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x49
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x14
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	adds r1, r6, #0
	adds r1, #0xa6
	movs r0, #0x17
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DEC0: .4byte 0x083B6EC8
_0801DEC4: .4byte 0x03000590
_0801DEC8: .4byte 0x03001800
_0801DECC: .4byte 0x030004DE
_0801DED0: .4byte 0x083BE6E8
_0801DED4:
	.byte 0x02, 0x48, 0xB5, 0x30, 0x01, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
