	.syntax unified

	thumb_func_start sub_08016614
	.global sub_08016614
sub_08016614: @ 0x08016614
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _08016654 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #9
	bhi _0801664A
	ldr r5, _08016658 @ =0x0400000A
	ldrh r0, [r5]
	str r0, [sp]
	ldr r4, _0801665C @ =0x02020800
	str r4, [sp, #4]
	movs r0, #0xb
	movs r1, #4
	movs r2, #0x13
	movs r3, #0x10
	bl read_vram_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xb
	movs r1, #4
	movs r2, #0x14
	movs r3, #0x10
	bl write_vram_tilemap_rect
_0801664A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016654: .4byte 0x03000440
_08016658: .4byte 0x0400000A
_0801665C: .4byte 0x02020800
	.syntax divided
