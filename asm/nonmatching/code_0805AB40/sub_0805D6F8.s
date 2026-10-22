	.syntax unified

	thumb_func_start sub_0805D6F8
sub_0805D6F8: @ 0x0805D6F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r7, #0
	movs r4, #0x80
	ldr r3, _0805D874 @ =0x03000BE0
	movs r2, #0x1d
_0805D708:
	ldrb r1, [r3]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0805D714
	adds r7, #1
_0805D714:
	adds r3, #0x40
	subs r2, #1
	cmp r2, #0
	bge _0805D708
	movs r0, #0xa
	str r0, [sp]
	ldr r0, _0805D878 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #2
	movs r2, #0xa
	movs r3, #4
	bl draw_number
	movs r7, #0
	ldr r1, _0805D87C @ =0x03004C40
	movs r2, #0xf0
	lsls r2, r2, #1
_0805D740:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0805D748
	adds r7, #1
_0805D748:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0805D740
	movs r0, #0xb
	str r0, [sp]
	ldr r6, _0805D878 @ =0x0400000A
	ldrh r0, [r6]
	lsrs r0, r0, #8
	movs r5, #0x1f
	ands r0, r5
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #3
	movs r2, #9
	movs r3, #6
	bl draw_number
	ldr r4, _0805D880 @ =0x03002B70
	ldr r0, [r4, #0x18]
	movs r1, #0xe1
	lsls r1, r1, #4
	bl sub_0807CD58
	adds r7, r0, #0
	movs r1, #0x3c
	bl sub_0807CBBC
	movs r1, #0xc
	mov r8, r1
	str r1, [sp]
	ldrh r1, [r6]
	lsrs r1, r1, #8
	ands r1, r5
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #7
	movs r3, #8
	bl draw_number
	adds r0, r7, #0
	movs r1, #0x3c
	bl sub_0807CC88
	movs r1, #2
	rsbs r1, r1, #0
	mov r2, r8
	str r2, [sp]
	ldrh r2, [r6]
	lsrs r2, r2, #8
	ands r2, r5
	str r2, [sp, #4]
	movs r2, #0xa
	movs r3, #8
	bl draw_number
	ldrh r0, [r4, #0x16]
	movs r1, #0xd
	mov r8, r1
	str r1, [sp]
	ldrh r1, [r6]
	lsrs r1, r1, #8
	ands r1, r5
	str r1, [sp, #4]
	movs r1, #4
	movs r2, #3
	movs r3, #0xb
	bl draw_number
	ldrh r0, [r4, #0x14]
	mov r2, r8
	str r2, [sp]
	ldrh r1, [r6]
	lsrs r1, r1, #8
	ands r1, r5
	str r1, [sp, #4]
	movs r1, #0
	movs r2, #8
	movs r3, #0xb
	bl draw_number
	ldr r6, _0805D884 @ =0x030004DE
	ldm r4!, {r1}
	adds r0, r6, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0xf
	movs r3, #9
	bl render_text_sprites_08040DB8
	movs r0, #0xa
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #0xe
	movs r3, #4
	bl render_text_sprites_08040DB8
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r0, _0805D888 @ =0x0878CA64
	ldr r1, _0805D88C @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _0805D890 @ =0x0850DCF8
	ldr r1, _0805D894 @ =0x0202F9A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805D898 @ =0x084E2E38
	ldr r1, _0805D89C @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0805D8A0 @ =0x080AF7E8
	ldr r1, _0805D8A4 @ =0x0202F800
	movs r2, #8
	bl CpuFastSet
	subs r6, #0x1a
	strb r5, [r6]
	ldr r1, _0805D8A8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805D874: .4byte 0x03000BE0
_0805D878: .4byte 0x0400000A
_0805D87C: .4byte 0x03004C40
_0805D880: .4byte 0x03002B70
_0805D884: .4byte 0x030004DE
_0805D888: .4byte 0x0878CA64
_0805D88C: .4byte 0x0202FA00
_0805D890: .4byte 0x0850DCF8
_0805D894: .4byte 0x0202F9A0
_0805D898: .4byte 0x084E2E38
_0805D89C: .4byte 0x0202F9E0
_0805D8A0: .4byte 0x080AF7E8
_0805D8A4: .4byte 0x0202F800
_0805D8A8: .4byte 0x0300137C
	.syntax divided
