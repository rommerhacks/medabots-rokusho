	.syntax unified

	thumb_func_start sub_08006764
sub_08006764: @ 0x08006764
	push {r4, r5, lr}
	sub sp, #0x20
	ldr r0, _080067BC @ =0x03000440
	mov ip, r0
	adds r0, #0x5e
	ldrb r5, [r0]
	cmp r5, #0
	beq _080067CC
	ldr r0, _080067C0 @ =0x03002414
	ldr r0, [r0]
	ldr r1, _080067C4 @ =0x00000B84
	adds r0, r0, r1
	ldr r1, _080067C8 @ =0x02026000
	mov r2, ip
	adds r2, #0x98
	ldrb r2, [r2]
	mov r3, ip
	adds r3, #0x99
	ldrb r3, [r3]
	mov r4, ip
	adds r4, #0x9a
	ldrb r4, [r4]
	str r4, [sp]
	mov r4, ip
	adds r4, #0x9b
	ldrb r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	movs r4, #0x32
	str r4, [sp, #0xc]
	movs r4, #0xe1
	lsls r4, r4, #1
	str r4, [sp, #0x10]
	movs r4, #8
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	movs r4, #1
	str r4, [sp, #0x1c]
	bl setup_scene_bg_layers_and_sprites
	b _0800680E
	.align 2, 0
_080067BC: .4byte 0x03000440
_080067C0: .4byte 0x03002414
_080067C4: .4byte 0x00000B84
_080067C8: .4byte 0x02026000
_080067CC:
	ldr r0, _08006818 @ =0x03002414
	ldr r0, [r0]
	ldr r1, _0800681C @ =0x00000B84
	adds r0, r0, r1
	ldr r1, _08006820 @ =0x02026000
	mov r2, ip
	adds r2, #0x98
	ldrb r2, [r2]
	mov r3, ip
	adds r3, #0x99
	ldrb r3, [r3]
	mov r4, ip
	adds r4, #0x9a
	ldrb r4, [r4]
	str r4, [sp]
	mov r4, ip
	adds r4, #0x9b
	ldrb r4, [r4]
	str r4, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	movs r4, #0x32
	str r4, [sp, #0xc]
	movs r4, #0xe1
	lsls r4, r4, #1
	str r4, [sp, #0x10]
	movs r4, #8
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	str r5, [sp, #0x1c]
	bl setup_scene_bg_layers_and_sprites
_0800680E:
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08006818: .4byte 0x03002414
_0800681C: .4byte 0x00000B84
_08006820: .4byte 0x02026000
	.syntax divided
