	.syntax unified

	thumb_func_start sub_08036BB8
	.global sub_08036BB8
sub_08036BB8: @ 0x08036BB8
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _08036BE8 @ =0x03000590
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r1, r0, #0
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	beq _08036BEC
	ldrb r0, [r4]
	cmp r0, #0
	beq _08036BEC
	subs r0, #1
	strb r0, [r4]
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	b _08036BEE
	.align 2, 0
_08036BE8: .4byte 0x03000590
_08036BEC:
	movs r0, #1
_08036BEE:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
