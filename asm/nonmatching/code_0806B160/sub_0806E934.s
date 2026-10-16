	.syntax unified

	thumb_func_start sub_0806E934
sub_0806E934: @ 0x0806E934
	push {lr}
	bl sub_0806F850
	cmp r0, #0
	beq _0806E952
	ldr r2, _0806E958 @ =0x0300178C
	ldr r1, _0806E95C @ =0x03001800
	ldrh r0, [r1]
	str r0, [r2]
	ldr r2, _0806E960 @ =0x03002B8C
	ldrh r0, [r1, #2]
	str r0, [r2]
	ldr r2, _0806E964 @ =0x0300137C
	ldrh r0, [r1, #4]
	str r0, [r2]
_0806E952:
	pop {r0}
	bx r0
	.align 2, 0
_0806E958: .4byte 0x0300178C
_0806E95C: .4byte 0x03001800
_0806E960: .4byte 0x03002B8C
_0806E964: .4byte 0x0300137C
	.syntax divided
