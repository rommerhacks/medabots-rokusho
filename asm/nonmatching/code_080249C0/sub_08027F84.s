	.syntax unified

	thumb_func_start sub_08027F84
sub_08027F84: @ 0x08027F84
	push {r4, r5, r6, lr}
	ldr r0, _08028008 @ =0x084C978C
	ldr r1, _0802800C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08028010 @ =0x0850E0B8
	ldr r1, _08028014 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _08028018 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r3, r0
	ldrh r1, [r4]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r2, #0
	movs r6, #0
	adds r2, r0, #0
	orrs r2, r1
	strh r2, [r4]
	ldr r0, _0802801C @ =0x00000849
	adds r1, r3, r0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _08028020 @ =0x00000848
	adds r1, r3, r0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _08028024 @ =0x00000844
	adds r1, r3, r0
	movs r0, #0x3c
	strh r0, [r1]
	ldr r0, _08028028 @ =0x00000846
	adds r1, r3, r0
	movs r0, #0xe0
	lsls r0, r0, #4
	strh r0, [r1]
	ldr r5, _0802802C @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027FF6
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r2, r0
	strh r2, [r4]
	ldr r2, _08028030 @ =0x00000842
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_08027FF6:
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028008: .4byte 0x084C978C
_0802800C: .4byte 0x06014800
_08028010: .4byte 0x0850E0B8
_08028014: .4byte 0x050002E0
_08028018: .4byte 0x03002C30
_0802801C: .4byte 0x00000849
_08028020: .4byte 0x00000848
_08028024: .4byte 0x00000844
_08028028: .4byte 0x00000846
_0802802C: .4byte 0x03001800
_08028030: .4byte 0x00000842
_08028034:
	.byte 0x0B, 0x4B, 0x0C, 0x48, 0x19, 0x18, 0x08, 0x78, 0x08, 0x30, 0x08, 0x70
	.byte 0x00, 0x06, 0x00, 0x0E, 0x40, 0x28, 0x0C, 0xD1, 0x08, 0x48, 0x86, 0x30, 0x00, 0x22, 0x3C, 0x21
	.byte 0x01, 0x80, 0x07, 0x49, 0x58, 0x18, 0x02, 0x70, 0x06, 0x49, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30
	.byte 0x08, 0x70, 0x70, 0x47, 0x30, 0x2C, 0x00, 0x03, 0x48, 0x08, 0x00, 0x00, 0x40, 0x04, 0x00, 0x03
	.byte 0x67, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
