	.syntax unified

	thumb_func_start sub_0801677C
	.global sub_0801677C
sub_0801677C: @ 0x0801677C
	ldr r2, _080167AC @ =0x03002C30
	movs r1, #0
	ldr r0, _080167B0 @ =0x0000C404
	strh r0, [r2]
	strb r1, [r2, #0x1c]
	movs r0, #0x78
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	movs r0, #0xa
	strb r0, [r2, #0xa]
	movs r0, #0xc0
	strb r0, [r2, #0xb]
	ldr r1, _080167B4 @ =0x083AD3A0
	ldr r0, _080167B8 @ =0x03001800
	adds r0, #0x82
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r2, #6]
	bx lr
	.align 2, 0
_080167AC: .4byte 0x03002C30
_080167B0: .4byte 0x0000C404
_080167B4: .4byte 0x083AD3A0
_080167B8: .4byte 0x03001800
	.syntax divided
