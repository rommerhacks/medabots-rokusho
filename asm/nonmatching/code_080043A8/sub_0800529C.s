	.syntax unified

	thumb_func_start sub_0800529C
	.global sub_0800529C
sub_0800529C: @ 0x0800529C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	ldr r0, _08005344 @ =0x02026000
	mov r8, r0
	movs r1, #0xd0
	movs r2, #0
	bl sub_0803F624
	ldr r4, _08005348 @ =0x020260D0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	movs r2, #0
	bl sub_0803F624
	ldr r5, _0800534C @ =0x020268D0
	adds r0, r5, #0
	movs r1, #0x60
	movs r2, #0
	bl sub_0803F624
	ldr r1, _08005350 @ =0x03000430
	movs r0, #2
	str r0, [r1]
	ldr r6, _08005354 @ =0x03002414
	ldr r1, _08005358 @ =0x02024000
	str r1, [r6]
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r2, _0800535C @ =0x01000426
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, _08005360 @ =0x03005308
	str r5, [r0]
	ldr r1, [r6]
	ldr r2, _08005364 @ =0x083D1BF8
	mov r0, r8
	adds r3, r4, #0
	bl sub_08047414
	mov r1, r8
	str r4, [r1, #8]
	ldr r4, _08005368 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r7, [r0]
	cmp r7, #0
	beq _08005374
	ldr r0, [r6]
	ldr r1, _0800536C @ =0x00000B84
	adds r0, r0, r1
	ldr r5, _08005370 @ =0x030017A0
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
	mov r1, r8
	bl setup_scene_bg_layers_and_sprites
	b _080053B2
	.align 2, 0
_08005344: .4byte 0x02026000
_08005348: .4byte 0x020260D0
_0800534C: .4byte 0x020268D0
_08005350: .4byte 0x03000430
_08005354: .4byte 0x03002414
_08005358: .4byte 0x02024000
_0800535C: .4byte 0x01000426
_08005360: .4byte 0x03005308
_08005364: .4byte 0x083D1BF8
_08005368: .4byte 0x03000440
_0800536C: .4byte 0x00000B84
_08005370: .4byte 0x030017A0
_08005374:
	ldr r0, [r6]
	ldr r1, _080053C0 @ =0x00000B84
	adds r0, r0, r1
	ldr r5, _080053C4 @ =0x030017A0
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
	str r7, [sp, #0x1c]
	mov r1, r8
	bl setup_scene_bg_layers_and_sprites
_080053B2:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080053C0: .4byte 0x00000B84
_080053C4: .4byte 0x030017A0
	.syntax divided
