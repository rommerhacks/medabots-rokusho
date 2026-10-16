	.syntax unified

	thumb_func_start check_sprite_in_range
check_sprite_in_range: @ 0x08035658
	push {r4, lr}
	ldr r1, _08035688 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r1
	movs r1, #2
	ldrsh r4, [r0, r1]
	movs r1, #4
	ldrsh r2, [r0, r1]
	ldrh r3, [r0, #0x30]
	ldrh r1, [r0, #0x32]
	subs r0, r1, #2
	cmp r0, r2
	bgt _0803568C
	adds r0, r1, #2
	cmp r0, r2
	blt _0803568C
	subs r0, r3, #2
	cmp r0, r4
	bgt _0803568C
	adds r0, r3, #2
	cmp r0, r4
	blt _0803568C
	movs r0, #1
	b _0803568E
	.align 2, 0
_08035688: .4byte 0x03002C30
_0803568C:
	movs r0, #0
_0803568E:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
