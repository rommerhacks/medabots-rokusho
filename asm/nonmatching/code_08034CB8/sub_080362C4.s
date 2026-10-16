	.syntax unified

	thumb_func_start sub_080362C4
	.global sub_080362C4
sub_080362C4: @ 0x080362C4
	push {r4, r5, lr}
	sub sp, #8
	movs r5, #2
	cmp r0, #0
	bne _080362D0
	movs r5, #0x10
_080362D0:
	ldr r4, _0803632C @ =0x0400000A
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _08036330 @ =0x0000B340
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r5, #0
	movs r3, #1
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _08036334 @ =0x0000B344
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r5, #0
	movs r3, #4
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _08036338 @ =0x0000B348
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r5, #0
	movs r3, #7
	bl fill_tilemap_rect_08042698
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _0803633C @ =0x0000B34C
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r5, #0
	movs r3, #0xa
	bl fill_tilemap_rect_08042698
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803632C: .4byte 0x0400000A
_08036330: .4byte 0x0000B340
_08036334: .4byte 0x0000B344
_08036338: .4byte 0x0000B348
_0803633C: .4byte 0x0000B34C
	.syntax divided
