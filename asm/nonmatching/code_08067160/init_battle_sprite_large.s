	.syntax unified

	thumb_func_start init_battle_sprite_large
init_battle_sprite_large: @ 0x08069DB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0x84
	lsls r0, r0, #1
	mov sl, r0
	movs r1, #3
	mov sb, r1
	str r1, [sp]
	movs r0, #2
	ldr r1, _08069E74 @ =0x0000CB20
	mov r2, sl
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r7, _08069E78 @ =0x03002C30
	adds r0, r7, #0
	adds r0, #0x84
	movs r6, #0
	movs r1, #0xc8
	mov r8, r1
	mov r1, r8
	strh r1, [r0]
	adds r0, #4
	movs r4, #0x88
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0xf
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	ldr r5, _08069E7C @ =0x00000109
	mov r0, sb
	str r0, [sp]
	movs r0, #3
	ldr r1, _08069E74 @ =0x0000CB20
	adds r2, r5, #0
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	adds r0, r7, #0
	adds r0, #0xc4
	mov r1, r8
	strh r1, [r0]
	adds r0, #4
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0xf
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	movs r2, #0x85
	lsls r2, r2, #1
	mov r0, sb
	str r0, [sp]
	movs r0, #4
	ldr r1, _08069E74 @ =0x0000CB20
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r1, r8
	strh r1, [r0]
	add sl, r7
	mov r0, sl
	strb r4, [r0]
	adds r5, r7, r5
	strb r4, [r5]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	adds r1, #2
	adds r0, r7, r1
	strh r6, [r0]
	ldr r1, _08069E80 @ =0x040000D4
	ldr r0, _08069E84 @ =0x0807C2A0
	str r0, [r1]
	ldr r0, _08069E88 @ =0x05000240
	str r0, [r1, #4]
	ldr r0, _08069E8C @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069E74: .4byte 0x0000CB20
_08069E78: .4byte 0x03002C30
_08069E7C: .4byte 0x00000109
_08069E80: .4byte 0x040000D4
_08069E84: .4byte 0x0807C2A0
_08069E88: .4byte 0x05000240
_08069E8C: .4byte 0x84000008
	.syntax divided
