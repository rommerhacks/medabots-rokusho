	.syntax unified

	thumb_func_start sub_0806918C
sub_0806918C: @ 0x0806918C
	sub sp, #4
	movs r2, #0
	str r2, [sp]
	ldr r1, _080691D8 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080691DC @ =0x85006000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r3, #0x80
	lsls r3, r3, #0x13
	movs r0, #0x60
	strh r0, [r3]
	str r2, [sp]
	mov r0, sp
	str r0, [r1]
	ldr r0, _080691E0 @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _080691E4 @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _080691E8 @ =0x03005000
	strh r2, [r0]
	strh r2, [r0, #2]
	ldr r0, _080691EC @ =0x03004C30
	strh r2, [r0]
	strh r2, [r0, #2]
	ldr r0, _080691F0 @ =0x0300057C
	strh r2, [r0]
	strh r2, [r0, #2]
	ldr r0, _080691F4 @ =0x03001C04
	strh r2, [r0]
	strh r2, [r0, #2]
	add sp, #4
	bx lr
	.align 2, 0
_080691D8: .4byte 0x040000D4
_080691DC: .4byte 0x85006000
_080691E0: .4byte 0x03002C30
_080691E4: .4byte 0x85000800
_080691E8: .4byte 0x03005000
_080691EC: .4byte 0x03004C30
_080691F0: .4byte 0x0300057C
_080691F4: .4byte 0x03001C04
	.syntax divided
