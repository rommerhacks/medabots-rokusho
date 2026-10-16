	.syntax unified

	thumb_func_start update_entity_sprites_on_screen
	.global update_entity_sprites_on_screen
update_entity_sprites_on_screen: @ 0x08052738
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08052824 @ =0x03002C30
	movs r1, #0xb6
	lsls r1, r1, #5
	adds r2, r0, r1
	str r2, [sp]
	mov ip, r1
	ldr r4, _08052828 @ =0x00000C6E
	adds r4, r0, r4
	str r4, [sp, #4]
	movs r1, #0xc4
	lsls r1, r1, #4
	adds r7, r0, r1
	mov sl, r1
	movs r6, #0x31
	mov sb, r6
	movs r0, #0x23
	mov r8, r0
_08052766:
	mov r1, sb
	lsls r0, r1, #2
	ldr r2, _0805282C @ =0x030055A0
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08052776
	b _08052874
_08052776:
	movs r3, #0
	ldr r4, _08052830 @ =0x03004C30
	movs r6, #2
	ldrsh r2, [r4, r6]
	ldr r1, [r7, #0x10]
	asrs r1, r1, #8
	ldr r5, _08052834 @ =0x030057E0
	ldr r6, _08052838 @ =0x00000C4A
	adds r0, r5, r6
	ldrh r0, [r0]
	subs r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x10
	ldr r6, _08052824 @ =0x03002C30
	cmp r2, r0
	bge _080527C0
	adds r0, r2, #0
	adds r0, #0xa8
	cmp r1, r0
	bge _080527C0
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldr r1, [r7, #0xc]
	asrs r1, r1, #8
	ldr r4, _0805283C @ =0x00000C48
	adds r0, r5, r4
	ldrh r0, [r0]
	subs r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x10
	cmp r2, r0
	bge _080527C0
	adds r0, r2, #0
	adds r0, #0xf0
	cmp r1, r0
	bge _080527C0
	movs r3, #1
_080527C0:
	cmp r3, #0
	beq _08052868
	mov r0, sl
	adds r3, r0, r6
	adds r0, r3, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	beq _08052854
	ldrh r0, [r3, #0x32]
	movs r2, #0
	strh r0, [r3]
	adds r1, r3, #0
	adds r1, #0x2e
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3, #0xc]
	asrs r0, r0, #8
	ldr r4, _08052830 @ =0x03004C30
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldr r0, [r3, #0x10]
	asrs r0, r0, #8
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _08052840 @ =0x083D2B8D
	ldrh r0, [r3, #0x30]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _0805284C
	mov r0, ip
	adds r2, r0, r6
	ldr r0, _08052844 @ =0x0000CC0C
	strh r0, [r2]
	ldrh r0, [r3, #2]
	strh r0, [r2, #2]
	adds r0, r3, #0
	adds r0, #0x2c
	ldr r4, _08052848 @ =0x0000FFFB
	adds r1, r4, #0
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	b _08052874
	.align 2, 0
_08052824: .4byte 0x03002C30
_08052828: .4byte 0x00000C6E
_0805282C: .4byte 0x030055A0
_08052830: .4byte 0x03004C30
_08052834: .4byte 0x030057E0
_08052838: .4byte 0x00000C4A
_0805283C: .4byte 0x00000C48
_08052840: .4byte 0x083D2B8D
_08052844: .4byte 0x0000CC0C
_08052848: .4byte 0x0000FFFB
_0805284C:
	mov r2, ip
	adds r0, r2, r6
	strh r1, [r0]
	b _08052874
_08052854:
	movs r4, #0
	strh r4, [r3]
	adds r0, r3, #0
	adds r0, #0x2e
	movs r1, #0
	strb r1, [r0]
	mov r2, ip
	adds r0, r2, r6
	strh r4, [r0]
	b _08052874
_08052868:
	strh r3, [r7]
	movs r0, #0
	ldr r6, [sp, #4]
	strb r0, [r6]
	ldr r1, [sp]
	strh r3, [r1]
_08052874:
	ldr r2, [sp]
	adds r2, #0x40
	str r2, [sp]
	movs r4, #0x40
	add ip, r4
	ldr r6, [sp, #4]
	adds r6, #0x40
	str r6, [sp, #4]
	adds r7, #0x40
	add sl, r4
	movs r0, #1
	add sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	blt _0805289A
	b _08052766
_0805289A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
