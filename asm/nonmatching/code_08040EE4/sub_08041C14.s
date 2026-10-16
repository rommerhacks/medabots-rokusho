	.syntax unified

	thumb_func_start sub_08041C14
	.global sub_08041C14
sub_08041C14: @ 0x08041C14
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0xc0
	lsls r0, r0, #0x14
	ands r0, r1
	lsrs r0, r0, #0x1a
	cmp r0, #1
	beq _08041C3C
	cmp r0, #3
	beq _08041C4C
	ldr r1, _08041C38 @ =0x03002C30
	lsls r0, r3, #6
	adds r0, r0, r1
	strh r2, [r0, #2]
	b _08041C56
	.align 2, 0
_08041C38: .4byte 0x03002C30
_08041C3C:
	ldr r0, _08041C48 @ =0x03002C30
	lsls r1, r3, #6
	adds r1, r1, r0
	adds r0, r2, #1
	b _08041C54
	.align 2, 0
_08041C48: .4byte 0x03002C30
_08041C4C:
	ldr r0, _08041C58 @ =0x03002C30
	lsls r1, r3, #6
	adds r1, r1, r0
	subs r0, r2, #1
_08041C54:
	strh r0, [r1, #2]
_08041C56:
	bx lr
	.align 2, 0
_08041C58: .4byte 0x03002C30
	.syntax divided
