	.syntax unified

	thumb_func_start sub_0800AF64
	.global sub_0800AF64
sub_0800AF64: @ 0x0800AF64
	push {r4, lr}
	sub sp, #4
	ldr r4, _0800AFA4 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	bl get_medal_active_slot
	adds r1, r0, #0
	cmp r1, #0xff
	beq _0800AFD4
	ldr r0, _0800AFA8 @ =0x030017A0
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrb r0, [r1, #6]
	cmp r0, #0x77
	bhi _0800AFB8
	movs r1, #0x87
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #3
	bl load_part_data
	ldr r1, _0800AFAC @ =0x0000010F
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x64
	ldr r1, _0800AFB0 @ =0x0400000A
	ldrh r3, [r1]
	ldr r1, _0800AFB4 @ =0x000083A0
	str r1, [sp]
	b _0800AFC2
	.align 2, 0
_0800AFA4: .4byte 0x03000440
_0800AFA8: .4byte 0x030017A0
_0800AFAC: .4byte 0x0000010F
_0800AFB0: .4byte 0x0400000A
_0800AFB4: .4byte 0x000083A0
_0800AFB8:
	ldr r0, _0800AFCC @ =0x0400000A
	ldrh r3, [r0]
	ldr r0, _0800AFD0 @ =0x000083A0
	str r0, [sp]
	movs r0, #0xff
_0800AFC2:
	movs r1, #2
	movs r2, #0xa
	bl draw_tilemap_with_offset
	b _0800AFE6
	.align 2, 0
_0800AFCC: .4byte 0x0400000A
_0800AFD0: .4byte 0x000083A0
_0800AFD4:
	ldr r0, _0800AFF0 @ =0x0400000A
	ldrh r3, [r0]
	ldr r0, _0800AFF4 @ =0x000083A0
	str r0, [sp]
	movs r0, #0xff
	movs r1, #2
	movs r2, #0xa
	bl draw_tilemap_with_offset
_0800AFE6:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800AFF0: .4byte 0x0400000A
_0800AFF4: .4byte 0x000083A0
	.syntax divided
