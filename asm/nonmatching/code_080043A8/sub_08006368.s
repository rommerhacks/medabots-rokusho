	.syntax unified

	thumb_func_start sub_08006368
	.global sub_08006368
sub_08006368: @ 0x08006368
	push {lr}
	sub sp, #8
	cmp r0, #0
	bne _08006390
	ldr r0, _08006388 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0800638C @ =0x0000C380
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
	b _080063A6
	.align 2, 0
_08006388: .4byte 0x0400000A
_0800638C: .4byte 0x0000C380
_08006390:
	ldr r0, _080063AC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080063B0 @ =0x0000C388
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xe
	movs r3, #0x11
	bl fill_tilemap_rect_08042698
_080063A6:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_080063AC: .4byte 0x0400000A
_080063B0: .4byte 0x0000C388
	.syntax divided
