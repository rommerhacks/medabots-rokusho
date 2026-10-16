	.syntax unified

	thumb_func_start sub_080303A4
sub_080303A4: @ 0x080303A4
	push {r4, r5, lr}
	ldr r0, _080303C4 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r2, [r1]
	adds r4, r0, #0
	cmp r2, #0x20
	bne _080303CC
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080303C8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08030474
	.align 2, 0
_080303C4: .4byte 0x03000440
_080303C8: .4byte 0x03001800
_080303CC:
	movs r3, #1
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _0803046A
	ldr r0, _08030418 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08030434
	ldr r1, _0803041C @ =0x03002C30
	ldr r0, _08030420 @ =0x00000842
	adds r2, r1, r0
	ldrh r0, [r2]
	subs r0, #1
	ldr r5, _08030424 @ =0x000001FF
	adds r3, r5, #0
	ands r0, r3
	strh r0, [r2]
	ldr r0, _08030428 @ =0x00000882
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	ands r0, r3
	strh r0, [r2]
	ldr r5, _0803042C @ =0x000008C2
	adds r2, r1, r5
	ldrh r0, [r2]
	subs r0, #1
	ands r0, r3
	strh r0, [r2]
	ldr r0, _08030430 @ =0x00000902
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	b _08030466
	.align 2, 0
_08030418: .4byte 0x03001800
_0803041C: .4byte 0x03002C30
_08030420: .4byte 0x00000842
_08030424: .4byte 0x000001FF
_08030428: .4byte 0x00000882
_0803042C: .4byte 0x000008C2
_08030430: .4byte 0x00000902
_08030434:
	ldr r1, _0803047C @ =0x03002C30
	ldr r5, _08030480 @ =0x00000842
	adds r2, r1, r5
	ldrh r0, [r2]
	adds r0, #1
	ldr r5, _08030484 @ =0x000001FF
	adds r3, r5, #0
	ands r0, r3
	strh r0, [r2]
	ldr r0, _08030488 @ =0x00000882
	adds r2, r1, r0
	ldrh r0, [r2]
	subs r0, #1
	ands r0, r3
	strh r0, [r2]
	ldr r5, _0803048C @ =0x000008C2
	adds r2, r1, r5
	ldrh r0, [r2]
	adds r0, #1
	ands r0, r3
	strh r0, [r2]
	ldr r0, _08030490 @ =0x00000902
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
_08030466:
	ands r0, r3
	strh r0, [r1]
_0803046A:
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_08030474:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803047C: .4byte 0x03002C30
_08030480: .4byte 0x00000842
_08030484: .4byte 0x000001FF
_08030488: .4byte 0x00000882
_0803048C: .4byte 0x000008C2
_08030490: .4byte 0x00000902
	.syntax divided
