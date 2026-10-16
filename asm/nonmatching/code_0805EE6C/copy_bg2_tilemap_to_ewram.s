	.syntax unified

	thumb_func_start copy_bg2_tilemap_to_ewram
copy_bg2_tilemap_to_ewram: @ 0x08060540
	push {r4, lr}
	sub sp, #4
	ldr r4, _0806058C @ =0x06002800
	ldr r1, _08060590 @ =0x02020800
	adds r0, r4, #0
	movs r2, #0x28
	bl CpuFastSet
	movs r0, #0
	str r0, [sp]
	ldr r2, _08060594 @ =0x01000200
	mov r0, sp
	adds r1, r4, #0
	bl CpuFastSet
	bl reset_bg_scroll
	bl sub_08059D04
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #0x50
	ldr r2, _08060598 @ =0x000002FF
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _0806059C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806058C: .4byte 0x06002800
_08060590: .4byte 0x02020800
_08060594: .4byte 0x01000200
_08060598: .4byte 0x000002FF
_0806059C: .4byte 0x0300137C
	.syntax divided
