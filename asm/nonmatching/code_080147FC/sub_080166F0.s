	.syntax unified

	thumb_func_start sub_080166F0
	.global sub_080166F0
sub_080166F0: @ 0x080166F0
	push {lr}
	sub sp, #8
	ldr r0, _08016720 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #3
	bhi _08016718
	movs r3, #0x13
	subs r3, r3, r0
	ldr r0, _08016724 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08016728 @ =0x02020800
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #4
	movs r2, #9
	bl write_vram_tilemap_rect
_08016718:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08016720: .4byte 0x03000440
_08016724: .4byte 0x04000008
_08016728: .4byte 0x02020800
	.syntax divided
