	.syntax unified

	thumb_func_start sub_08040994
sub_08040994: @ 0x08040994
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, _080409D0 @ =0x03000440
	ldrb r4, [r5, #1]
	cmp r4, #2
	beq _080409EE
	ldrb r3, [r5, #0x12]
	cmp r3, #1
	bne _080409EE
	ldrb r0, [r5, #0xf]
	movs r6, #3
	cmp r0, #0
	bne _080409B0
	movs r6, #0x13
_080409B0:
	cmp r4, #0
	bne _080409D4
	ldrb r0, [r5, #0x10]
	ldrb r1, [r5, #0x11]
	ldrb r2, [r5, #0xf]
	str r2, [sp]
	str r3, [sp, #4]
	adds r2, r6, #0
	movs r3, #5
	bl load_overworld_map_column
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080409F4
	b _080409EA
	.align 2, 0
_080409D0: .4byte 0x03000440
_080409D4:
	ldr r0, _080409FC @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #8
	movs r1, #8
	adds r2, r6, #0
	movs r3, #5
	bl vram_fill_tilemap_rect
_080409EA:
	strb r4, [r5, #0xe]
	strb r4, [r5, #0x12]
_080409EE:
	ldrb r0, [r5, #0x1b]
	adds r0, #1
	strb r0, [r5, #0x1b]
_080409F4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080409FC: .4byte 0x04000008
	.syntax divided
