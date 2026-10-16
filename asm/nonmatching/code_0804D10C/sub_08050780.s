	.syntax unified

	thumb_func_start sub_08050780
sub_08050780: @ 0x08050780
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0804DBA4
	ldr r1, _0805079C @ =0x03002C30
	adds r0, #0x4f
	lsls r0, r0, #6
	adds r0, r0, r1
	strb r4, [r0, #0xb]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805079C: .4byte 0x03002C30
	.syntax divided
