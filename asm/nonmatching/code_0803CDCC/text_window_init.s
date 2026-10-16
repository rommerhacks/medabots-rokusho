	.syntax unified

	thumb_func_start text_window_init
	.global text_window_init
text_window_init: @ 0x0803FAA0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _0803FB00 @ =0x03000440
	adds r0, r4, #0
	movs r1, #0x28
	movs r2, #0
	bl sub_0803F624
	strb r5, [r4]
	strb r6, [r4, #1]
	mov r0, r8
	strb r0, [r4, #2]
	movs r0, #0xff
	strb r0, [r4, #0xf]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r4, #0x10]
	strb r0, [r4, #0x11]
	bl decompress_bg_tiles_to_vram_bg
	ldr r0, _0803FB04 @ =0x084C6998
	ldr r1, _0803FB08 @ =0x050001C0
	movs r2, #8
	bl CpuFastSet
	mov r0, r8
	cmp r0, #1
	bne _0803FAF4
	bl setup_bg0_display_layer
_0803FAF4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803FB00: .4byte 0x03000440
_0803FB04: .4byte 0x084C6998
_0803FB08: .4byte 0x050001C0
	.syntax divided
