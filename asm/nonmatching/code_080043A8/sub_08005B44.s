	.syntax unified

	thumb_func_start sub_08005B44
	.global sub_08005B44
sub_08005B44: @ 0x08005B44
	push {lr}
	sub sp, #8
	ldr r0, _08005B6C @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x97
	ldrb r0, [r2]
	cmp r0, #0x1d
	bhi _08005B7C
	ldr r1, _08005B70 @ =0x03000BE0
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #7
	ldr r1, _08005B74 @ =0x084C21BC
	adds r0, r0, r1
	ldr r1, _08005B78 @ =0x06007800
	movs r2, #0x20
	bl CpuFastSet
	b _08005B86
	.align 2, 0
_08005B6C: .4byte 0x03000440
_08005B70: .4byte 0x03000BE0
_08005B74: .4byte 0x084C21BC
_08005B78: .4byte 0x06007800
_08005B7C:
	ldr r0, _08005BA4 @ =0x084C30BC
	ldr r1, _08005BA8 @ =0x06007800
	movs r2, #0x20
	bl CpuFastSet
_08005B86:
	ldr r0, _08005BAC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08005BB0 @ =0x000063C0
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0x10
	movs r3, #9
	bl fill_tilemap_rect_08042698
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08005BA4: .4byte 0x084C30BC
_08005BA8: .4byte 0x06007800
_08005BAC: .4byte 0x0400000A
_08005BB0: .4byte 0x000063C0
	.syntax divided
