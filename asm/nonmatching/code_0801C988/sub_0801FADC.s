	.syntax unified

	thumb_func_start sub_0801FADC
sub_0801FADC: @ 0x0801FADC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r7, _0801FB88 @ =0x03001800
	ldr r2, _0801FB8C @ =0x0000015F
	adds r1, r7, r2
	movs r2, #0
	mov r8, r2
	strb r0, [r1]
	bl battle_advance_action_text
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0801FB90 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r3, [r6]
	ldr r4, _0801FB94 @ =0x083B4AE0
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r4]
	str r0, [sp]
	ldr r5, _0801FB98 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r0, #0x1e
	movs r1, #1
	movs r2, #0
	bl write_tilemap_rect
	ldrb r0, [r6]
	movs r3, #0x13
	subs r3, r3, r0
	ldr r0, [r4]
	str r0, [sp]
	ldrh r0, [r5]
	str r0, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	movs r0, #0x1e
	movs r1, #1
	movs r2, #0
	bl write_tilemap_rect
	ldrb r0, [r6]
	cmp r0, #9
	bne _0801FBB4
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0xc]
	ldr r4, _0801FB9C @ =0x03002414
	ldr r1, [r4]
	ldr r0, _0801FBA0 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _0801FBA4 @ =0x01000100
	add r0, sp, #0xc
	bl CpuFastSet
	ldr r0, [r4]
	ldr r1, _0801FBA8 @ =0x00001094
	adds r0, r0, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, _0801FBAC @ =0x030017F0
	ldr r0, _0801FBB0 @ =0x08000841
	str r0, [r1]
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801FBB8
	.align 2, 0
_0801FB88: .4byte 0x03001800
_0801FB8C: .4byte 0x0000015F
_0801FB90: .4byte 0x03000440
_0801FB94: .4byte 0x083B4AE0
_0801FB98: .4byte 0x04000008
_0801FB9C: .4byte 0x03002414
_0801FBA0: .4byte 0x00000B84
_0801FBA4: .4byte 0x01000100
_0801FBA8: .4byte 0x00001094
_0801FBAC: .4byte 0x030017F0
_0801FBB0: .4byte 0x08000841
_0801FBB4:
	adds r0, #1
	strb r0, [r6]
_0801FBB8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
