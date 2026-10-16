	.syntax unified

	thumb_func_start sub_080705BC
sub_080705BC: @ 0x080705BC
	push {r4, lr}
	lsls r0, r0, #0x18
	ldr r1, _080705D8 @ =0x03002C30
	lsrs r0, r0, #0x12
	adds r2, r0, r1
	adds r3, r2, #0
	adds r3, #0x21
	ldrb r0, [r3]
	cmp r0, #0x47
	bhi _080705DC
	adds r0, #1
	strb r0, [r3]
	b _080705F8
	.align 2, 0
_080705D8: .4byte 0x03002C30
_080705DC:
	ldrh r4, [r2, #4]
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r0, #0x50
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080705F4
	movs r1, #0
	movs r0, #0xa0
	strh r0, [r2, #4]
	strb r1, [r3]
	b _080705F8
_080705F4:
	subs r0, r4, #4
	strh r0, [r2, #4]
_080705F8:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
