	.syntax unified

	thumb_func_start sub_08036784
	.global sub_08036784
sub_08036784: @ 0x08036784
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	adds r6, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_battle_sprite_slot
	movs r4, #0
	ldr r0, _08036834 @ =0x083AF480
	mov r8, r0
	lsls r0, r6, #1
	adds r0, #1
	lsls r0, r0, #1
	add r0, r8
	mov sb, r0
	ldr r5, _08036838 @ =0x083AF490
_080367BC:
	ldr r0, _0803683C @ =0x03002C30
	ldr r2, [sp, #4]
	adds r1, r2, r4
	lsls r3, r1, #6
	adds r3, r3, r0
	ldr r0, _08036840 @ =0x00004404
	strh r0, [r3]
	movs r7, #0
	strb r7, [r3, #0x1c]
	movs r0, #0xe
	strb r0, [r3, #0xa]
	movs r0, #0x80
	strb r0, [r3, #0xb]
	lsls r2, r4, #3
	adds r0, r3, #0
	adds r0, #0x2c
	strb r2, [r0]
	lsls r2, r6, #2
	add r2, r8
	ldr r7, [sp]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r2]
	adds r0, r0, r2
	ldrh r2, [r5]
	adds r2, r2, r0
	ldr r7, _08036844 @ =0x000001FF
	adds r0, r7, #0
	ands r2, r0
	strh r2, [r3, #2]
	mov r2, sl
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	mov r7, sb
	ldrh r7, [r7]
	adds r0, r0, r7
	ldrh r2, [r5, #2]
	adds r2, r2, r0
	movs r0, #0xff
	ands r2, r0
	strh r2, [r3, #4]
	ldr r0, _08036848 @ =0x083B5F80
	ldr r0, [r0, #0x74]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	adds r5, #4
	adds r4, #1
	cmp r4, #3
	bls _080367BC
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036834: .4byte 0x083AF480
_08036838: .4byte 0x083AF490
_0803683C: .4byte 0x03002C30
_08036840: .4byte 0x00004404
_08036844: .4byte 0x000001FF
_08036848: .4byte 0x083B5F80
	.syntax divided
