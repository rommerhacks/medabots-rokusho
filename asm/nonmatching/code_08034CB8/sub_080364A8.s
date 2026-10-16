	.syntax unified

	thumb_func_start sub_080364A8
	.global sub_080364A8
sub_080364A8: @ 0x080364A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r2, #6
	mov sb, r2
	cmp r0, #0
	bne _080364C0
	movs r0, #0x14
	mov sb, r0
_080364C0:
	ldr r0, _08036504 @ =0x03000590
	lsls r1, r1, #8
	adds r4, r1, r0
	adds r2, r4, #0
	adds r2, #0x59
	ldrb r0, [r2]
	mov sl, r1
	cmp r0, #0
	beq _08036510
	ldr r6, _08036508 @ =0x0400000A
	ldrh r1, [r6]
	str r1, [sp]
	ldr r5, _0803650C @ =0x0000A330
	str r5, [sp, #4]
	mov r1, sb
	movs r2, #2
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r4, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	mov r4, sb
	adds r4, #4
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	adds r1, r4, #0
	movs r2, #2
	movs r3, #3
	bl divide_by_100000_08042838
	b _08036540
	.align 2, 0
_08036504: .4byte 0x03000590
_08036508: .4byte 0x0400000A
_0803650C: .4byte 0x0000A330
_08036510:
	ldrb r0, [r2]
	ldr r6, _08036584 @ =0x0400000A
	ldrh r1, [r6]
	str r1, [sp]
	ldr r5, _08036588 @ =0x00008330
	str r5, [sp, #4]
	mov r1, sb
	movs r2, #2
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r4, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	mov r4, sb
	adds r4, #4
	ldrh r1, [r6]
	str r1, [sp]
	str r5, [sp, #4]
	adds r1, r4, #0
	movs r2, #2
	movs r3, #3
	bl divide_by_100000_08042838
_08036540:
	mov r8, r4
	ldr r0, _0803658C @ =0x03000590
	mov r1, sl
	adds r7, r1, r0
	adds r1, r7, #0
	adds r1, #0x71
	ldrb r0, [r1]
	cmp r0, #0
	beq _08036594
	movs r6, #2
	adds r6, #3
	ldr r5, _08036584 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _08036590 @ =0x0000A330
	str r4, [sp, #4]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r7, #0
	adds r0, #0x64
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	mov r1, r8
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	b _080365C4
	.align 2, 0
_08036584: .4byte 0x0400000A
_08036588: .4byte 0x00008330
_0803658C: .4byte 0x03000590
_08036590: .4byte 0x0000A330
_08036594:
	ldrb r0, [r1]
	movs r6, #2
	adds r6, #3
	ldr r5, _08036604 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _08036608 @ =0x00008330
	str r4, [sp, #4]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r7, #0
	adds r0, #0x64
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	mov r1, r8
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
_080365C4:
	ldr r0, _0803660C @ =0x03000590
	mov r2, sl
	adds r7, r2, r0
	adds r1, r7, #0
	adds r1, #0x89
	ldrb r0, [r1]
	cmp r0, #0
	beq _08036614
	movs r6, #2
	adds r6, #6
	ldr r5, _08036604 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _08036610 @ =0x0000A330
	str r4, [sp, #4]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r7, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	mov r1, r8
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	b _08036644
	.align 2, 0
_08036604: .4byte 0x0400000A
_08036608: .4byte 0x00008330
_0803660C: .4byte 0x03000590
_08036610: .4byte 0x0000A330
_08036614:
	ldrb r0, [r1]
	movs r6, #2
	adds r6, #6
	ldr r5, _08036684 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _08036688 @ =0x00008330
	str r4, [sp, #4]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r7, #0
	adds r0, #0x7c
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	mov r1, r8
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
_08036644:
	ldr r0, _0803668C @ =0x03000590
	mov r1, sl
	adds r7, r1, r0
	adds r1, r7, #0
	adds r1, #0xa1
	ldrb r0, [r1]
	cmp r0, #0
	beq _08036694
	movs r6, #2
	adds r6, #9
	ldr r5, _08036684 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _08036690 @ =0x0000A330
	str r4, [sp, #4]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r7, #0
	adds r0, #0x94
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	mov r1, r8
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	b _080366C4
	.align 2, 0
_08036684: .4byte 0x0400000A
_08036688: .4byte 0x00008330
_0803668C: .4byte 0x03000590
_08036690: .4byte 0x0000A330
_08036694:
	ldrb r0, [r1]
	movs r6, #2
	adds r6, #9
	ldr r5, _080366D4 @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _080366D8 @ =0x00008330
	str r4, [sp, #4]
	mov r1, sb
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
	adds r0, r7, #0
	adds r0, #0x94
	ldrb r0, [r0]
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	mov r1, r8
	adds r2, r6, #0
	movs r3, #3
	bl divide_by_100000_08042838
_080366C4:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080366D4: .4byte 0x0400000A
_080366D8: .4byte 0x00008330
	.syntax divided
