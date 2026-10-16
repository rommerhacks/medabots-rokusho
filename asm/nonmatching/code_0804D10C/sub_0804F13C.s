	.syntax unified

	thumb_func_start sub_0804F13C
sub_0804F13C: @ 0x0804F13C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #1
	beq _0804F1E4
	cmp r0, #1
	bgt _0804F152
	cmp r0, #0
	beq _0804F160
	b _0804F350
_0804F152:
	cmp r1, #2
	bne _0804F158
	b _0804F26C
_0804F158:
	cmp r1, #3
	bne _0804F15E
	b _0804F2E4
_0804F15E:
	b _0804F350
_0804F160:
	ldr r5, _0804F1CC @ =0x030057E0
	ldr r0, _0804F1D0 @ =0x00000C54
	adds r4, r5, r0
	ldrh r0, [r4]
	ldr r1, _0804F1D4 @ =0x00000C4A
	adds r6, r5, r1
	ldrh r2, [r6]
	cmp r0, r2
	bne _0804F174
	b _0804F350
_0804F174:
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	subs r1, r1, r0
	strh r1, [r4]
	bl sub_08052A18
	cmp r0, #0
	beq _0804F18A
	b _0804F350
_0804F18A:
	ldrh r1, [r4]
	ldrh r0, [r6]
	subs r1, r1, r0
	ldr r2, _0804F1D8 @ =0x00000802
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #3
	subs r0, #0x60
	cmp r1, r0
	blt _0804F1A0
	b _0804F350
_0804F1A0:
	ldr r0, _0804F1DC @ =0x03004C30
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0804F1AC
	b _0804F350
_0804F1AC:
	movs r0, #0x2f
	bl sub_080518F4
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052AF8
	movs r0, #0x2f
	bl sub_080518F4
	ldr r2, _0804F1E0 @ =0x03002C30
	ldrh r1, [r2, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	b _0804F350
	.align 2, 0
_0804F1CC: .4byte 0x030057E0
_0804F1D0: .4byte 0x00000C54
_0804F1D4: .4byte 0x00000C4A
_0804F1D8: .4byte 0x00000802
_0804F1DC: .4byte 0x03004C30
_0804F1E0: .4byte 0x03002C30
_0804F1E4:
	ldr r2, _0804F258 @ =0x030057E0
	ldr r0, _0804F25C @ =0x00000C54
	adds r4, r2, r0
	ldrh r1, [r4]
	subs r0, #0xa
	adds r5, r2, r0
	ldrh r0, [r5]
	subs r1, r1, r0
	adds r1, #0x10
	ldr r0, _0804F260 @ =0x00000802
	adds r6, r2, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	blt _0804F204
	b _0804F350
_0804F204:
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	bl sub_08052A18
	cmp r0, #0
	beq _0804F21A
	b _0804F350
_0804F21A:
	ldrh r0, [r4]
	ldrh r1, [r5]
	subs r0, r0, r1
	adds r0, #0x10
	cmp r0, #0x50
	bgt _0804F228
	b _0804F350
_0804F228:
	ldr r0, _0804F264 @ =0x03004C30
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r1, #0xa0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	blt _0804F23A
	b _0804F350
_0804F23A:
	movs r0, #0x2f
	bl sub_080518F4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052AF8
	movs r0, #0x2f
	bl sub_080518F4
	ldr r2, _0804F268 @ =0x03002C30
	ldrh r1, [r2, #4]
	subs r1, r1, r0
	strh r1, [r2, #4]
	b _0804F350
	.align 2, 0
_0804F258: .4byte 0x030057E0
_0804F25C: .4byte 0x00000C54
_0804F260: .4byte 0x00000802
_0804F264: .4byte 0x03004C30
_0804F268: .4byte 0x03002C30
_0804F26C:
	ldr r5, _0804F2D0 @ =0x030057E0
	ldr r0, _0804F2D4 @ =0x00000C52
	adds r4, r5, r0
	ldrh r0, [r4]
	ldr r1, _0804F2D8 @ =0x00000C48
	adds r6, r5, r1
	ldrh r2, [r6]
	cmp r0, r2
	beq _0804F350
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	subs r1, r1, r0
	strh r1, [r4]
	bl sub_08052A04
	cmp r0, #0
	bne _0804F350
	ldrh r1, [r4]
	ldrh r0, [r6]
	subs r1, r1, r0
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #3
	subs r0, #0x80
	cmp r1, r0
	bge _0804F350
	ldr r0, _0804F2DC @ =0x03004C30
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0804F350
	movs r0, #0x2f
	bl sub_080518F4
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052A2C
	movs r0, #0x2f
	bl sub_080518F4
	ldr r2, _0804F2E0 @ =0x03002C30
	ldrh r1, [r2, #2]
	adds r1, r1, r0
	b _0804F34E
	.align 2, 0
_0804F2D0: .4byte 0x030057E0
_0804F2D4: .4byte 0x00000C52
_0804F2D8: .4byte 0x00000C48
_0804F2DC: .4byte 0x03004C30
_0804F2E0: .4byte 0x03002C30
_0804F2E4:
	ldr r2, _0804F38C @ =0x030057E0
	ldr r0, _0804F390 @ =0x00000C52
	adds r4, r2, r0
	ldrh r1, [r4]
	subs r0, #0xa
	adds r5, r2, r0
	ldrh r0, [r5]
	subs r1, r1, r0
	adds r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #4
	adds r6, r2, r0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	bge _0804F350
	movs r0, #0x2f
	bl sub_080518F4
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	bl sub_08052A04
	cmp r0, #0
	bne _0804F350
	ldrh r0, [r4]
	ldrh r1, [r5]
	subs r0, r0, r1
	adds r0, #0x10
	cmp r0, #0x80
	ble _0804F350
	ldr r0, _0804F394 @ =0x03004C30
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r1, #0xf0
	ldrh r0, [r6]
	lsls r0, r0, #3
	cmp r1, r0
	bge _0804F350
	movs r0, #0x2f
	bl sub_080518F4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl sub_08052A2C
	movs r0, #0x2f
	bl sub_080518F4
	ldr r2, _0804F398 @ =0x03002C30
	ldrh r1, [r2, #2]
	subs r1, r1, r0
_0804F34E:
	strh r1, [r2, #2]
_0804F350:
	ldr r1, _0804F39C @ =0x03006D20
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r1, #0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F384
	ldr r4, _0804F38C @ =0x030057E0
	ldr r1, _0804F390 @ =0x00000C52
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _0804F3A0 @ =0x00000C56
	adds r1, r4, r2
	strb r0, [r1]
	ldr r1, _0804F3A4 @ =0x00000C54
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _0804F3A8 @ =0x00000C57
	adds r4, r4, r2
	strb r0, [r4]
	movs r1, #1
_0804F384:
	adds r0, r1, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804F38C: .4byte 0x030057E0
_0804F390: .4byte 0x00000C52
_0804F394: .4byte 0x03004C30
_0804F398: .4byte 0x03002C30
_0804F39C: .4byte 0x03006D20
_0804F3A0: .4byte 0x00000C56
_0804F3A4: .4byte 0x00000C54
_0804F3A8: .4byte 0x00000C57
	.syntax divided
