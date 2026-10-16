	.syntax unified

	thumb_func_start sub_080526F0
	.global sub_080526F0
sub_080526F0: @ 0x080526F0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0805270C @ =0x030057E0
	ldr r2, _08052710 @ =0x00000C48
	adds r1, r1, r2
	ldrh r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bge _08052704
	adds r0, #0xf
_08052704:
	asrs r0, r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bx lr
	.align 2, 0
_0805270C: .4byte 0x030057E0
_08052710: .4byte 0x00000C48
	.syntax divided
