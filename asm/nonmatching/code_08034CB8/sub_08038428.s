	.syntax unified

	thumb_func_start sub_08038428
sub_08038428: @ 0x08038428
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _08038504 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x86
	ldrh r0, [r0]
	movs r6, #7
	ands r6, r0
	cmp r6, #0
	beq _08038440
	b _0803857A
_08038440:
	ldr r0, _08038508 @ =0x0000012F
	adds r0, r0, r1
	mov r8, r0
	ldrb r0, [r0]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xa
	bl find_next_free_sprite_slot
	adds r4, r0, #0
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r7, _0803850C @ =0x03002C30
	lsls r4, r4, #6
	adds r5, r4, r7
	movs r1, #0
	ldr r0, _08038510 @ =0x0000C604
	strh r0, [r5]
	strb r1, [r5, #0x1c]
	movs r0, #0x78
	strh r0, [r5, #2]
	strh r0, [r5, #4]
	movs r0, #0x40
	strb r0, [r5, #8]
	strb r0, [r5, #9]
	strh r6, [r5, #0x18]
	movs r0, #6
	strb r0, [r5, #0xa]
	movs r0, #0xf0
	strb r0, [r5, #0xb]
	ldr r0, _08038514 @ =0x00007706
	strh r0, [r5, #6]
	adds r2, r5, #0
	adds r2, #0x29
	movs r0, #2
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x24
	movs r4, #3
	strb r4, [r0]
	subs r0, #1
	strb r1, [r0]
	bl rng_next_080424B8
	adds r6, r0, #0
	ands r6, r4
	ldr r0, _08038518 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08038524
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #6
	adds r1, r1, r7
	ldr r3, _0803851C @ =0x083AF6D0
	lsls r2, r6, #1
	lsls r0, r6, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	ldr r4, _08038520 @ =0x000001FF
	adds r1, r4, #0
	ands r0, r1
	strh r0, [r5, #2]
	mov r0, r8
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r7
	adds r2, #1
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrh r0, [r2]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5, #4]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r7
	ldrh r0, [r0, #2]
	adds r0, #0x10
	strh r0, [r5, #0x30]
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r7
	ldrh r0, [r0, #4]
	adds r0, #4
	b _08038578
	.align 2, 0
_08038504: .4byte 0x03000440
_08038508: .4byte 0x0000012F
_0803850C: .4byte 0x03002C30
_08038510: .4byte 0x0000C604
_08038514: .4byte 0x00007706
_08038518: .4byte 0x03001800
_0803851C: .4byte 0x083AF6D0
_08038520: .4byte 0x000001FF
_08038524:
	mov r4, r8
	ldrb r2, [r4]
	lsls r2, r2, #6
	adds r2, r2, r7
	ldr r4, _08038584 @ =0x083AF6D0
	lsls r3, r6, #1
	lsls r0, r6, #2
	adds r0, r0, r4
	ldrh r1, [r0]
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	movs r0, #0xf0
	subs r0, r0, r1
	ldr r2, _08038588 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r5, #2]
	mov r0, r8
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r7
	adds r3, #1
	lsls r3, r3, #1
	adds r3, r3, r4
	ldrh r0, [r3]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5, #4]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r7
	ldrh r0, [r0, #2]
	subs r0, #0x10
	strh r0, [r5, #0x30]
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r7
	ldrh r0, [r0, #4]
	adds r0, #6
_08038578:
	strh r0, [r5, #0x32]
_0803857A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038584: .4byte 0x083AF6D0
_08038588: .4byte 0x000001FF
	.syntax divided
