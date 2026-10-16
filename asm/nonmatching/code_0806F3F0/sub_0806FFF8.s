	.syntax unified

	thumb_func_start sub_0806FFF8
	.global sub_0806FFF8
sub_0806FFF8: @ 0x0806FFF8
	sub sp, #4
	ldr r0, _08070020 @ =0x03001800
	adds r2, r0, #0
	adds r2, #0xf2
	movs r1, #0
	strh r1, [r2]
	adds r0, #0xf0
	strh r1, [r0]
	mov r0, sp
	strh r1, [r0]
	ldr r1, _08070024 @ =0x040000D4
	str r0, [r1]
	ldr r0, _08070028 @ =0x0600F86C
	str r0, [r1, #4]
	ldr r0, _0807002C @ =0x81000007
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	bx lr
	.align 2, 0
_08070020: .4byte 0x03001800
_08070024: .4byte 0x040000D4
_08070028: .4byte 0x0600F86C
_0807002C: .4byte 0x81000007
	.syntax divided
