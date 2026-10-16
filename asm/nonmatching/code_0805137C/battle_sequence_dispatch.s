	.syntax unified

	thumb_func_start battle_sequence_dispatch
	.global battle_sequence_dispatch
battle_sequence_dispatch: @ 0x08054200
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x98
	ldr r3, _08054258 @ =0x03005350
	adds r1, r3, #0
	adds r1, #0xf0
	movs r0, #1
	str r0, [r1]
	adds r2, r3, #0
	adds r2, #0xf8
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [r2]
	ldr r1, _0805425C @ =0x083D5D84
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	adds r5, r3, #0
	.syntax divided
