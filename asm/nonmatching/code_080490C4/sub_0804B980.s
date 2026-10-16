	.syntax unified

	thumb_func_start sub_0804B980
sub_0804B980: @ 0x0804B980
	push {lr}
	ldr r0, _0804B994 @ =0x030057E0
	ldr r1, _0804B998 @ =0x00000C5B
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bl sub_0804B99C
	pop {r0}
	bx r0
	.align 2, 0
_0804B994: .4byte 0x030057E0
_0804B998: .4byte 0x00000C5B
	.syntax divided
