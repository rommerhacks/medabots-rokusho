	.syntax unified

	thumb_func_start sub_08040A40
sub_08040A40: @ 0x08040A40
	push {r4, lr}
	sub sp, #8
	ldr r0, _08040A5C @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x26
	ldrb r1, [r4]
	adds r2, r0, #0
	cmp r1, #2
	beq _08040A90
	cmp r1, #2
	bgt _08040A60
	cmp r1, #1
	beq _08040ABC
	b _08040AE0
	.align 2, 0
_08040A5C: .4byte 0x03000440
_08040A60:
	cmp r1, #3
	bne _08040AE0
	ldr r0, _08040A80 @ =0x08487524
	ldr r1, _08040A84 @ =0x06000020
	bl lz_decompress_dispatch
	ldr r2, _08040A88 @ =0x084885A8
	ldr r0, _08040A8C @ =0x04000008
	ldrh r3, [r0]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	b _08040AD2
	.align 2, 0
_08040A80: .4byte 0x08487524
_08040A84: .4byte 0x06000020
_08040A88: .4byte 0x084885A8
_08040A8C: .4byte 0x04000008
_08040A90:
	ldr r0, _08040AAC @ =0x08487630
	ldr r1, _08040AB0 @ =0x06000020
	bl lz_decompress_dispatch
	ldr r2, _08040AB4 @ =0x08488600
	ldr r0, _08040AB8 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	movs r1, #0xd
	bl set_tilemap_and_decompress_bg
	b _08040AD2
	.align 2, 0
_08040AAC: .4byte 0x08487630
_08040AB0: .4byte 0x06000020
_08040AB4: .4byte 0x08488600
_08040AB8: .4byte 0x04000008
_08040ABC:
	ldr r0, _08040ADC @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x1e
	movs r1, #6
	movs r2, #0
	movs r3, #0xd
	bl vram_fill_tilemap_rect
_08040AD2:
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _08040AE6
	.align 2, 0
_08040ADC: .4byte 0x04000008
_08040AE0:
	ldrb r0, [r2, #0x1b]
	adds r0, #1
	strb r0, [r2, #0x1b]
_08040AE6:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08040AF0:
	.byte 0x03, 0x49, 0x08, 0x78, 0x00, 0x28, 0x05, 0xD1, 0xC8, 0x7E, 0x01, 0x30, 0x04, 0xE0, 0x00, 0x00
	.byte 0x40, 0x04, 0x00, 0x03, 0xC8, 0x7E, 0x02, 0x30, 0xC8, 0x76, 0x70, 0x47
	.syntax divided
