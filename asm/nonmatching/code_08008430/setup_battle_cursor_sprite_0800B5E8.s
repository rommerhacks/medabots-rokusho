	.syntax unified

	thumb_func_start setup_battle_cursor_sprite_0800B5E8
setup_battle_cursor_sprite_0800B5E8: @ 0x0800B5E8
	push {r4, r5, r6, lr}
	ldr r3, _0800B644 @ =0x03002C30
	movs r0, #0xfe
	lsls r0, r0, #5
	adds r1, r3, r0
	movs r5, #0
	ldr r0, _0800B648 @ =0x0000C804
	strh r0, [r1]
	ldr r4, _0800B64C @ =0x083AC8AC
	ldr r1, _0800B650 @ =0x03000440
	adds r1, #0x48
	ldrh r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r6, _0800B654 @ =0x00001FC2
	adds r0, r3, r6
	strh r2, [r0]
	ldrh r0, [r1]
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r2, _0800B658 @ =0x00001FC4
	adds r0, r3, r2
	strh r1, [r0]
	adds r6, #4
	adds r1, r3, r6
	ldr r0, _0800B65C @ =0x00000303
	strh r0, [r1]
	ldr r0, _0800B660 @ =0x00001FCA
	adds r1, r3, r0
	movs r0, #0xe
	strb r0, [r1]
	ldr r1, _0800B664 @ =0x00001FDC
	adds r0, r3, r1
	strb r5, [r0]
	adds r2, #7
	adds r3, r3, r2
	movs r0, #0x40
	strb r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800B644: .4byte 0x03002C30
_0800B648: .4byte 0x0000C804
_0800B64C: .4byte 0x083AC8AC
_0800B650: .4byte 0x03000440
_0800B654: .4byte 0x00001FC2
_0800B658: .4byte 0x00001FC4
_0800B65C: .4byte 0x00000303
_0800B660: .4byte 0x00001FCA
_0800B664: .4byte 0x00001FDC
	.syntax divided
