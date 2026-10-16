	.syntax unified

	thumb_func_start process_text_tile_and_dma_transfer
	.global process_text_tile_and_dma_transfer
process_text_tile_and_dma_transfer: @ 0x0806FB44
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	ldr r1, _0806FB70 @ =0x0848602C
	lsrs r0, r0, #0x16
	adds r0, #0x10
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, _0806FB74 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xd0
	ldrb r4, [r0]
	adds r1, r1, r4
	ldr r3, [r2, #8]
	movs r5, #1
	ands r5, r3
	cmp r5, #0
	beq _0806FB78
	ldrb r0, [r1]
	cmp r0, #0x14
	bne _0806FC04
	movs r0, #1
	b _0806FC06
	.align 2, 0
_0806FB70: .4byte 0x0848602C
_0806FB74: .4byte 0x03001800
_0806FB78:
	ldrb r0, [r1]
	cmp r0, #0x14
	bne _0806FBC8
	movs r0, #8
	ands r3, r0
	cmp r3, #0
	beq _0806FB92
	lsls r0, r4, #1
	adds r1, r2, #0
	adds r1, #0xd2
	adds r0, r0, r1
	strh r5, [r0]
	b _0806FB9E
_0806FB92:
	lsls r0, r4, #1
	adds r1, r2, #0
	adds r1, #0xd2
	adds r0, r0, r1
	ldr r1, _0806FBB4 @ =0x00009078
	strh r1, [r0]
_0806FB9E:
	ldr r1, _0806FBB8 @ =0x040000D4
	ldr r0, _0806FBBC @ =0x030018D2
	str r0, [r1]
	ldr r0, _0806FBC0 @ =0x0600FC44
	str r0, [r1, #4]
	ldr r0, _0806FBC4 @ =0x8000000D
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #1
	b _0806FC06
	.align 2, 0
_0806FBB4: .4byte 0x00009078
_0806FBB8: .4byte 0x040000D4
_0806FBBC: .4byte 0x030018D2
_0806FBC0: .4byte 0x0600FC44
_0806FBC4: .4byte 0x8000000D
_0806FBC8:
	ldrb r3, [r1]
	cmp r3, #0x15
	bne _0806FBDA
	lsls r0, r4, #1
	adds r1, r2, #0
	adds r1, #0xd2
	adds r0, r0, r1
	strh r5, [r0]
	b _0806FBE8
_0806FBDA:
	lsls r0, r4, #1
	adds r1, r2, #0
	adds r1, #0xd2
	adds r0, r0, r1
	ldr r4, _0806FC0C @ =0x00009064
	adds r1, r3, r4
	strh r1, [r0]
_0806FBE8:
	adds r1, r2, #0
	adds r1, #0xd0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0806FC10 @ =0x040000D4
	adds r0, r2, #0
	adds r0, #0xd2
	str r0, [r1]
	ldr r0, _0806FC14 @ =0x0600FC44
	str r0, [r1, #4]
	ldr r0, _0806FC18 @ =0x8000000D
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0806FC04:
	movs r0, #0
_0806FC06:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0806FC0C: .4byte 0x00009064
_0806FC10: .4byte 0x040000D4
_0806FC14: .4byte 0x0600FC44
_0806FC18: .4byte 0x8000000D
	.syntax divided
