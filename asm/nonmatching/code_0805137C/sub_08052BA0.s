	.syntax unified

	thumb_func_start sub_08052BA0
	.global sub_08052BA0
sub_08052BA0: @ 0x08052BA0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08052BCC
	ldr r1, _08052BC0 @ =0x03002C30
	movs r0, #0xbc
	lsls r0, r0, #4
	adds r2, r1, r0
	ldr r0, _08052BC4 @ =0x0000C804
	strh r0, [r2]
	movs r3, #0xb2
	lsls r3, r3, #5
	adds r1, r1, r3
	ldr r0, _08052BC8 @ =0x0000CC0C
	strh r0, [r1]
	b _08052BDE
	.align 2, 0
_08052BC0: .4byte 0x03002C30
_08052BC4: .4byte 0x0000C804
_08052BC8: .4byte 0x0000CC0C
_08052BCC:
	ldr r0, _08052BE0 @ =0x03002C30
	movs r3, #0xbc
	lsls r3, r3, #4
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	strh r2, [r0]
_08052BDE:
	bx lr
	.align 2, 0
_08052BE0: .4byte 0x03002C30
	.syntax divided
