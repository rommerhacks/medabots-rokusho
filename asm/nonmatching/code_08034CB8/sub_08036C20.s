	.syntax unified

	thumb_func_start sub_08036C20
	.global sub_08036C20
sub_08036C20: @ 0x08036C20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r1
	adds r4, r2, #0
	adds r5, r3, #0
	ldr r2, [sp, #0x24]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	adds r0, r3, #0
	movs r1, #1
	str r2, [sp]
	str r3, [sp, #4]
	bl clear_battle_sprite_slot
	ldr r0, _08036CB8 @ =0x03002C30
	lsls r6, r6, #6
	adds r6, r6, r0
	movs r1, #0
	ldr r0, _08036CBC @ =0x0000C404
	strh r0, [r6]
	strb r1, [r6, #0x1c]
	movs r0, #0xe
	strb r0, [r6, #0xa]
	movs r0, #0x80
	strb r0, [r6, #0xb]
	ldr r0, _08036CC0 @ =0x083AF480
	mov sb, r0
	mov r7, r8
	lsls r1, r7, #1
	adds r0, r7, #0
	lsls r0, r0, #2
	mov r8, r0
	add r8, sb
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r7, r8
	ldrh r7, [r7]
	adds r4, r4, r7
	ldr r7, _08036CC4 @ =0x000001FF
	adds r0, r7, #0
	ands r4, r0
	strh r4, [r6, #2]
	adds r1, #1
	lsls r1, r1, #1
	add r1, sb
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	ldrh r1, [r1]
	adds r5, r5, r1
	movs r0, #0xff
	ands r5, r0
	strh r5, [r6, #4]
	ldr r0, _08036CC8 @ =0x083B5F80
	ldr r2, [sp]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r0, [r2]
	ldr r3, [sp, #4]
	adds r1, r3, #0
	bl init_battle_sprite_entry_08040B90
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036CB8: .4byte 0x03002C30
_08036CBC: .4byte 0x0000C404
_08036CC0: .4byte 0x083AF480
_08036CC4: .4byte 0x000001FF
_08036CC8: .4byte 0x083B5F80
	.syntax divided
