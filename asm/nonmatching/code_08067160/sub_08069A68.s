	.syntax unified

	thumb_func_start sub_08069A68
sub_08069A68: @ 0x08069A68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	mov sb, r1
	mov sl, r2
	ldr r0, [sp, #0x40]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	mov r4, sl
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov sl, r4
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	lsls r1, r0, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #3
	bl sub_0807CD58
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #3
	bl sub_0807CDD0
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r5, _08069B24 @ =0x03006FA0
	lsls r0, r4, #1
	mov r8, r0
	add r8, r4
	mov r1, r8
	lsls r3, r1, #2
	adds r3, r6, r3
	adds r0, r3, r5
	ldrb r0, [r0]
	adds r1, r5, #3
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r5, #6
	adds r2, r3, r2
	ldrb r2, [r2]
	adds r5, #9
	adds r3, r3, r5
	ldrb r3, [r3]
	subs r4, r6, #2
	mov r5, r8
	subs r4, r5, r4
	str r4, [sp]
	ldr r4, _08069B28 @ =0x08485CC4
	add r6, r8
	adds r6, r6, r4
	ldrb r4, [r6]
	subs r4, #3
	str r4, [sp, #4]
	mov r4, sb
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r4, [sp, #8]
	mov r5, sl
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	str r5, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r4, #3
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	bl init_battle_medabot_sprites
	ldrb r0, [r6]
	subs r0, #3
	ldr r1, [sp, #0x1c]
	bl battle_sprite_set_palette_index
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08069B24: .4byte 0x03006FA0
_08069B28: .4byte 0x08485CC4
	.syntax divided
