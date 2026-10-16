	.syntax unified

	thumb_func_start sub_0806B310
	.global sub_0806B310
sub_0806B310: @ 0x0806B310
	ldr r0, _0806B32C @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0806B32A
	ldr r0, _0806B330 @ =0x03001C04
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0806B32A:
	bx lr
	.align 2, 0
_0806B32C: .4byte 0x03001780
_0806B330: .4byte 0x03001C04
	.syntax divided
