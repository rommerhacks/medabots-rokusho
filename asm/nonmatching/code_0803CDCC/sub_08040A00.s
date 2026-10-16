	.syntax unified

	thumb_func_start sub_08040A00
sub_08040A00: @ 0x08040A00
	push {r4, lr}
	sub sp, #8
	ldr r4, _08040A28 @ =0x03000440
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08040A30
	ldr r0, _08040A2C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x1e
	movs r1, #6
	movs r2, #0
	movs r3, #0xd
	bl vram_fill_tilemap_rect
	ldrb r0, [r4, #0x1b]
	adds r0, #2
	b _08040A34
	.align 2, 0
_08040A28: .4byte 0x03000440
_08040A2C: .4byte 0x04000008
_08040A30:
	ldrb r0, [r4, #0x1b]
	adds r0, #1
_08040A34:
	strb r0, [r4, #0x1b]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
