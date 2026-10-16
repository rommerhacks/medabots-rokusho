	.syntax unified

	thumb_func_start sub_08031704
sub_08031704: @ 0x08031704
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	bl dispatch_battle_action_substate
	ldr r0, _08031820 @ =0x084E3018
	ldr r1, _08031824 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08031828 @ =0x03002C30
	ldr r0, _0803182C @ =0x03001800
	mov sl, r0
	ldr r1, _08031830 @ =0x0300183C
	ldrb r0, [r1]
	adds r0, #2
	lsls r0, r0, #0xa
	ldr r2, _08031834 @ =0xFFFFC004
	mov r8, r2
	movs r2, #0x84
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r6, #0
	mov r2, r8
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _08031838 @ =0x0000085C
	adds r0, r4, r1
	strb r6, [r0]
	mov r7, sl
	adds r7, #0x87
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldr r2, _0803183C @ =0x00000842
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _08031840 @ =0x0000084A
	adds r0, r4, r1
	movs r5, #7
	strb r5, [r0]
	adds r2, #7
	adds r1, r4, r2
	movs r0, #0x81
	strb r0, [r1]
	ldr r0, _08031844 @ =0x083B5F80
	mov sb, r0
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	ldr r1, _08031830 @ =0x0300183C
	ldrb r0, [r1]
	adds r0, #2
	lsls r0, r0, #0xa
	mov r2, r8
	orrs r0, r2
	movs r2, #0x88
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _08031848 @ =0x0000089C
	adds r0, r4, r1
	strb r6, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldr r2, _0803184C @ =0x00000882
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _08031850 @ =0x0000088A
	adds r0, r4, r1
	strb r5, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #2
	adds r0, #0x59
	adds r2, #7
	adds r4, r4, r2
	strb r0, [r4]
	movs r0, #0x9c
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	movs r1, #0x22
	bl init_battle_sprite_entry_08040B90
	ldr r1, _08031854 @ =0x03000590
	ldrb r0, [r7]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xaa
	ldrb r1, [r0]
	mov r0, sl
	adds r0, #0x51
	strb r1, [r0]
	ldr r1, _08031858 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031820: .4byte 0x084E3018
_08031824: .4byte 0x050002E0
_08031828: .4byte 0x03002C30
_0803182C: .4byte 0x03001800
_08031830: .4byte 0x0300183C
_08031834: .4byte 0xFFFFC004
_08031838: .4byte 0x0000085C
_0803183C: .4byte 0x00000842
_08031840: .4byte 0x0000084A
_08031844: .4byte 0x083B5F80
_08031848: .4byte 0x0000089C
_0803184C: .4byte 0x00000882
_08031850: .4byte 0x0000088A
_08031854: .4byte 0x03000590
_08031858: .4byte 0x0300137C
	.syntax divided
