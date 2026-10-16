	.syntax unified

	thumb_func_start sub_0801DF60
sub_0801DF60: @ 0x0801DF60
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _0801DFC4 @ =0x03000440
	adds r7, r0, #0
	adds r7, #0x84
	ldrb r3, [r7]
	ldr r4, _0801DFC8 @ =0x083B4AE0
	movs r0, #0xd2
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r4]
	str r0, [sp]
	ldr r6, _0801DFCC @ =0x04000008
	ldrh r0, [r6]
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #0x1e
	movs r1, #1
	movs r2, #0
	bl write_tilemap_rect
	ldrb r0, [r7]
	movs r3, #0x13
	subs r3, r3, r0
	ldr r0, [r4]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0x1e
	movs r1, #1
	movs r2, #0
	bl write_tilemap_rect
	ldrb r0, [r7]
	cmp r0, #9
	bne _0801DFD4
	ldr r1, _0801DFD0 @ =0x03001800
	movs r0, #0xd7
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #1
	strb r0, [r2]
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801DFD8
	.align 2, 0
_0801DFC4: .4byte 0x03000440
_0801DFC8: .4byte 0x083B4AE0
_0801DFCC: .4byte 0x04000008
_0801DFD0: .4byte 0x03001800
_0801DFD4:
	adds r0, #1
	strb r0, [r7]
_0801DFD8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
