	.syntax unified

	thumb_func_start update_scroll_animation_tiles
	.global update_scroll_animation_tiles
update_scroll_animation_tiles: @ 0x08062C84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08062CAC @ =0x03006F74
	ldr r2, [r0]
	movs r3, #0x3a
	ldrsh r1, [r2, r3]
	adds r3, r0, #0
	cmp r1, #0
	bge _08062C9A
	adds r1, #0x7f
_08062C9A:
	asrs r0, r1, #7
	cmp r0, #4
	bhi _08062CF0
	lsls r0, r0, #2
	ldr r1, _08062CB0 @ =_08062CB4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062CAC: .4byte 0x03006F74
_08062CB0: .4byte _08062CB4
_08062CB4: @ jump table
	.4byte _08062CC8 @ case 0
	.4byte _08062CC8 @ case 1
	.4byte _08062CD2 @ case 2
	.4byte _08062CDC @ case 3
	.4byte _08062CE6 @ case 4
_08062CC8:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x15
	b _08062CF6
_08062CD2:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	b _08062CF6
_08062CDC:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x13
	b _08062CF6
_08062CE6:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x12
	b _08062CF6
_08062CF0:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
_08062CF6:
	movs r0, #3
	ands r1, r0
	ldr r2, [r3]
	ldrh r0, [r2, #0x3a]
	subs r0, #1
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08062D0C
	movs r0, #0x3f
	strh r0, [r2, #0x3a]
_08062D0C:
	movs r6, #0
	adds r0, r1, #2
	mov r8, r0
	ldr r7, _08062D54 @ =0x0600D800
	movs r5, #0xe0
	lsls r5, r5, #1
	lsls r4, r1, #9
_08062D1A:
	adds r0, r4, r7
	ldr r2, _08062D58 @ =0x0600E804
	adds r1, r5, r2
	movs r2, #0xc
	bl CpuSet
	movs r0, #3
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #3
	adds r0, r0, r6
	lsls r0, r0, #6
	adds r0, r0, r7
	ldr r2, _08062D5C @ =0x0600E820
	adds r1, r5, r2
	movs r2, #0xc
	bl CpuSet
	adds r5, #0x40
	adds r4, #0x40
	adds r6, #1
	cmp r6, #7
	ble _08062D1A
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062D54: .4byte 0x0600D800
_08062D58: .4byte 0x0600E804
_08062D5C: .4byte 0x0600E820
	.syntax divided
