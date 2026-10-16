	.syntax unified

	thumb_func_start sub_0807079C
sub_0807079C: @ 0x0807079C
	push {r4, r5, lr}
	sub sp, #4
	movs r4, #0
	str r4, [sp]
	ldr r0, _08070828 @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _0807082C @ =0x85006000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _08070830 @ =0x85000100
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r1, _08070834 @ =0x03002C30
	str r1, [r0, #4]
	ldr r1, _08070838 @ =0x85000800
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp]
	mov r1, sp
	str r1, [r0]
	ldr r5, _0807083C @ =0x03001800
	str r5, [r0, #4]
	ldr r1, _08070840 @ =0x85000005
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #0
	bl play_song
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	movs r2, #0
	movs r1, #3
	strh r1, [r5]
	movs r0, #6
	strh r0, [r5, #2]
	ldr r0, _08070844 @ =0x03005000
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _08070848 @ =0x03004C30
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _0807084C @ =0x0300057C
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _08070850 @ =0x03001C04
	strh r4, [r0]
	strh r4, [r0, #2]
	ldr r0, _08070854 @ =0x03007010
	strb r2, [r0]
	ldr r0, _08070858 @ =0x0300137C
	str r1, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08070828: .4byte 0x040000D4
_0807082C: .4byte 0x85006000
_08070830: .4byte 0x85000100
_08070834: .4byte 0x03002C30
_08070838: .4byte 0x85000800
_0807083C: .4byte 0x03001800
_08070840: .4byte 0x85000005
_08070844: .4byte 0x03005000
_08070848: .4byte 0x03004C30
_0807084C: .4byte 0x0300057C
_08070850: .4byte 0x03001C04
_08070854: .4byte 0x03007010
_08070858: .4byte 0x0300137C
	.syntax divided
