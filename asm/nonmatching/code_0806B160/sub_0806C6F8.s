	.syntax unified

	thumb_func_start sub_0806C6F8
sub_0806C6F8: @ 0x0806C6F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r6, _0806C710 @ =0x03002C30
	adds r7, r6, #0
	adds r7, #0x20
	ldrb r5, [r7]
	cmp r5, #0
	beq _0806C714
	cmp r5, #1
	beq _0806C778
	b _0806C7B8
	.align 2, 0
_0806C710: .4byte 0x03002C30
_0806C714:
	movs r1, #0xc0
	lsls r1, r1, #8
	movs r4, #3
	str r4, [sp]
	movs r0, #0
	movs r2, #0x33
	movs r3, #0xc
	bl init_battle_sprite_entry_08048818
	movs r0, #0x78
	strh r0, [r6, #2]
	movs r0, #0x50
	strh r0, [r6, #4]
	strh r5, [r6, #0x1a]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	ldr r1, _0806C768 @ =0x00000786
	adds r0, r6, r1
	strh r5, [r0]
	ldr r1, _0806C76C @ =0x0000CC08
	str r4, [sp]
	movs r0, #0x21
	movs r2, #0x12
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806C770 @ =0x00000782
	adds r0, r6, r2
	ldrh r1, [r0]
	adds r2, #0xc0
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _0806C774 @ =0x00000784
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #0xa
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	b _0806C7B8
	.align 2, 0
_0806C768: .4byte 0x00000786
_0806C76C: .4byte 0x0000CC08
_0806C770: .4byte 0x00000782
_0806C774: .4byte 0x00000784
_0806C778:
	ldrh r0, [r6, #0x1a]
	adds r0, #1
	strh r0, [r6, #0x1a]
	ldrh r0, [r6, #0x1a]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0806C792
	ldr r0, _0806C7B0 @ =0x00000804
	adds r1, r6, r0
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
_0806C792:
	ldrh r0, [r6, #0x1a]
	cmp r0, #0xeb
	bhi _0806C7A4
	ldr r0, _0806C7B4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _0806C7B8
_0806C7A4:
	movs r0, #0
	bl sub_0806B584
	movs r0, #1
	b _0806C7BA
	.align 2, 0
_0806C7B0: .4byte 0x00000804
_0806C7B4: .4byte 0x0300058C
_0806C7B8:
	movs r0, #0
_0806C7BA:
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
