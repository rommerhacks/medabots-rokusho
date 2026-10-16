	.syntax unified

	thumb_func_start shop_complete_transaction
shop_complete_transaction: @ 0x080624AC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	bl poll_choice_menu
	cmp r0, #0
	bne _080624BA
	b _080625CA
_080624BA:
	ldr r0, _08062520 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x84
	movs r1, #0
	strb r1, [r2]
	strb r1, [r0, #0x1b]
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _080625C2
	ldr r0, _08062524 @ =0x03006F74
	ldr r2, [r0]
	ldrb r1, [r2, #5]
	adds r4, r0, #0
	cmp r1, #0
	bne _08062534
	ldr r0, _08062528 @ =0x03002B70
	ldr r1, [r0]
	ldr r2, [r2, #0x1c]
	subs r1, r1, r2
	str r1, [r0]
	movs r0, #0
	ldr r6, _0806252C @ =0x03004C40
	movs r5, #0x81
	lsls r5, r5, #0x12
_080624EC:
	lsls r3, r0, #0x18
	asrs r3, r3, #0x18
	lsls r0, r3, #3
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #1
	ldr r0, [r4]
	ldrb r2, [r0, #0x19]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r1, r6
	ldr r2, _08062530 @ =0x02023000
	adds r0, r3, r2
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r0, r3, #0x18
	asrs r3, r3, #0x18
	cmp r3, #0x77
	ble _080624EC
	b _0806258E
	.align 2, 0
_08062520: .4byte 0x03000440
_08062524: .4byte 0x03006F74
_08062528: .4byte 0x03002B70
_0806252C: .4byte 0x03004C40
_08062530: .4byte 0x02023000
_08062534:
	ldr r3, _08062548 @ =0x03002B70
	ldr r0, [r3]
	ldr r1, [r2, #0x1c]
	adds r1, r0, r1
	ldr r0, _0806254C @ =0x0001869E
	cmp r1, r0
	bhi _08062550
	str r1, [r3]
	b _08062554
	.align 2, 0
_08062548: .4byte 0x03002B70
_0806254C: .4byte 0x0001869E
_08062550:
	ldr r0, _080625D4 @ =0x0001869F
	str r0, [r3]
_08062554:
	movs r0, #0
	ldr r6, _080625D8 @ =0x03004C40
	movs r5, #0x81
	lsls r5, r5, #0x12
_0806255C:
	lsls r3, r0, #0x18
	asrs r3, r3, #0x18
	lsls r0, r3, #3
	adds r0, r0, r5
	ldrh r2, [r0]
	lsls r2, r2, #1
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r2, r2, r0
	adds r2, r2, r6
	ldr r0, _080625DC @ =0x02023000
	adds r1, r3, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r2]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r0, r3, #0x18
	asrs r3, r3, #0x18
	cmp r3, #0x77
	ble _0806255C
_0806258E:
	movs r0, #0
	movs r1, #7
	bl clear_sprite_table_mask
	ldr r4, _080625E0 @ =0x030004DE
	ldr r0, _080625E4 @ =0x03002B70
	ldr r1, [r0]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r5, #0
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x15
	movs r3, #1
	bl render_text_sprites_08040DB8
	subs r4, #0x1a
	strb r5, [r4]
_080625C2:
	ldr r1, _080625E8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080625CA:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080625D4: .4byte 0x0001869F
_080625D8: .4byte 0x03004C40
_080625DC: .4byte 0x02023000
_080625E0: .4byte 0x030004DE
_080625E4: .4byte 0x03002B70
_080625E8: .4byte 0x0300137C
	.syntax divided
