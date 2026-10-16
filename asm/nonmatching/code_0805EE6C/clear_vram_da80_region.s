	.syntax unified

	thumb_func_start clear_vram_da80_region
clear_vram_da80_region: @ 0x08060E10
	push {r4, r5, r6, lr}
	sub sp, #0x14
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r1, _08060F98 @ =0x0600DA80
	ldr r2, _08060F9C @ =0x01000080
	add r0, sp, #0x10
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r5, _08060FA0 @ =0x03002C30
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r5, r0
	movs r1, #0
	ldr r2, _08060FA4 @ =0x00008004
	strh r2, [r3]
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r0, _08060FA8 @ =0x0000020A
	adds r1, r5, r0
	movs r0, #0xe
	strb r0, [r1]
	subs r6, #0x16
	adds r1, r5, r6
	ldr r0, _08060FAC @ =0x00000307
	strh r0, [r1]
	ldr r0, _08060FB0 @ =0x00000202
	adds r1, r5, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, _08060FB4 @ =0x03006F74
	ldr r0, [r0]
	ldrb r1, [r0, #5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	subs r6, #2
	adds r1, r5, r6
	strh r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r2, r0
	strh r2, [r3]
	movs r2, #0x82
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #0x40
	strb r1, [r0]
	adds r6, #5
	adds r0, r5, r6
	strb r1, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r1]
	subs r2, #0x2c
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	subs r6, #0x3f
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x1a
	strh r0, [r1]
	subs r2, #0x1a
	adds r1, r5, r2
	movs r0, #0x98
	strh r0, [r1]
	subs r6, #6
	adds r0, r5, r6
	strh r4, [r0]
	movs r2, #0
	adds r1, r5, #0
	movs r6, #0
	movs r5, #0x80
	lsls r5, r5, #8
	movs r4, #2
	adds r3, r1, #0
_08060EC8:
	adds r0, r2, #0
	adds r0, #0xc
	lsls r0, r0, #6
	adds r0, r0, r1
	strh r5, [r0]
	strb r4, [r0, #0x1c]
	strb r6, [r0, #0xa]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08060EC8
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r4, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xf0
	lsls r6, r6, #2
	adds r2, r3, r6
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #6
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r6, #0x7a
	adds r0, r3, r6
	movs r1, #5
	strh r1, [r0]
	ldr r2, _08060FB8 @ =0x00000386
	adds r0, r3, r2
	strh r1, [r0]
	ldr r4, _08060FBC @ =0x00000306
	adds r0, r3, r4
	movs r1, #8
	strh r1, [r0]
	adds r6, #0x80
	adds r0, r3, r6
	strh r1, [r0]
	ldr r0, _08060FC0 @ =0x00000342
	adds r1, r3, r0
	movs r0, #0x48
	strh r0, [r1]
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0x2c
	strh r2, [r0]
	adds r4, #0x7c
	adds r1, r3, r4
	movs r0, #0x58
	strh r0, [r1]
	subs r6, #0x42
	adds r0, r3, r6
	strh r2, [r0]
	ldr r1, _08060FC4 @ =0x00000302
	adds r0, r3, r1
	movs r2, #0x50
	strh r2, [r0]
	subs r4, #0x7e
	adds r1, r3, r4
	movs r0, #0x22
	strh r0, [r1]
	adds r6, #0x3e
	adds r0, r3, r6
	strh r2, [r0]
	movs r0, #0xf1
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r0, #0x3e
	strh r0, [r1]
	ldr r4, _08060FC8 @ =0x030004DE
	ldr r0, _08060FCC @ =0x03002B70
	ldr r1, [r0]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x15
	movs r3, #1
	bl render_text_sprites_08040DB8
	ldr r1, _08060FD0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08060F98: .4byte 0x0600DA80
_08060F9C: .4byte 0x01000080
_08060FA0: .4byte 0x03002C30
_08060FA4: .4byte 0x00008004
_08060FA8: .4byte 0x0000020A
_08060FAC: .4byte 0x00000307
_08060FB0: .4byte 0x00000202
_08060FB4: .4byte 0x03006F74
_08060FB8: .4byte 0x00000386
_08060FBC: .4byte 0x00000306
_08060FC0: .4byte 0x00000342
_08060FC4: .4byte 0x00000302
_08060FC8: .4byte 0x030004DE
_08060FCC: .4byte 0x03002B70
_08060FD0: .4byte 0x0300137C
	.syntax divided
