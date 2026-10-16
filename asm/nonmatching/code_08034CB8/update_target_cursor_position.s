	.syntax unified

	thumb_func_start update_target_cursor_position
	.global update_target_cursor_position
update_target_cursor_position: @ 0x0803512C
	push {r4, lr}
	ldr r1, _0803515C @ =0x03002C30
	lsls r3, r0, #2
	adds r2, r3, #0
	adds r2, #0x5d
	lsls r2, r2, #6
	adds r2, r2, r1
	ldr r1, _08035160 @ =0x03001800
	adds r3, r3, r1
	movs r4, #0x9e
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r1, [r1]
	strh r1, [r2, #2]
	adds r4, #2
	adds r1, r3, r4
	ldrh r1, [r1]
	adds r1, #4
	strh r1, [r2, #4]
	bl sub_080350E0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803515C: .4byte 0x03002C30
_08035160: .4byte 0x03001800
	.syntax divided
