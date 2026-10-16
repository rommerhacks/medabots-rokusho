	.syntax unified

	thumb_func_start sub_08006284
	.global sub_08006284
sub_08006284: @ 0x08006284
	push {lr}
	sub sp, #8
	cmp r0, #0
	bne _080062AC
	ldr r0, _080062A4 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080062A8 @ =0x0000C374
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0xb
	bl fill_tilemap_rect_08042698
	b _080062C2
	.align 2, 0
_080062A4: .4byte 0x0400000A
_080062A8: .4byte 0x0000C374
_080062AC:
	ldr r0, _080062C8 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080062CC @ =0x0000C388
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0xb
	bl fill_tilemap_rect_08042698
_080062C2:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_080062C8: .4byte 0x0400000A
_080062CC: .4byte 0x0000C388
	.syntax divided
