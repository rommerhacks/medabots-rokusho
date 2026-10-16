	.syntax unified

	non_word_aligned_thumb_func_start sub_0801615A
sub_0801615A: @ 0x0801615A
	push {r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r1, #0
	movs r0, #0
	mov sb, r0
	ldr r3, _08016180 @ =0x03002C30
	lsls r1, r7, #6
	adds r1, r1, r3
	ldrh r2, [r1]
	ldr r0, _08016184 @ =0x0000FFDF
	ands r0, r2
	strh r0, [r1]
	adds r5, r3, #0
	cmp r4, #0
	bne _0801618C
	ldr r0, _08016188 @ =0x083AD376
	b _0801618E
	.align 2, 0
_08016180: .4byte 0x03002C30
_08016184: .4byte 0x0000FFDF
_08016188: .4byte 0x083AD376
_0801618C:
	ldr r0, _080161B0 @ =0x083AD37C
_0801618E:
	ldr r1, _080161B4 @ =0x03001800
	adds r1, #0x81
	ldrb r1, [r1]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r3, r7, r0
	cmp r3, #5
	bls _080161A0
	adds r3, #6
_080161A0:
	cmp r4, #0
	bne _080161B8
	lsls r2, r7, #6
	adds r1, r2, r5
	adds r1, #0x20
	ldrb r0, [r1]
	adds r0, #6
	b _080161C2
	.align 2, 0
_080161B0: .4byte 0x083AD37C
_080161B4: .4byte 0x03001800
_080161B8:
	lsls r2, r7, #6
	adds r1, r2, r5
	adds r1, #0x20
	ldrb r0, [r1]
	subs r0, #6
_080161C2:
	strb r0, [r1]
	adds r6, r2, #0
	ldr r0, _08016228 @ =0x03002C30
	adds r4, r6, r0
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	adds r0, #1
	movs r5, #0
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _080161F4
	movs r1, #1
	mov sb, r1
	ldr r0, _0801622C @ =0x083AD370
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x20
	strb r1, [r0]
	strb r5, [r2]
	adds r0, #2
	strb r5, [r0]
_080161F4:
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r1, [r0]
	movs r0, #0x80
	str r0, [sp]
	movs r2, #8
	mov r8, r2
	str r2, [sp, #4]
	str r5, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0x18
	movs r3, #0x78
	bl compute_polar_to_screen_position
	ldr r0, [sp, #0xc]
	strh r0, [r4, #2]
	asrs r0, r0, #0x10
	strh r0, [r4, #4]
	ldr r2, _08016230 @ =0x0000060C
	adds r1, r7, r2
	strh r1, [r4, #6]
	cmp r0, #0x87
	ble _08016234
	mov r0, r8
	b _0801623E
	.align 2, 0
_08016228: .4byte 0x03002C30
_0801622C: .4byte 0x083AD370
_08016230: .4byte 0x0000060C
_08016234:
	cmp r0, #0x7b
	ble _0801623C
	movs r0, #9
	b _0801623E
_0801623C:
	movs r0, #0xa
_0801623E:
	strb r0, [r4, #0xa]
	ldr r3, _08016284 @ =0x03002C30
	adds r3, r6, r3
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r1, #4
	ldrsh r0, [r3, r1]
	movs r1, #0x90
	subs r0, r1, r0
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	movs r2, #0x40
	subs r0, r2, r0
	strb r0, [r3, #9]
	movs r4, #4
	ldrsh r0, [r3, r4]
	subs r1, r1, r0
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	subs r2, r2, r1
	strb r2, [r3, #8]
	ldrb r0, [r3, #4]
	subs r0, #0x70
	strb r0, [r3, #0xb]
	mov r0, sb
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016284: .4byte 0x03002C30
	.syntax divided
