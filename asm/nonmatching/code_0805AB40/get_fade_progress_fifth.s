	.syntax unified

	thumb_func_start get_fade_progress_fifth
get_fade_progress_fifth: @ 0x0805B40C
	push {r4, lr}
	ldr r4, _0805B444 @ =0x03006F74
	ldr r0, [r4]
	ldrb r0, [r0, #0xc]
	movs r1, #5
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #1
	movs r1, #2
	movs r2, #3
	bl sub_0805A258
	ldr r0, [r4]
	ldrb r0, [r0, #0x10]
	subs r0, #1
	movs r1, #5
	bl sub_0807CBBC
	adds r0, #1
	movs r1, #5
	movs r2, #3
	bl sub_0805A258
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805B444: .4byte 0x03006F74
	.syntax divided
