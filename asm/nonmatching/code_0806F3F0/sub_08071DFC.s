	.syntax unified

	thumb_func_start sub_08071DFC
sub_08071DFC: @ 0x08071DFC
	push {r4, r5, lr}
	ldr r4, _08071E18 @ =0x03002C30
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #0x3d
	bgt _08071E1C
	adds r0, #2
	strh r0, [r2]
	b _08071E78
	.align 2, 0
_08071E18: .4byte 0x03002C30
_08071E1C:
	cmp r1, #0x41
	bgt _08071E26
	adds r0, #1
	strh r0, [r2]
	b _08071E78
_08071E26:
	movs r0, #0xad
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x1f
	bhi _08071E38
	adds r0, #1
	strh r0, [r5]
	b _08071E78
_08071E38:
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x40
	bgt _08071E74
	movs r0, #9
	bl sub_0806B584
	movs r0, #0x54
	bl play_sound_effect
	ldr r0, _08071E6C @ =0x0000014B
	adds r2, r4, r0
	movs r1, #0
	movs r0, #0x21
	strb r0, [r2]
	strh r1, [r5]
	ldr r1, _08071E70 @ =0x03001800
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	movs r0, #1
	b _08071E7A
	.align 2, 0
_08071E6C: .4byte 0x0000014B
_08071E70: .4byte 0x03001800
_08071E74:
	subs r0, r2, #4
	strh r0, [r1]
_08071E78:
	movs r0, #0
_08071E7A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
