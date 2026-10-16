	.syntax unified

	thumb_func_start sub_0806B068
sub_0806B068: @ 0x0806B068
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	ldr r1, _0806B0A4 @ =0x03002C30
	lsls r0, r3, #6
	adds r1, r0, r1
	ldrh r0, [r1, #0x1a]
	cmp r0, #0xf
	bhi _0806B082
	ldrh r0, [r1, #4]
	adds r0, #2
	strh r0, [r1, #4]
_0806B082:
	ldrh r2, [r1, #0x1a]
	adds r0, r2, #0
	subs r0, #0xd2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0806B096
	ldrh r0, [r1, #4]
	subs r0, #2
	strh r0, [r1, #4]
_0806B096:
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe1
	bhi _0806B0A8
	movs r0, #1
	b _0806B0B0
	.align 2, 0
_0806B0A4: .4byte 0x03002C30
_0806B0A8:
	adds r0, r3, #0
	bl sub_0806B584
	movs r0, #0
_0806B0B0:
	pop {r1}
	bx r1
	.syntax divided
