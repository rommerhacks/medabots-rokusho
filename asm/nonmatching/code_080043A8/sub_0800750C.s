	.syntax unified

	thumb_func_start sub_0800750C
	.global sub_0800750C
sub_0800750C: @ 0x0800750C
	push {lr}
	sub sp, #8
	ldr r0, _08007538 @ =0x03000440
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #0
	beq _08007530
	ldr r0, _0800753C @ =0x0400000C
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x10
	movs r1, #4
	movs r2, #0xd
	movs r3, #0x10
	bl vram_fill_tilemap_rect
_08007530:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08007538: .4byte 0x03000440
_0800753C: .4byte 0x0400000C
	.syntax divided
