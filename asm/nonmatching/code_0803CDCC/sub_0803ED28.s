	.syntax unified

	thumb_func_start sub_0803ED28
sub_0803ED28: @ 0x0803ED28
	push {r4, lr}
	bl sub_0803EC50
	ldr r3, _0803ED54 @ =0x03002C30
	adds r2, r3, #0
	adds r2, #0x84
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0803ED58 @ =0x03001800
	ldr r4, _0803ED5C @ =0x000001A3
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	bge _0803ED60
	adds r1, r3, #0
	adds r1, #0xa4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	b _0803ED64
	.align 2, 0
_0803ED54: .4byte 0x03002C30
_0803ED58: .4byte 0x03001800
_0803ED5C: .4byte 0x000001A3
_0803ED60:
	strh r0, [r2]
	movs r0, #1
_0803ED64:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
