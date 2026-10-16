	.syntax unified

	thumb_func_start sub_080053C8
sub_080053C8: @ 0x080053C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r7, _08005420 @ =0x02026000
	ldr r0, _08005424 @ =0x020260D0
	str r0, [r7, #8]
	ldr r4, _08005428 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r6, [r0]
	cmp r6, #0
	beq _08005438
	ldr r0, _0800542C @ =0x03002414
	ldr r0, [r0]
	ldr r1, _08005430 @ =0x00000B84
	adds r0, r0, r1
	ldr r5, _08005434 @ =0x030017A0
	adds r4, #0x51
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r2, [r1, #3]
	ldrb r3, [r1, #4]
	ldrb r1, [r1, #5]
	str r1, [sp]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r1, [r1, #6]
	str r1, [sp, #4]
	movs r1, #0x28
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #0x10]
	movs r1, #8
	str r1, [sp, #0x14]
	movs r1, #1
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r1, r7, #0
	bl setup_scene_bg_layers_and_sprites
	b _08005478
	.align 2, 0
_08005420: .4byte 0x02026000
_08005424: .4byte 0x020260D0
_08005428: .4byte 0x03000440
_0800542C: .4byte 0x03002414
_08005430: .4byte 0x00000B84
_08005434: .4byte 0x030017A0
_08005438:
	ldr r0, _080054A8 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _080054AC @ =0x00000B84
	adds r0, r0, r2
	ldr r5, _080054B0 @ =0x030017A0
	adds r4, #0x51
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r2, [r1, #3]
	ldrb r3, [r1, #4]
	ldrb r1, [r1, #5]
	str r1, [sp]
	ldrb r1, [r4]
	lsls r1, r1, #3
	adds r1, r1, r5
	ldrb r1, [r1, #6]
	str r1, [sp, #4]
	movs r1, #0x28
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #0x10]
	movs r1, #8
	str r1, [sp, #0x14]
	movs r1, #1
	str r1, [sp, #0x18]
	str r6, [sp, #0x1c]
	adds r1, r7, #0
	bl setup_scene_bg_layers_and_sprites
_08005478:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r4, _080054A8 @ =0x03002414
	ldr r1, [r4]
	ldr r0, _080054AC @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _080054B4 @ =0x01000100
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, [r4]
	ldr r1, _080054B8 @ =0x00001094
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _080054BC @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080054A8: .4byte 0x03002414
_080054AC: .4byte 0x00000B84
_080054B0: .4byte 0x030017A0
_080054B4: .4byte 0x01000100
_080054B8: .4byte 0x00001094
_080054BC: .4byte 0x00001095
	.syntax divided
