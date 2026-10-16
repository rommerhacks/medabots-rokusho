	.syntax unified

	thumb_func_start sub_08053AB8
sub_08053AB8: @ 0x08053AB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	ldr r3, [r7]
	ldr r4, [r1]
	ldr r5, [r2]
	adds r0, r3, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl sub_08053B94
	movs r6, #1
	ldr r1, _08053B88 @ =0x03005350
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r2, r1, r0
	ldr r0, [r2]
	cmp r6, r0
	bge _08053B44
	str r1, [sp]
	mov r1, sb
	adds r1, #4
	str r1, [sp, #4]
	mov r2, r8
	adds r2, #4
	str r2, [sp, #8]
	adds r0, r7, #4
	mov sl, r0
_08053AFC:
	mov r1, sl
	adds r1, #4
	mov sl, r1
	subs r1, #4
	ldm r1!, {r3}
	ldr r2, [sp, #8]
	ldm r2!, {r4}
	str r2, [sp, #8]
	ldr r0, [sp, #4]
	ldm r0!, {r5}
	str r0, [sp, #4]
	ldr r1, [sp]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, _08053B8C @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r2
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r0, r1
	str r6, [r0]
	adds r0, r3, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl update_battle_entity_screen_position
	adds r6, #1
	ldr r2, _08053B90 @ =0x03005520
	ldr r0, [r2]
	cmp r6, r0
	blt _08053AFC
_08053B44:
	ldr r3, [r7]
	mov r0, r8
	ldr r4, [r0]
	mov r1, sb
	ldr r5, [r1]
	ldr r0, _08053B88 @ =0x03005350
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r0, _08053B8C @ =0x03006D30
	ldr r2, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r2
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	adds r0, r3, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl update_battle_entity_screen_position
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053B88: .4byte 0x03005350
_08053B8C: .4byte 0x03006D30
_08053B90: .4byte 0x03005520
	.syntax divided
