	.syntax unified

	thumb_func_start sub_080062D0
	.global sub_080062D0
sub_080062D0: @ 0x080062D0
	push {lr}
	sub sp, #8
	cmp r0, #0
	bne _080062F8
	ldr r0, _080062F0 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080062F4 @ =0x0000C378
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0xd
	bl fill_tilemap_rect_08042698
	b _0800630E
	.align 2, 0
_080062F0: .4byte 0x0400000A
_080062F4: .4byte 0x0000C378
_080062F8:
	ldr r0, _08006314 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08006318 @ =0x0000C388
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0xd
	bl fill_tilemap_rect_08042698
_0800630E:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08006314: .4byte 0x0400000A
_08006318: .4byte 0x0000C388
	.syntax divided
