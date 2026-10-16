	.syntax unified

	thumb_func_start sub_08017048
	.global sub_08017048
sub_08017048: @ 0x08017048
	push {lr}
	sub sp, #8
	ldr r0, _08017078 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x84
	ldrb r0, [r1]
	cmp r0, #3
	bhi _08017070
	movs r3, #0x13
	subs r3, r3, r0
	ldr r0, _0801707C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08017080 @ =0x02020800
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #4
	movs r2, #9
	bl write_vram_tilemap_rect
_08017070:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_08017078: .4byte 0x03000440
_0801707C: .4byte 0x04000008
_08017080: .4byte 0x02020800
	.syntax divided
