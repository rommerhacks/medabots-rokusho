	.syntax unified

	thumb_func_start sub_08017948
	.global sub_08017948
sub_08017948: @ 0x08017948
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _08017988 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0xb
	bhi _0801797E
	ldr r5, _0801798C @ =0x0400000A
	ldrh r0, [r5]
	str r0, [sp]
	ldr r4, _08017990 @ =0x02021000
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #4
	movs r2, #0x11
	movs r3, #0xd
	bl read_vram_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #4
	movs r2, #0x12
	movs r3, #0xd
	bl write_vram_tilemap_rect
_0801797E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017988: .4byte 0x03000440
_0801798C: .4byte 0x0400000A
_08017990: .4byte 0x02021000
	.syntax divided
