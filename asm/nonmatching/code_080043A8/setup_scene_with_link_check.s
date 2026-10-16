	.syntax unified

	thumb_func_start setup_scene_with_link_check
setup_scene_with_link_check: @ 0x0800667C
	push {r4, r5, r6, lr}
	sub sp, #0x24
	ldr r6, _080066D0 @ =0x02026000
	ldr r0, _080066D4 @ =0x020260D0
	str r0, [r6, #8]
	ldr r4, _080066D8 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r5, [r0]
	cmp r5, #0
	beq _080066E4
	ldr r0, _080066DC @ =0x03002414
	ldr r0, [r0]
	ldr r1, _080066E0 @ =0x00000B84
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r1, [sp]
	adds r1, r4, #0
	adds r1, #0x9b
	ldrb r1, [r1]
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
	adds r1, r6, #0
	bl setup_scene_bg_layers_and_sprites
	b _08006720
	.align 2, 0
_080066D0: .4byte 0x02026000
_080066D4: .4byte 0x020260D0
_080066D8: .4byte 0x03000440
_080066DC: .4byte 0x03002414
_080066E0: .4byte 0x00000B84
_080066E4:
	ldr r0, _08006750 @ =0x03002414
	ldr r0, [r0]
	ldr r2, _08006754 @ =0x00000B84
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r1, [sp]
	adds r1, r4, #0
	adds r1, #0x9b
	ldrb r1, [r1]
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
	str r5, [sp, #0x1c]
	adds r1, r6, #0
	bl setup_scene_bg_layers_and_sprites
_08006720:
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x20]
	ldr r4, _08006750 @ =0x03002414
	ldr r1, [r4]
	ldr r0, _08006754 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _08006758 @ =0x01000100
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, [r4]
	ldr r1, _0800675C @ =0x00001094
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, _08006760 @ =0x00001095
	adds r0, r0, r2
	strb r1, [r0]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08006750: .4byte 0x03002414
_08006754: .4byte 0x00000B84
_08006758: .4byte 0x01000100
_0800675C: .4byte 0x00001094
_08006760: .4byte 0x00001095
	.syntax divided
