	.syntax unified

	thumb_func_start sub_08006238
	.global sub_08006238
sub_08006238: @ 0x08006238
	push {lr}
	sub sp, #8
	cmp r0, #0
	bne _08006260
	ldr r0, _08006258 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800625C @ =0x0000C370
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #9
	bl fill_tilemap_rect_08042698
	b _08006276
	.align 2, 0
_08006258: .4byte 0x0400000A
_0800625C: .4byte 0x0000C370
_08006260:
	ldr r0, _0800627C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08006280 @ =0x0000C384
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #9
	bl fill_tilemap_rect_08042698
_08006276:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800627C: .4byte 0x0400000A
_08006280: .4byte 0x0000C384
	.syntax divided
