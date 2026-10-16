	.syntax unified

	thumb_func_start set_bg2_affine_transform
set_bg2_affine_transform: @ 0x080010B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	mov sl, r2
	adds r7, r3, #0
	ldr r0, _08001174 @ =0x080750E0
	mov r8, r0
	ldr r0, _08001178 @ =0x000003FF
	ands r4, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r4, r1
	lsls r5, r5, #1
	add r5, r8
	movs r2, #0
	ldrsh r0, [r5, r2]
	lsls r0, r0, #2
	adds r1, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #1
	add r4, r8
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r1, r6, #0
	bl Div
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	rsbs r0, r0, #0
	lsls r0, r0, #2
	adds r1, r6, #0
	bl Div
	adds r4, r0, #0
	movs r2, #0
	ldrsh r0, [r5, r2]
	lsls r0, r0, #2
	adds r1, r6, #0
	bl Div
	ldr r1, _0800117C @ =0x04000030
	mov r3, sb
	strh r3, [r1]
	adds r1, #2
	mov r2, r8
	strh r2, [r1]
	adds r1, #2
	strh r4, [r1]
	adds r1, #2
	strh r0, [r1]
	ldr r3, [sp, #0x20]
	mov r1, sb
	muls r1, r3, r1
	rsbs r1, r1, #0
	ldr r3, [sp, #0x24]
	mov r2, r8
	muls r2, r3, r2
	subs r1, r1, r2
	mov r2, sl
	subs r1, r1, r2
	ldr r3, [sp, #0x20]
	adds r2, r4, #0
	muls r2, r3, r2
	rsbs r2, r2, #0
	ldr r3, [sp, #0x24]
	muls r0, r3, r0
	subs r2, r2, r0
	subs r2, r2, r7
	ldr r0, _08001180 @ =0x04000038
	strh r1, [r0]
	adds r0, #2
	ldr r3, _08001184 @ =0x0FFF0000
	ands r1, r3
	asrs r1, r1, #0x10
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	ands r2, r3
	asrs r2, r2, #0x10
	strh r2, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001174: .4byte 0x080750E0
_08001178: .4byte 0x000003FF
_0800117C: .4byte 0x04000030
_08001180: .4byte 0x04000038
_08001184: .4byte 0x0FFF0000
	.syntax divided
