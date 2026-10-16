	.syntax unified

	thumb_func_start set_oam_affine_params
set_oam_affine_params: @ 0x08001CAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	adds r4, r1, #0
	mov sl, r2
	mov sb, r3
	ldr r5, [sp, #0x24]
	lsls r0, r0, #2
	mov r8, r0
	ldr r1, _08001D24 @ =0x03005048
	ldr r3, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne _08001DB8
	ldr r2, _08001D28 @ =0x080750E0
	ldr r1, _08001D2C @ =0x000003FF
	ands r1, r4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r1, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r7, [r0, r4]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r6, [r1, r0]
	mov r1, sl
	cmp r1, #0
	bne _08001CF8
	movs r2, #1
	mov sl, r2
_08001CF8:
	mov r3, sb
	cmp r3, #0
	bne _08001D02
	movs r4, #1
	mov sb, r4
_08001D02:
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq _08001D34
	rsbs r1, r7, #0
	mov r0, sl
	bl DivArm
	ldr r4, _08001D30 @ =0x03001380
	ldr r2, [sp]
	lsls r1, r2, #5
	adds r1, r1, r4
	strh r0, [r1, #6]
	rsbs r1, r6, #0
	mov r0, sb
	b _08001D4A
	.align 2, 0
_08001D24: .4byte 0x03005048
_08001D28: .4byte 0x080750E0
_08001D2C: .4byte 0x000003FF
_08001D30: .4byte 0x03001380
_08001D34:
	mov r0, sl
	adds r1, r7, #0
	bl DivArm
	ldr r4, _08001D88 @ =0x03001380
	ldr r3, [sp]
	lsls r1, r3, #5
	adds r1, r1, r4
	strh r0, [r1, #6]
	mov r0, sb
	adds r1, r6, #0
_08001D4A:
	bl DivArm
	mov r1, r8
	adds r1, #1
	lsls r1, r1, #3
	adds r1, r1, r4
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r5, r0
	cmp r5, #0
	beq _08001D8C
	mov r0, sl
	adds r1, r6, #0
	bl DivArm
	ldr r4, _08001D88 @ =0x03001380
	mov r1, r8
	adds r1, #2
	lsls r1, r1, #3
	adds r1, r1, r4
	strh r0, [r1, #6]
	rsbs r1, r7, #0
	mov r0, sb
	bl DivArm
	mov r1, r8
	adds r1, #3
	lsls r1, r1, #3
	adds r1, r1, r4
	b _08001E8E
	.align 2, 0
_08001D88: .4byte 0x03001380
_08001D8C:
	mov r0, sb
	adds r1, r7, #0
	bl DivArm
	ldr r4, _08001DB4 @ =0x03001380
	mov r1, r8
	adds r1, #3
	lsls r1, r1, #3
	adds r1, r1, r4
	strh r0, [r1, #6]
	rsbs r1, r6, #0
	mov r0, sl
	bl DivArm
	mov r1, r8
	adds r1, #2
	lsls r1, r1, #3
	adds r1, r1, r4
	b _08001E8E
	.align 2, 0
_08001DB4: .4byte 0x03001380
_08001DB8:
	ldr r2, _08001DFC @ =0x080750E0
	ldr r1, _08001E00 @ =0x000003FF
	ands r1, r4
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r1, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r7, r0, #8
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r6, r0, #8
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r5
	cmp r0, #0
	beq _08001E0C
	rsbs r1, r7, #0
	adds r0, r3, #0
	bl DivArm
	ldr r4, _08001E04 @ =0x03001380
	ldr r3, [sp]
	lsls r1, r3, #5
	adds r1, r1, r4
	strh r0, [r1, #6]
	ldr r1, _08001E08 @ =0x03005048
	ldr r0, [r1]
	rsbs r1, r6, #0
	b _08001E24
	.align 2, 0
_08001DFC: .4byte 0x080750E0
_08001E00: .4byte 0x000003FF
_08001E04: .4byte 0x03001380
_08001E08: .4byte 0x03005048
_08001E0C:
	adds r0, r3, #0
	adds r1, r7, #0
	bl DivArm
	ldr r4, _08001E60 @ =0x03001380
	ldr r2, [sp]
	lsls r1, r2, #5
	adds r1, r1, r4
	strh r0, [r1, #6]
	ldr r3, _08001E64 @ =0x03005048
	ldr r0, [r3]
	adds r1, r6, #0
_08001E24:
	bl DivArm
	mov r1, r8
	adds r1, #1
	lsls r1, r1, #3
	adds r1, r1, r4
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #6
	ands r5, r0
	cmp r5, #0
	beq _08001E68
	ldr r4, _08001E64 @ =0x03005048
	ldr r0, [r4]
	adds r1, r6, #0
	bl DivArm
	ldr r5, _08001E60 @ =0x03001380
	mov r1, r8
	adds r1, #2
	lsls r1, r1, #3
	adds r1, r1, r5
	strh r0, [r1, #6]
	ldr r0, [r4]
	rsbs r1, r7, #0
	bl DivArm
	mov r1, r8
	adds r1, #3
	b _08001E8A
	.align 2, 0
_08001E60: .4byte 0x03001380
_08001E64: .4byte 0x03005048
_08001E68:
	ldr r4, _08001EA0 @ =0x03005048
	ldr r0, [r4]
	adds r1, r7, #0
	bl DivArm
	ldr r5, _08001EA4 @ =0x03001380
	mov r1, r8
	adds r1, #3
	lsls r1, r1, #3
	adds r1, r1, r5
	strh r0, [r1, #6]
	ldr r0, [r4]
	rsbs r1, r6, #0
	bl DivArm
	mov r1, r8
	adds r1, #2
_08001E8A:
	lsls r1, r1, #3
	adds r1, r1, r5
_08001E8E:
	strh r0, [r1, #6]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08001EA0: .4byte 0x03005048
_08001EA4: .4byte 0x03001380
	.syntax divided
