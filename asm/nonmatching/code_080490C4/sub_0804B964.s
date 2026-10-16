	.syntax unified

	thumb_func_start sub_0804B964
sub_0804B964: @ 0x0804B964
	push {lr}
	ldr r0, _0804B978 @ =0x030057E0
	ldr r1, _0804B97C @ =0x00000C5B
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl sub_0804B99C
	pop {r0}
	bx r0
	.align 2, 0
_0804B978: .4byte 0x030057E0
_0804B97C: .4byte 0x00000C5B
	.syntax divided
