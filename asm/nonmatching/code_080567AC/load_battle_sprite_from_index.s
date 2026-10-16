	.syntax unified

	thumb_func_start load_battle_sprite_from_index
load_battle_sprite_from_index: @ 0x080595E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sb, r0
	str r1, [sp, #0x14]
	adds r4, r2, #0
	str r3, [sp, #0x18]
	ldr r1, _0805961C @ =0x080AC5A4
	add r0, sp, #4
	movs r2, #0x10
	bl memcpy_optimized
	movs r0, #0
	mov sl, r0
	movs r0, #0xff
	lsls r0, r0, #8
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #0x10
	str r0, [sp, #0x1c]
	str r4, [sp, #0x20]
	ldr r6, _08059620 @ =0x030057A0
	b _0805973C
	.align 2, 0
_0805961C: .4byte 0x080AC5A4
_08059620: .4byte 0x030057A0
_08059624:
	cmp r0, #4
	bne _08059654
	mov r2, sl
	cmp r2, #0
	bne _08059632
	mov r0, sb
	lsrs r7, r0, #0x18
_08059632:
	mov r1, sl
	cmp r1, #1
	bne _08059642
	movs r0, #0xff
	lsls r0, r0, #0x10
	mov r2, sb
	ands r0, r2
	lsrs r7, r0, #0x10
_08059642:
	mov r0, sl
	cmp r0, #2
	bne _0805964C
	ldr r1, [sp, #0x1c]
	lsrs r7, r1, #0x18
_0805964C:
	mov r2, sl
	cmp r2, #3
	bne _0805967E
	b _08059678
_08059654:
	cmp r0, #2
	bne _0805966E
	mov r2, sl
	cmp r2, #0
	bne _08059662
	ldr r0, [sp, #0x1c]
	lsrs r7, r0, #0x18
_08059662:
	mov r1, sl
	cmp r1, #1
	bne _0805967E
	mov r2, sb
	lsls r0, r2, #0x18
	b _0805967C
_0805966E:
	cmp r0, #1
	bne _0805967E
	mov r0, sl
	cmp r0, #0
	bne _0805967E
_08059678:
	mov r1, sb
	lsls r0, r1, #0x18
_0805967C:
	lsrs r7, r0, #0x18
_0805967E:
	lsrs r0, r7, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #4
	subs r4, r7, r4
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	add r0, sp
	adds r0, #4
	ldrb r0, [r0]
	lsls r0, r0, #5
	ldr r2, _0805975C @ =0x080ACB7C
	adds r0, r0, r2
	ldr r1, _08059760 @ =0x040000D4
	str r0, [r1]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #5
	ldr r2, _08059764 @ =0x06017A00
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _08059768 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r6, #0x13]
	adds r2, r0, #0
	adds r2, #0x99
	movs r1, #1
	mov r8, r1
	str r1, [sp]
	ldr r1, _0805976C @ =0x0000C004
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	ldr r5, _08059770 @ =0x03002C30
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #6
	adds r0, r0, r5
	mov r2, sp
	ldrh r2, [r2, #0x20]
	strh r2, [r0, #2]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #6
	adds r0, r0, r5
	mov r1, sp
	ldrh r1, [r1, #0x18]
	strh r1, [r0, #4]
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	mov r0, sp
	adds r0, r0, r4
	adds r0, #4
	ldrb r0, [r0]
	lsls r0, r0, #5
	ldr r2, _0805975C @ =0x080ACB7C
	adds r0, r0, r2
	ldr r1, _08059760 @ =0x040000D4
	str r0, [r1]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #5
	ldr r2, _08059764 @ =0x06017A00
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _08059768 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r6, #0x13]
	adds r2, r0, #0
	adds r2, #0x99
	mov r1, r8
	str r1, [sp]
	ldr r1, _0805976C @ =0x0000C004
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldr r1, [sp, #0x20]
	adds r1, #8
	strh r1, [r0, #2]
	ldrb r0, [r6, #0x13]
	lsls r0, r0, #6
	adds r0, r0, r5
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0, #4]
	ldrb r0, [r6, #0x13]
	adds r0, #1
	strb r0, [r6, #0x13]
	ldr r0, [sp, #0x20]
	adds r0, #0x10
	str r0, [sp, #0x20]
	movs r1, #1
	add sl, r1
_0805973C:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bge _08059744
	adds r0, #7
_08059744:
	asrs r0, r0, #3
	cmp sl, r0
	bge _0805974C
	b _08059624
_0805974C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805975C: .4byte 0x080ACB7C
_08059760: .4byte 0x040000D4
_08059764: .4byte 0x06017A00
_08059768: .4byte 0x84000008
_0805976C: .4byte 0x0000C004
_08059770: .4byte 0x03002C30
	.syntax divided
