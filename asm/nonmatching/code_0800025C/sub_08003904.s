	.syntax unified

	thumb_func_start sub_08003904
sub_08003904: @ 0x08003904
	push {lr}
	ldr r0, _08003918 @ =0x03000440
	adds r0, #0x8f
	ldrb r0, [r0]
	cmp r0, #0
	beq _08003920
	cmp r0, #1
	beq _08003928
	ldr r0, _0800391C @ =0x084C1FD4
	b _0800392A
	.align 2, 0
_08003918: .4byte 0x03000440
_0800391C: .4byte 0x084C1FD4
_08003920:
	ldr r0, _08003924 @ =0x084C1C24
	b _0800392A
	.align 2, 0
_08003924: .4byte 0x084C1C24
_08003928:
	ldr r0, _08003934 @ =0x084C1E04
_0800392A:
	ldr r1, _08003938 @ =0x06007E00
	bl lz_decompress_dispatch
	pop {r0}
	bx r0
	.align 2, 0
_08003934: .4byte 0x084C1E04
_08003938: .4byte 0x06007E00
	.syntax divided
