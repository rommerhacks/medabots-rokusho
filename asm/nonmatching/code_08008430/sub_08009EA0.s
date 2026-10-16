	.syntax unified

	thumb_func_start sub_08009EA0
sub_08009EA0: @ 0x08009EA0
	push {lr}
	sub sp, #8
	ldr r1, _08009EDC @ =0x03000BE0
	ldr r0, _08009EE0 @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #7
	ldr r1, _08009EE4 @ =0x084C21BC
	adds r0, r0, r1
	ldr r1, _08009EE8 @ =0x06007800
	movs r2, #0x20
	bl CpuFastSet
	ldr r0, _08009EEC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08009EF0 @ =0x000063C0
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
_08009EDC: .4byte 0x03000BE0
_08009EE0: .4byte 0x03000440
_08009EE4: .4byte 0x084C21BC
_08009EE8: .4byte 0x06007800
_08009EEC: .4byte 0x0400000A
_08009EF0: .4byte 0x000063C0
	.syntax divided
