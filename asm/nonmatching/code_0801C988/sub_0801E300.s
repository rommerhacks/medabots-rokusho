	.syntax unified

	thumb_func_start sub_0801E300
sub_0801E300: @ 0x0801E300
	push {r4, r5, r6, lr}
	ldr r0, _0801E384 @ =0x084C4F00
	ldr r1, _0801E388 @ =0x06006400
	bl lz_decompress_dispatch
	ldr r0, _0801E38C @ =0x084882F4
	ldr r1, _0801E390 @ =0x06006520
	bl lz_decompress_dispatch
	ldr r0, _0801E394 @ =0x084C3648
	ldr r1, _0801E398 @ =0x06006600
	bl lz_decompress_dispatch
	ldr r0, _0801E39C @ =0x084C65C8
	ldr r1, _0801E3A0 @ =0x06006800
	bl lz_decompress_dispatch
	ldr r0, _0801E3A4 @ =0x08488B24
	ldr r1, _0801E3A8 @ =0x05000140
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E3AC @ =0x084E3098
	ldr r1, _0801E3B0 @ =0x05000100
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0801E3B4 @ =0x084C6A58
	ldr r1, _0801E3B8 @ =0x05000160
	movs r2, #8
	bl CpuFastSet
	ldr r6, _0801E3BC @ =0x03001800
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	movs r5, #0
	cmp r0, #0
	bne _0801E354
	movs r5, #1
_0801E354:
	adds r0, r5, #0
	bl sub_080362C4
	adds r0, r5, #0
	bl sub_08036340
	adds r4, r6, #0
	adds r4, #0x88
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_08036370
	ldrb r1, [r4]
	adds r0, r5, #0
	bl sub_080364A8
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E384: .4byte 0x084C4F00
_0801E388: .4byte 0x06006400
_0801E38C: .4byte 0x084882F4
_0801E390: .4byte 0x06006520
_0801E394: .4byte 0x084C3648
_0801E398: .4byte 0x06006600
_0801E39C: .4byte 0x084C65C8
_0801E3A0: .4byte 0x06006800
_0801E3A4: .4byte 0x08488B24
_0801E3A8: .4byte 0x05000140
_0801E3AC: .4byte 0x084E3098
_0801E3B0: .4byte 0x05000100
_0801E3B4: .4byte 0x084C6A58
_0801E3B8: .4byte 0x05000160
_0801E3BC: .4byte 0x03001800
	.syntax divided
