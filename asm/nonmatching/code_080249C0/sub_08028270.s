	.syntax unified

	thumb_func_start sub_08028270
sub_08028270: @ 0x08028270
	push {lr}
	ldr r0, _080282B8 @ =0x084DBDC8
	ldr r1, _080282BC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080282C0 @ =0x0850EBB8
	ldr r1, _080282C4 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _080282C8 @ =0x03002C30
	ldr r0, _080282CC @ =0x00000846
	adds r2, r1, r0
	movs r3, #0
	movs r0, #0xd4
	lsls r0, r0, #7
	strh r0, [r2]
	ldr r0, _080282D0 @ =0x00000844
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #4
	strh r0, [r2]
	ldr r0, _080282D4 @ =0x00000867
	adds r1, r1, r0
	strb r3, [r1]
	ldr r0, _080282D8 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _080282DC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080282B8: .4byte 0x084DBDC8
_080282BC: .4byte 0x06014800
_080282C0: .4byte 0x0850EBB8
_080282C4: .4byte 0x050002E0
_080282C8: .4byte 0x03002C30
_080282CC: .4byte 0x00000846
_080282D0: .4byte 0x00000844
_080282D4: .4byte 0x00000867
_080282D8: .4byte 0x03000440
_080282DC: .4byte 0x03001800
	.syntax divided
