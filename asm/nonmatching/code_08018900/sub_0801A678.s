	.syntax unified

	thumb_func_start sub_0801A678
	.global sub_0801A678
sub_0801A678: @ 0x0801A678
	push {r4, lr}
	movs r0, #0
	ldr r4, _0801A6AC @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x45
_0801A682:
	adds r2, r0, #1
	ldrb r0, [r1, #2]
	strb r0, [r1]
	ldrb r0, [r1, #3]
	strb r0, [r1, #1]
	adds r1, #2
	adds r0, r2, #0
	cmp r2, #4
	bls _0801A682
	movs r3, #0
	lsls r0, r2, #1
	adds r2, r4, #0
	adds r2, #0x45
	adds r1, r0, r2
	strb r3, [r1]
	adds r0, #1
	adds r0, r0, r2
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A6AC: .4byte 0x03001800
	.syntax divided
