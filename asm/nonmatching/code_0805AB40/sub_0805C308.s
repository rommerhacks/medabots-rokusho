	.syntax unified

	thumb_func_start sub_0805C308
sub_0805C308: @ 0x0805C308
	push {r4, lr}
	ldr r4, _0805C348 @ =0x03006F74
	ldr r0, [r4]
	movs r1, #0x3a
	ldrsh r0, [r0, r1]
	bl sub_0805BB10
	ldr r1, [r4]
	strh r0, [r1, #0x3a]
	ldrb r0, [r1, #5]
	ldr r1, _0805C34C @ =0x03001780
	ldr r1, [r1]
	movs r2, #0x1f
	ands r1, r2
	bl sub_0805BEA0
	ldr r0, _0805C350 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0805C358
	movs r0, #2
	bl play_sound_effect
	ldr r1, [r4]
	ldrb r0, [r1, #5]
	ldrb r2, [r1, #4]
	cmp r0, r2
	bne _0805C354
	movs r0, #2
	b _0805C356
	.align 2, 0
_0805C348: .4byte 0x03006F74
_0805C34C: .4byte 0x03001780
_0805C350: .4byte 0x0300058C
_0805C354:
	subs r0, #1
_0805C356:
	strb r0, [r1, #5]
_0805C358:
	ldr r2, _0805C37C @ =0x0300058C
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0805C388
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0805C380 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	cmp r0, #2
	bne _0805C384
	ldrb r0, [r1, #4]
	b _0805C386
	.align 2, 0
_0805C37C: .4byte 0x0300058C
_0805C380: .4byte 0x03006F74
_0805C384:
	adds r0, #1
_0805C386:
	strb r0, [r1, #5]
_0805C388:
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0805C41C
	movs r0, #4
	bl play_sound_effect
	ldr r4, _0805C400 @ =0x03006F74
	ldr r1, [r4]
	ldrb r0, [r1, #5]
	cmp r0, #2
	bne _0805C410
	movs r0, #0
	strb r0, [r1, #5]
	ldr r1, [r4]
	movs r0, #0x14
	strh r0, [r1, #2]
	ldr r0, _0805C404 @ =0x03001780
	ldr r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	bl sub_0805BDC8
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	bl sub_0805BBF8
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	bl sub_0805BCC0
	movs r0, #3
	movs r1, #0
	bl sub_0805BEA0
	ldr r2, _0805C408 @ =0x03002C30
	ldr r0, [r4]
	ldrb r1, [r0, #5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x50
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r2, r2, r0
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0805C40C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0805C41A
	.align 2, 0
_0805C400: .4byte 0x03006F74
_0805C404: .4byte 0x03001780
_0805C408: .4byte 0x03002C30
_0805C40C: .4byte 0x0300137C
_0805C410:
	adds r1, #0x48
	movs r0, #0x2d
	strb r0, [r1]
	ldr r1, _0805C424 @ =0x0300137C
	movs r0, #6
_0805C41A:
	str r0, [r1]
_0805C41C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C424: .4byte 0x0300137C
	.syntax divided
