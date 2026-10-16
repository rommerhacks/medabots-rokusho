	.syntax unified

	thumb_func_start sub_08041C5C
	.global sub_08041C5C
sub_08041C5C: @ 0x08041C5C
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
	beq _08041C84
	cmp r0, #3
	beq _08041C94
	ldr r1, _08041C80 @ =0x03002C30
	lsls r0, r3, #6
	adds r0, r0, r1
	strh r2, [r0, #4]
	b _08041C9E
	.align 2, 0
_08041C80: .4byte 0x03002C30
_08041C84:
	ldr r0, _08041C90 @ =0x03002C30
	lsls r1, r3, #6
	adds r1, r1, r0
	adds r0, r2, #1
	b _08041C9C
	.align 2, 0
_08041C90: .4byte 0x03002C30
_08041C94:
	ldr r0, _08041CA0 @ =0x03002C30
	lsls r1, r3, #6
	adds r1, r1, r0
	subs r0, r2, #1
_08041C9C:
	strh r0, [r1, #4]
_08041C9E:
	bx lr
	.align 2, 0
_08041CA0: .4byte 0x03002C30
	.syntax divided
