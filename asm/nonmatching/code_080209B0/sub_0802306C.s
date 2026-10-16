	.syntax unified

	thumb_func_start sub_0802306C
sub_0802306C: @ 0x0802306C
	push {lr}
	ldr r0, _08023090 @ =0x084D5D78
	ldr r1, _08023094 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08023098 @ =0x0850E778
	ldr r1, _0802309C @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r1, _080230A0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08023090: .4byte 0x084D5D78
_08023094: .4byte 0x06014800
_08023098: .4byte 0x0850E778
_0802309C: .4byte 0x050002C0
_080230A0: .4byte 0x03001800
	.syntax divided
