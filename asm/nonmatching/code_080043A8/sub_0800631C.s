	.syntax unified

	thumb_func_start sub_0800631C
	.global sub_0800631C
sub_0800631C: @ 0x0800631C
	push {lr}
	sub sp, #8
	cmp r0, #0
	bne _08006344
	ldr r0, _0800633C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08006340 @ =0x0000C37C
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0xf
	bl fill_tilemap_rect_08042698
	b _0800635A
	.align 2, 0
_0800633C: .4byte 0x0400000A
_08006340: .4byte 0x0000C37C
_08006344:
	ldr r0, _08006360 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08006364 @ =0x0000C388
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0xf
	bl fill_tilemap_rect_08042698
_0800635A:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08006360: .4byte 0x0400000A
_08006364: .4byte 0x0000C388
	.syntax divided
