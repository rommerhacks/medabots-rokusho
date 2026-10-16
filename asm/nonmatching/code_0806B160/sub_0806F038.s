	.syntax unified

	thumb_func_start sub_0806F038
sub_0806F038: @ 0x0806F038
	push {lr}
	bl load_bg_screen_b
	ldr r1, _0806F070 @ =0x0400004C
	movs r0, #0xff
	strh r0, [r1]
	ldr r2, _0806F074 @ =0x03001800
	movs r0, #6
	strh r0, [r2, #6]
	ldr r1, _0806F078 @ =0x03005000
	ldr r0, _0806F07C @ =0x0000FFE4
	strh r0, [r1, #2]
	ldr r1, _0806F080 @ =0x040000D4
	ldr r0, _0806F084 @ =0x08485FD8
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r0, _0806F088 @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _0806F08C @ =0x80000050
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrh r0, [r2, #0xc]
	strh r0, [r2, #4]
	ldr r1, _0806F090 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0806F070: .4byte 0x0400004C
_0806F074: .4byte 0x03001800
_0806F078: .4byte 0x03005000
_0806F07C: .4byte 0x0000FFE4
_0806F080: .4byte 0x040000D4
_0806F084: .4byte 0x08485FD8
_0806F088: .4byte 0x05000200
_0806F08C: .4byte 0x80000050
_0806F090: .4byte 0x0300137C
	.syntax divided
