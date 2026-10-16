	.syntax unified

	thumb_func_start battle_cutscene_dispatch
battle_cutscene_dispatch: @ 0x0806564C
	push {r4, r5, r6, r7, lr}
	ldr r2, _080656C4 @ =0x03006F74
	ldr r3, [r2]
	ldrh r0, [r3, #2]
	adds r1, r0, #1
	strh r1, [r3, #2]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r5, #0
	ldr r7, _080656C8 @ =0x03001784
	ldrb r1, [r7]
	movs r0, #2
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _080656E0
	ldr r2, _080656CC @ =0x08485BD8
	ldr r1, _080656D0 @ =0x080AFB08
	ldr r0, [r3, #8]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	bne _08065686
	b _08065886
_08065686:
	ldr r0, _080656D4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08065694
	b _08065886
_08065694:
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, [r4]
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	cmp r0, #2
	bhi _080656A8
	b _080657EC
_080656A8:
	ldr r1, _080656D8 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x84
	strb r5, [r0]
	strb r5, [r1, #0x1b]
	ldr r1, _080656DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldrb r0, [r7]
	movs r1, #2
	orrs r0, r1
	strb r0, [r7]
	b _08065886
	.align 2, 0
_080656C4: .4byte 0x03006F74
_080656C8: .4byte 0x03001784
_080656CC: .4byte 0x08485BD8
_080656D0: .4byte 0x080AFB08
_080656D4: .4byte 0x0300058C
_080656D8: .4byte 0x03000440
_080656DC: .4byte 0x0300137C
_080656E0:
	ldr r0, [r3, #8]
	cmp r0, #5
	bls _080656E8
	b _08065886
_080656E8:
	lsls r0, r0, #2
	ldr r1, _080656F4 @ =_080656F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080656F4: .4byte _080656F8
_080656F8: @ jump table
	.4byte _08065710 @ case 0
	.4byte _08065764 @ case 1
	.4byte _08065764 @ case 2
	.4byte _08065764 @ case 3
	.4byte _080657F8 @ case 4
	.4byte _08065838 @ case 5
_08065710:
	ldr r2, _08065758 @ =0x08485BD8
	ldr r1, _0806575C @ =0x080AFB0B
	ldr r0, [r4]
	ldr r0, [r0, #8]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	bne _0806572C
	b _08065886
_0806572C:
	ldr r0, _08065760 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0806573A
	b _08065886
_0806573A:
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, [r4]
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	bl sub_0803FB0C
	movs r0, #1
	movs r1, #0
	movs r2, #7
	bl open_choice_menu
	b _08065886
	.align 2, 0
_08065758: .4byte 0x08485BD8
_0806575C: .4byte 0x080AFB0B
_08065760: .4byte 0x0300058C
_08065764:
	ldr r2, _080657B0 @ =0x08485BD8
	ldr r1, _080657B4 @ =0x080AFB0B
	ldr r0, [r4]
	ldr r0, [r0, #8]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	bne _08065780
	b _08065886
_08065780:
	bl poll_choice_menu
	cmp r0, #0
	bne _0806578A
	b _08065886
_0806578A:
	ldr r0, _080657B8 @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _080657DE
	ldr r0, _080657BC @ =0x03001784
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080657C0
	ldr r1, [r4]
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	cmp r0, #3
	bhi _080657EC
	b _080657CC
	.align 2, 0
_080657B0: .4byte 0x08485BD8
_080657B4: .4byte 0x080AFB0B
_080657B8: .4byte 0x03000440
_080657BC: .4byte 0x03001784
_080657C0:
	ldr r1, [r4]
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	cmp r0, #2
	bhi _080657D8
_080657CC:
	movs r0, #1
	movs r1, #0
	movs r2, #7
	bl open_choice_menu
	b _080657EC
_080657D8:
	adds r0, #1
	str r0, [r1, #8]
	b _080657EC
_080657DE:
	ldr r1, [r4]
	movs r0, #0
	str r0, [r1, #8]
	ldr r1, _080657F4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_080657EC:
	bl sub_0803FB0C
	b _08065886
	.align 2, 0
_080657F4: .4byte 0x0300137C
_080657F8:
	ldr r2, _08065830 @ =0x08485BD8
	ldr r1, _08065834 @ =0x080AFB0B
	ldr r0, [r4]
	ldr r0, [r0, #8]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08065886
	movs r0, #0
	bl play_song
	movs r0, #0
	bl play_sound_effect
	bl eeprom_setup_timer_irq
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #2]
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _08065886
	.align 2, 0
_08065830: .4byte 0x08485BD8
_08065834: .4byte 0x080AFB0B
_08065838:
	cmp r6, #0x1d
	bls _08065886
	movs r0, #4
	bl is_sound_playing_with_lock
	cmp r0, #0
	bne _08065886
	movs r0, #0
	b _08065850
_0806584A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08065850:
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	cmp r4, #3
	bgt _08065866
	movs r0, #0
	bl save_dispatch
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _0806584A
_08065866:
	ldr r4, _0806588C @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x7f
	ldrb r0, [r0]
	bl play_song
	ldr r0, [r4]
	str r5, [r0, #8]
	ldr r1, _08065890 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #3
	str r0, [r1]
	bl sub_0803FB0C
	bl serial_link_init
_08065886:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806588C: .4byte 0x03006F74
_08065890: .4byte 0x0300137C
	.syntax divided
