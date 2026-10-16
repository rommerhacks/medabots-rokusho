	.syntax unified

	thumb_func_start sub_08070030
	.global sub_08070030
sub_08070030: @ 0x08070030
	sub sp, #4
	ldr r0, _0807006C @ =0x03001800
	adds r2, r0, #0
	adds r2, #0xec
	movs r1, #0
	strb r1, [r2]
	adds r0, #0xed
	strb r1, [r0]
	str r1, [sp]
	ldr r1, _08070070 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08070074 @ =0x0600F800
	str r0, [r1, #4]
	ldr r0, _08070078 @ =0x850000A0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0807007C @ =0x03002C30
	movs r2, #0xc8
	movs r1, #5
	movs r3, #0x98
	lsls r3, r3, #3
	adds r0, r0, r3
_0807005E:
	strh r2, [r0, #4]
	subs r0, #0x40
	subs r1, #1
	cmp r1, #0
	bge _0807005E
	add sp, #4
	bx lr
	.align 2, 0
_0807006C: .4byte 0x03001800
_08070070: .4byte 0x040000D4
_08070074: .4byte 0x0600F800
_08070078: .4byte 0x850000A0
_0807007C: .4byte 0x03002C30
	.syntax divided
