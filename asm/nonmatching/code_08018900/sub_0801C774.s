	.syntax unified

	thumb_func_start sub_0801C774
sub_0801C774: @ 0x0801C774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _0801C7D0 @ =0x03002C30
	ldr r3, _0801C7D4 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	lsls r4, r0, #0xa
	ldr r1, _0801C7D8 @ =0xFFFFC204
	adds r0, r1, #0
	movs r1, #0x84
	lsls r1, r1, #4
	adds r7, r2, r1
	movs r6, #0
	orrs r4, r0
	strh r4, [r7]
	adds r1, #0x1c
	adds r0, r2, r1
	strb r6, [r0]
	ldr r0, _0801C7DC @ =0x0000084A
	adds r1, r2, r0
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0801C7E0 @ =0x00000849
	adds r1, r2, r0
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x89
	ldrb r0, [r0]
	adds r5, r2, #0
	mov r8, r3
	cmp r0, #0
	bne _0801C7E8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r4, r0
	strh r4, [r7]
	ldr r0, _0801C7E4 @ =0x00000842
	adds r1, r5, r0
	movs r0, #0x68
	b _0801C7EE
	.align 2, 0
_0801C7D0: .4byte 0x03002C30
_0801C7D4: .4byte 0x03001800
_0801C7D8: .4byte 0xFFFFC204
_0801C7DC: .4byte 0x0000084A
_0801C7E0: .4byte 0x00000849
_0801C7E4: .4byte 0x00000842
_0801C7E8:
	ldr r0, _0801C808 @ =0x00000842
	adds r1, r5, r0
	movs r0, #0x88
_0801C7EE:
	strh r0, [r1]
	mov r4, r8
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801C864
	cmp r0, #1
	bgt _0801C80C
	cmp r0, #0
	beq _0801C818
	b _0801C960
	.align 2, 0
_0801C808: .4byte 0x00000842
_0801C80C:
	cmp r0, #2
	beq _0801C8B0
	cmp r0, #3
	bne _0801C816
	b _0801C910
_0801C816:
	b _0801C960
_0801C818:
	ldr r0, _0801C854 @ =0x0000084B
	adds r1, r5, r0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0801C858 @ =0x00000848
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0801C85C @ =0x00000844
	adds r1, r5, r0
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #0x19
	strb r0, [r1]
	ldr r0, _0801C860 @ =0x083B5F80
	ldr r0, [r0, #0x64]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x3e
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0801C95E
	.align 2, 0
_0801C854: .4byte 0x0000084B
_0801C858: .4byte 0x00000848
_0801C85C: .4byte 0x00000844
_0801C860: .4byte 0x083B5F80
_0801C864:
	ldr r0, _0801C8A0 @ =0x0000084B
	adds r1, r5, r0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _0801C8A4 @ =0x00000848
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	ldr r0, _0801C8A8 @ =0x00000844
	adds r1, r5, r0
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #0x1a
	strb r0, [r1]
	ldr r0, _0801C8AC @ =0x083B5F80
	ldr r0, [r0, #0x68]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x3e
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0801C95E
	.align 2, 0
_0801C8A0: .4byte 0x0000084B
_0801C8A4: .4byte 0x00000848
_0801C8A8: .4byte 0x00000844
_0801C8AC: .4byte 0x083B5F80
_0801C8B0:
	ldr r0, _0801C8F4 @ =0x0000084B
	adds r1, r5, r0
	movs r3, #0
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _0801C8F8 @ =0x00000848
	adds r1, r5, r0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _0801C8FC @ =0x00000844
	adds r1, r5, r0
	movs r2, #0
	ldr r0, _0801C900 @ =0x0000FFD4
	strh r0, [r1]
	ldr r0, _0801C904 @ =0x00000846
	adds r1, r5, r0
	movs r0, #0xd0
	lsls r0, r0, #4
	strh r0, [r1]
	ldr r0, _0801C908 @ =0x00000864
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0801C90C @ =0x00000865
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xb
	adds r0, r5, r1
	strh r3, [r0]
	movs r0, #0x61
	bl play_sound_effect
	adds r1, r4, #0
	b _0801C95A
	.align 2, 0
_0801C8F4: .4byte 0x0000084B
_0801C8F8: .4byte 0x00000848
_0801C8FC: .4byte 0x00000844
_0801C900: .4byte 0x0000FFD4
_0801C904: .4byte 0x00000846
_0801C908: .4byte 0x00000864
_0801C90C: .4byte 0x00000865
_0801C910:
	ldr r0, _0801C96C @ =0x0000084B
	adds r1, r5, r0
	movs r3, #0
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _0801C970 @ =0x00000848
	adds r1, r5, r0
	movs r0, #0x40
	strb r0, [r1]
	ldr r0, _0801C974 @ =0x00000844
	adds r1, r5, r0
	movs r2, #0
	ldr r0, _0801C978 @ =0x0000FFD4
	strh r0, [r1]
	ldr r0, _0801C97C @ =0x00000846
	adds r1, r5, r0
	movs r0, #0xe0
	lsls r0, r0, #4
	strh r0, [r1]
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _0801C980 @ =0x00000864
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0801C984 @ =0x00000865
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xb
	adds r0, r5, r1
	strh r3, [r0]
	movs r0, #0x61
	bl play_sound_effect
	mov r1, r8
_0801C95A:
	adds r1, #0xaa
	movs r0, #0x10
_0801C95E:
	strb r0, [r1]
_0801C960:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C96C: .4byte 0x0000084B
_0801C970: .4byte 0x00000848
_0801C974: .4byte 0x00000844
_0801C978: .4byte 0x0000FFD4
_0801C97C: .4byte 0x00000846
_0801C980: .4byte 0x00000864
_0801C984: .4byte 0x00000865
	.syntax divided
