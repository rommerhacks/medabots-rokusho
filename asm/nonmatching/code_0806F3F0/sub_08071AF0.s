	.syntax unified

	thumb_func_start sub_08071AF0
sub_08071AF0: @ 0x08071AF0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _08071B40 @ =0x03002C30
	lsls r0, r5, #6
	adds r4, r0, r2
	ldrh r1, [r4, #2]
	adds r1, #1
	strh r1, [r4, #2]
	adds r0, r5, #4
	lsls r0, r0, #6
	adds r0, r0, r2
	strh r1, [r0, #2]
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x1a]
	cmp r0, r1
	bhi _08071B36
	ldrh r0, [r4, #6]
	movs r1, #0xc
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x12
	lsrs r1, r1, #0x10
	adds r1, #3
	strh r1, [r4, #0x30]
	strh r1, [r4, #6]
	movs r0, #8
	adds r1, r5, #0
	movs r2, #0
	bl sub_08071C40
_08071B36:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08071B40: .4byte 0x03002C30
	.syntax divided
