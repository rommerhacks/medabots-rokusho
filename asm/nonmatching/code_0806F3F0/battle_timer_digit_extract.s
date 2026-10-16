	.syntax unified

	thumb_func_start battle_timer_digit_extract
	.global battle_timer_digit_extract
battle_timer_digit_extract: @ 0x0806FCBC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	ldr r0, _0806FD90 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0xf0
	ldrh r5, [r1]
	adds r0, #0xf2
	ldrh r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl sub_0807CDD0
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r4, sp
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_0807CDD0
	ldr r1, _0806FD94 @ =0x000090C8
	mov r8, r1
	add r0, r8
	movs r1, #0
	mov sb, r1
	strh r0, [r4, #6]
	adds r0, r5, #0
	movs r1, #0xa
	bl sub_0807CD58
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, r8
	strh r0, [r5, #2]
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r4, sp
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, r8
	strh r0, [r4]
	mov r0, sp
	mov r1, sb
	strh r1, [r0, #4]
	mov r4, sp
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, r8
	strh r0, [r4, #0xc]
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, r8
	strh r0, [r5, #0xa]
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r4, sp
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, r8
	strh r0, [r4, #8]
	ldr r1, _0806FD98 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _0806FD9C @ =0x0600F86C
	str r0, [r1, #4]
	ldr r0, _0806FDA0 @ =0x80000007
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806FD90: .4byte 0x03001800
_0806FD94: .4byte 0x000090C8
_0806FD98: .4byte 0x040000D4
_0806FD9C: .4byte 0x0600F86C
_0806FDA0: .4byte 0x80000007
	.syntax divided
