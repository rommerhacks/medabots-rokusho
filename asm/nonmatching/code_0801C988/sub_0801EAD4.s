	.syntax unified

	thumb_func_start sub_0801EAD4
sub_0801EAD4: @ 0x0801EAD4
	push {r4, lr}
	sub sp, #4
	ldr r0, _0801EB00 @ =0x084CCE48
	ldr r1, _0801EB04 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801EB08 @ =0x0850E358
	ldr r1, _0801EB0C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0801EB10 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801EB14
	movs r1, #0xac
	lsls r1, r1, #1
	b _0801EB18
	.align 2, 0
_0801EB00: .4byte 0x084CCE48
_0801EB04: .4byte 0x06010800
_0801EB08: .4byte 0x0850E358
_0801EB0C: .4byte 0x050003C0
_0801EB10: .4byte 0x03001800
_0801EB14:
	movs r1, #0xaa
	lsls r1, r1, #1
_0801EB18:
	adds r0, r3, r1
	ldrh r2, [r0]
	adds r1, #2
	adds r0, r3, r1
	ldrh r3, [r0]
	ldr r0, _0801EB54 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	ldr r4, _0801EB58 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r1, [r0]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xa
	bl sub_08036C20
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801EB54: .4byte 0x03000440
_0801EB58: .4byte 0x03001800
	.syntax divided
