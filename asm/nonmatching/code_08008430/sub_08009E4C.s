	.syntax unified

	thumb_func_start sub_08009E4C
	.global sub_08009E4C
sub_08009E4C: @ 0x08009E4C
	push {lr}
	sub sp, #8
	ldr r1, _08009E88 @ =0x03000BE0
	ldr r0, _08009E8C @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #7
	ldr r1, _08009E90 @ =0x084C21BC
	adds r0, r0, r1
	ldr r1, _08009E94 @ =0x06006600
	movs r2, #0x20
	bl CpuFastSet
	ldr r0, _08009E98 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08009E9C @ =0x00006330
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #2
	movs r3, #3
	bl fill_tilemap_rect_08042698
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08009E88: .4byte 0x03000BE0
_08009E8C: .4byte 0x03000440
_08009E90: .4byte 0x084C21BC
_08009E94: .4byte 0x06006600
_08009E98: .4byte 0x0400000A
_08009E9C: .4byte 0x00006330
	.syntax divided
