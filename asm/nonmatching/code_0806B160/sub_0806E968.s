	.syntax unified

	thumb_func_start sub_0806E968
sub_0806E968: @ 0x0806E968
	push {lr}
	bl sub_0806F9D4
	cmp r0, #0
	beq _0806E986
	ldr r2, _0806E98C @ =0x0300178C
	ldr r1, _0806E990 @ =0x03001800
	ldrh r0, [r1]
	str r0, [r2]
	ldr r2, _0806E994 @ =0x03002B8C
	ldrh r0, [r1, #2]
	str r0, [r2]
	ldr r2, _0806E998 @ =0x0300137C
	ldrh r0, [r1, #4]
	str r0, [r2]
_0806E986:
	pop {r0}
	bx r0
	.align 2, 0
_0806E98C: .4byte 0x0300178C
_0806E990: .4byte 0x03001800
_0806E994: .4byte 0x03002B8C
_0806E998: .4byte 0x0300137C
	.syntax divided
