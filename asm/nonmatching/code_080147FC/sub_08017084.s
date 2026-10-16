	.syntax unified

	thumb_func_start sub_08017084
	.global sub_08017084
sub_08017084: @ 0x08017084
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _080170C8 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #0xb
	bhi _080170C0
	adds r0, #1
	ldr r5, _080170CC @ =0x0400000A
	ldrh r1, [r5]
	str r1, [sp]
	ldr r4, _080170D0 @ =0x02021000
	str r4, [sp, #4]
	movs r1, #4
	movs r2, #0x12
	movs r3, #0x15
	bl read_vram_tilemap_rect
	ldrb r1, [r6]
	adds r0, r1, #1
	movs r2, #0x1d
	subs r2, r2, r1
	ldrh r1, [r5]
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	movs r3, #0xd
	bl write_vram_tilemap_rect
_080170C0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080170C8: .4byte 0x03000440
_080170CC: .4byte 0x0400000A
_080170D0: .4byte 0x02021000
	.syntax divided
