	.syntax unified

	thumb_func_start sub_0806BBA8
sub_0806BBA8: @ 0x0806BBA8
	push {lr}
	ldr r1, _0806BBD4 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0806BBD8 @ =0x000080FF
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
	bl play_song
	movs r0, #1
	bl sub_08047850
	pop {r0}
	bx r0
	.align 2, 0
_0806BBD4: .4byte 0x04000050
_0806BBD8: .4byte 0x000080FF
	.syntax divided
