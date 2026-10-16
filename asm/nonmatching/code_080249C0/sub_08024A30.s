	.syntax unified

	thumb_func_start sub_08024A30
sub_08024A30: @ 0x08024A30
	push {r4, r5, lr}
	ldr r0, _08024AC8 @ =0x084D651C
	ldr r1, _08024ACC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08024AD0 @ =0x0850E858
	ldr r1, _08024AD4 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08024AD8 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrh r1, [r3]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r5, _08024ADC @ =0x00000848
	adds r0, r2, r5
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08024AE0 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	adds r5, #0x10
	adds r0, r2, r5
	strh r4, [r0]
	ldr r0, _08024AE4 @ =0x00000846
	adds r1, r2, r0
	movs r0, #0x9c
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r3, _08024AE8 @ =0x03001800
	adds r4, r3, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	adds r5, #0x18
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r4, _08024AEC @ =0x00000872
	adds r1, r2, r4
	strh r0, [r1]
	subs r5, #0xc
	adds r2, r2, r5
	movs r0, #6
	strb r0, [r2]
	ldr r0, _08024AF0 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r3, #0xaa
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08024AC8: .4byte 0x084D651C
_08024ACC: .4byte 0x06014800
_08024AD0: .4byte 0x0850E858
_08024AD4: .4byte 0x050002E0
_08024AD8: .4byte 0x03002C30
_08024ADC: .4byte 0x00000848
_08024AE0: .4byte 0x00000849
_08024AE4: .4byte 0x00000846
_08024AE8: .4byte 0x03001800
_08024AEC: .4byte 0x00000872
_08024AF0: .4byte 0x03000440
	.syntax divided
