	.syntax unified

	thumb_func_start compute_scaled_value
compute_scaled_value: @ 0x08001EA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov ip, r1
	mov sb, r2
	mov r8, r3
	lsls r6, r4, #2
	ldr r0, _08001EF0 @ =0x03005048
	ldr r2, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	mov sl, r0
	cmp r2, r1
	bne _08001F4E
	movs r7, #0x80
	lsls r7, r7, #5
	ands r7, r3
	cmp r7, #0
	beq _08001EFC
	ldr r5, _08001EF4 @ =0x03001380
	lsls r4, r4, #5
	adds r4, r4, r5
	ldr r0, _08001EF8 @ =0xFFFFC000
	mov r1, ip
	bl sub_0807CBBC
	movs r1, #0
	strh r0, [r4, #6]
	adds r0, r6, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	strh r1, [r0, #6]
	b _08001F16
	.align 2, 0
_08001EF0: .4byte 0x03005048
_08001EF4: .4byte 0x03001380
_08001EF8: .4byte 0xFFFFC000
_08001EFC:
	ldr r5, _08001F38 @ =0x03001380
	lsls r4, r4, #5
	adds r4, r4, r5
	movs r0, #0x80
	lsls r0, r0, #7
	mov r1, ip
	bl sub_0807CBBC
	strh r0, [r4, #6]
	adds r0, r6, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	strh r7, [r0, #6]
_08001F16:
	movs r7, #0x80
	lsls r7, r7, #6
	mov r0, r8
	ands r7, r0
	cmp r7, #0
	beq _08001F40
	adds r0, r6, #2
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0, #6]
	adds r4, r6, #3
	lsls r4, r4, #3
	adds r4, r4, r5
	ldr r0, _08001F3C @ =0xFFFFC000
	mov r1, sb
	b _08001FBC
	.align 2, 0
_08001F38: .4byte 0x03001380
_08001F3C: .4byte 0xFFFFC000
_08001F40:
	adds r4, r6, #3
	lsls r4, r4, #3
	adds r4, r4, r5
	movs r0, #0x80
	lsls r0, r0, #7
	mov r1, sb
	b _08001FDA
_08001F4E:
	movs r7, #0x80
	lsls r7, r7, #5
	mov r0, r8
	ands r7, r0
	cmp r7, #0
	beq _08001F80
	ldr r5, _08001F78 @ =0x03001380
	lsls r4, r4, #5
	adds r4, r4, r5
	ldr r0, _08001F7C @ =0xFFC00000
	adds r1, r2, #0
	bl sub_0807CBBC
	movs r1, #0
	strh r0, [r4, #6]
	adds r0, r6, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	strh r1, [r0, #6]
	b _08001F9A
	.align 2, 0
_08001F78: .4byte 0x03001380
_08001F7C: .4byte 0xFFC00000
_08001F80:
	ldr r5, _08001FC4 @ =0x03001380
	lsls r4, r4, #5
	adds r4, r4, r5
	movs r0, #0x80
	lsls r0, r0, #0xf
	adds r1, r2, #0
	bl sub_0807CBBC
	strh r0, [r4, #6]
	adds r0, r6, #1
	lsls r0, r0, #3
	adds r0, r0, r5
	strh r7, [r0, #6]
_08001F9A:
	movs r7, #0x80
	lsls r7, r7, #6
	mov r0, r8
	ands r7, r0
	cmp r7, #0
	beq _08001FCC
	adds r0, r6, #2
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0, #6]
	adds r4, r6, #3
	lsls r4, r4, #3
	adds r4, r4, r5
	mov r0, sl
	ldr r1, [r0]
	ldr r0, _08001FC8 @ =0xFFC00000
_08001FBC:
	bl sub_0807CBBC
	strh r0, [r4, #6]
	b _08001FE8
	.align 2, 0
_08001FC4: .4byte 0x03001380
_08001FC8: .4byte 0xFFC00000
_08001FCC:
	adds r4, r6, #3
	lsls r4, r4, #3
	adds r4, r4, r5
	mov r0, sl
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
_08001FDA:
	bl sub_0807CBBC
	strh r0, [r4, #6]
	adds r0, r6, #2
	lsls r0, r0, #3
	adds r0, r0, r5
	strh r7, [r0, #6]
_08001FE8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
