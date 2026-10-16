	.syntax unified

	thumb_func_start sub_08022A04
sub_08022A04: @ 0x08022A04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r4, _08022B14 @ =0x03002C30
	movs r1, #0x94
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #0
	ldr r2, _08022B18 @ =0x0000C604
	mov r8, r2
	mov r3, r8
	strh r3, [r0]
	ldr r2, _08022B1C @ =0x0000095C
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08022B20 @ =0x03001800
	adds r1, #0x88
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	adds r0, r0, r4
	ldrh r2, [r0, #2]
	ldr r3, _08022B24 @ =0x00000942
	adds r0, r4, r3
	strh r2, [r0]
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r2, _08022B28 @ =0x00000944
	adds r1, r4, r2
	strh r0, [r1]
	adds r3, #8
	adds r1, r4, r3
	movs r0, #7
	strb r0, [r1]
	ldr r1, _08022B2C @ =0x00000948
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #1
	adds r1, r4, r3
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _08022B30 @ =0x083B5F80
	adds r0, #0xfc
	ldr r0, [r0]
	movs r1, #0x25
	bl init_battle_sprite_entry_08040B90
	movs r5, #0
	mov sl, r4
	movs r0, #0
	mov sb, r0
	ldr r7, _08022B34 @ =0x0000086B
	add r7, sl
	movs r6, #0x84
	lsls r6, r6, #4
	add r6, sl
_08022A92:
	ldr r1, _08022B38 @ =0xFFFFC604
	strh r1, [r6]
	lsls r4, r5, #6
	ldr r2, _08022B20 @ =0x03001800
	mov r8, r2
	mov r0, r8
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	add r0, sl
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r0, #4
	str r0, [sp]
	add r0, sp, #4
	adds r1, r4, #0
	movs r2, #0x10
	bl calc_polar_to_screen_coords
	ldr r0, [sp, #4]
	strh r0, [r6, #2]
	asrs r0, r0, #0x10
	strh r0, [r6, #4]
	mov r3, sb
	strb r3, [r6, #0x1c]
	movs r0, #7
	strb r0, [r6, #0xa]
	movs r0, #0xf0
	strb r0, [r6, #0xb]
	ldr r0, _08022B3C @ =0x00004604
	strh r0, [r6, #6]
	movs r0, #0x40
	strb r0, [r6, #8]
	strb r0, [r6, #9]
	movs r0, #0x10
	strb r0, [r7]
	strb r4, [r7, #1]
	strb r3, [r7, #2]
	adds r7, #0x40
	adds r6, #0x40
	adds r5, #1
	cmp r5, #3
	bls _08022A92
	movs r0, #0x4a
	bl play_sound_effect
	mov r1, r8
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022B14: .4byte 0x03002C30
_08022B18: .4byte 0x0000C604
_08022B1C: .4byte 0x0000095C
_08022B20: .4byte 0x03001800
_08022B24: .4byte 0x00000942
_08022B28: .4byte 0x00000944
_08022B2C: .4byte 0x00000948
_08022B30: .4byte 0x083B5F80
_08022B34: .4byte 0x0000086B
_08022B38: .4byte 0xFFFFC604
_08022B3C: .4byte 0x00004604
	.syntax divided
