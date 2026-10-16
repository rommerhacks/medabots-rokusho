	.syntax unified

	thumb_func_start sub_0805FB2C
sub_0805FB2C: @ 0x0805FB2C
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _0805FB8C @ =0x01006000
	mov r0, sp
	bl CpuFastSet
	bl sub_08059D04
	bl reset_bg_scroll
	ldr r1, _0805FB90 @ =0x04000040
	movs r0, #0xf0
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x80
	strh r0, [r1]
	adds r1, #4
	ldr r2, _0805FB94 @ =0x00003F3F
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x2f
	strh r0, [r1]
	subs r1, #0x4a
	ldr r2, _0805FB98 @ =0x00002060
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x50
	ldr r2, _0805FB9C @ =0x000002BF
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0x12
	bl play_song
	ldr r1, _0805FBA0 @ =0x04000054
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _0805FBA4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0805FB8C: .4byte 0x01006000
_0805FB90: .4byte 0x04000040
_0805FB94: .4byte 0x00003F3F
_0805FB98: .4byte 0x00002060
_0805FB9C: .4byte 0x000002BF
_0805FBA0: .4byte 0x04000054
_0805FBA4: .4byte 0x0300137C
	.syntax divided
