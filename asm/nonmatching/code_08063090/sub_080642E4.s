	.syntax unified

	thumb_func_start sub_080642E4
sub_080642E4: @ 0x080642E4
	push {lr}
	bl animate_battle_scroll_tiles
	ldr r0, _0806430C @ =0x03006F74
	ldr r1, [r0]
	ldrh r0, [r1, #0x3c]
	subs r0, #1
	strh r0, [r1, #0x3c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08064314
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r1, #0x3a]
	ldr r1, _08064310 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08064354
	.align 2, 0
_0806430C: .4byte 0x03006F74
_08064310: .4byte 0x0300137C
_08064314:
	cmp r0, #7
	bgt _0806432C
	ldr r2, _08064328 @ =0x03002C30
	movs r0, #0x3c
	ldrsh r1, [r1, r0]
	lsls r1, r1, #3
	movs r0, #0x40
	subs r0, r0, r1
	strb r0, [r2, #8]
	b _08064334
	.align 2, 0
_08064328: .4byte 0x03002C30
_0806432C:
	ldr r1, _08064358 @ =0x03002C30
	movs r0, #1
	strb r0, [r1, #8]
	adds r2, r1, #0
_08064334:
	ldr r0, _0806435C @ =0x03006F74
	ldr r1, [r0]
	movs r3, #0x3c
	ldrsh r0, [r1, r3]
	cmp r0, #1
	ble _08064354
	lsls r0, r0, #2
	adds r0, #0x38
	strb r0, [r2, #9]
	movs r0, #0x3c
	ldrsh r1, [r1, r0]
	subs r1, #2
	lsls r1, r1, #3
	movs r0, #0x38
	subs r0, r0, r1
	strh r0, [r2, #4]
_08064354:
	pop {r0}
	bx r0
	.align 2, 0
_08064358: .4byte 0x03002C30
_0806435C: .4byte 0x03006F74
	.syntax divided
