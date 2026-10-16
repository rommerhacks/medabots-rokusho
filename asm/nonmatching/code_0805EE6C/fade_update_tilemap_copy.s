	.syntax unified

	thumb_func_start fade_update_tilemap_copy
	.global fade_update_tilemap_copy
fade_update_tilemap_copy: @ 0x08062D60
	push {r4, r5, r6, lr}
	ldr r0, _08062D84 @ =0x03006F74
	ldr r2, [r0]
	movs r3, #0x3a
	ldrsh r1, [r2, r3]
	adds r3, r0, #0
	cmp r1, #0
	bge _08062D72
	adds r1, #0x7f
_08062D72:
	asrs r0, r1, #7
	cmp r0, #4
	bhi _08062DC8
	lsls r0, r0, #2
	ldr r1, _08062D88 @ =_08062D8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062D84: .4byte 0x03006F74
_08062D88: .4byte _08062D8C
_08062D8C: @ jump table
	.4byte _08062DA0 @ case 0
	.4byte _08062DA0 @ case 1
	.4byte _08062DAA @ case 2
	.4byte _08062DB4 @ case 3
	.4byte _08062DBE @ case 4
_08062DA0:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x15
	b _08062DCE
_08062DAA:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	b _08062DCE
_08062DB4:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x13
	b _08062DCE
_08062DBE:
	ldr r0, [r3]
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x12
	b _08062DCE
_08062DC8:
	ldrh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x11
_08062DCE:
	movs r0, #3
	ands r1, r0
	ldr r2, [r3]
	ldrh r0, [r2, #0x3a]
	subs r0, #1
	strh r0, [r2, #0x3a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08062DE4
	movs r0, #0x3f
	strh r0, [r2, #0x3a]
_08062DE4:
	ldr r6, _08062E08 @ =0x0600E9E2
	lsls r1, r1, #9
	ldr r0, _08062E0C @ =0x0600D800
	adds r4, r1, r0
	movs r5, #7
_08062DEE:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xc
	bl CpuSet
	adds r6, #0x40
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _08062DEE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062E08: .4byte 0x0600E9E2
_08062E0C: .4byte 0x0600D800
_08062E10:
	.byte 0x07, 0x4B, 0x18, 0x68, 0x07, 0x4A, 0x11, 0x68, 0x31, 0x30, 0x01, 0x70, 0x18, 0x68, 0x51, 0x88
	.byte 0x33, 0x30, 0x01, 0x70, 0x04, 0x49, 0x08, 0x68, 0x01, 0x30, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00
	.byte 0x74, 0x6F, 0x00, 0x03, 0x68, 0x2B, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
