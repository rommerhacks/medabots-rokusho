	.syntax unified

	thumb_func_start calculate_camera_scroll_from_npc
	.global calculate_camera_scroll_from_npc
calculate_camera_scroll_from_npc: @ 0x08052A58
	push {r4, r5, r6, r7, lr}
	ldr r1, _08052AE8 @ =0x030057E0
	ldr r2, _08052AEC @ =0x00000C56
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r6, r0, #7
	cmp r6, #0
	bge _08052A6A
	movs r6, #0
_08052A6A:
	adds r4, r6, #0
	adds r4, #0xf
	ldr r0, _08052AF0 @ =0x000007FE
	adds r5, r1, r0
	ldrb r0, [r5]
	movs r1, #0
	bl sub_08052960
	lsrs r0, r0, #1
	cmp r4, r0
	bls _08052A96
	ldrb r0, [r5]
	movs r1, #0
	bl sub_08052960
	lsrs r6, r0, #1
	subs r6, #0xf
	bl sub_08052A04
	cmp r0, #0
	beq _08052A96
	movs r6, #0
_08052A96:
	ldr r1, _08052AE8 @ =0x030057E0
	ldr r2, _08052AF4 @ =0x00000C57
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r5, r0, #4
	cmp r5, #0
	bgt _08052AA6
	movs r5, #0
_08052AA6:
	adds r4, r5, #0
	adds r4, #0xa
	ldr r0, _08052AF0 @ =0x000007FE
	adds r7, r1, r0
	ldrb r0, [r7]
	movs r1, #1
	bl sub_08052960
	lsrs r0, r0, #1
	cmp r4, r0
	bls _08052AD2
	ldrb r0, [r7]
	movs r1, #1
	bl sub_08052960
	lsrs r5, r0, #1
	subs r5, #0xa
	bl sub_08052A18
	cmp r0, #0
	beq _08052AD2
	movs r5, #0
_08052AD2:
	lsls r0, r6, #0x14
	lsrs r0, r0, #0x10
	bl sub_080529C4
	lsls r0, r5, #0x14
	lsrs r0, r0, #0x10
	bl sub_080529E4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052AE8: .4byte 0x030057E0
_08052AEC: .4byte 0x00000C56
_08052AF0: .4byte 0x000007FE
_08052AF4: .4byte 0x00000C57
	.syntax divided
