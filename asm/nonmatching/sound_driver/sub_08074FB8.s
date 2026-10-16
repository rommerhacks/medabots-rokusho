	.syntax unified

	thumb_func_start sub_08074FB8
	.global sub_08074FB8
sub_08074FB8: @ 0x08074FB8
	movs r2, #0
	ldr r0, _08075014 @ =0x03007014
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x44
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0807500E
	adds r0, r1, #0
	adds r0, #0xb8
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0807500E
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0807500E
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0807500E
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0807500E
	movs r3, #0x8b
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _08075010
_0807500E:
	movs r2, #1
_08075010:
	adds r0, r2, #0
	bx lr
	.align 2, 0
_08075014: .4byte 0x03007014
	.syntax divided
