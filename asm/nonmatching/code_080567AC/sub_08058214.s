	.syntax unified

	thumb_func_start sub_08058214
	.global sub_08058214
sub_08058214: @ 0x08058214
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r1, _08058234 @ =0x030057A0
	ldrb r0, [r1, #0x15]
	adds r0, #1
	strb r0, [r1, #0x15]
	adds r4, r1, #0
	cmp r2, #7
	bls _08058228
	b _080586F6
_08058228:
	lsls r0, r2, #2
	ldr r1, _08058238 @ =_0805823C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058234: .4byte 0x030057A0
_08058238: .4byte _0805823C
_0805823C: @ jump table
	.4byte _0805825C @ case 0
	.4byte _08058330 @ case 1
	.4byte _08058380 @ case 2
	.4byte _08058410 @ case 3
	.4byte _08058458 @ case 4
	.4byte _08058538 @ case 5
	.4byte _08058556 @ case 6
	.4byte _080585EC @ case 7
_0805825C:
	movs r0, #6
	bl sub_0805889C
	ldr r1, _08058284 @ =0x030057A0
	adds r0, r1, #0
	adds r0, #0x16
	ldrb r1, [r1, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bls _08058278
	b _080586F6
_08058278:
	lsls r0, r0, #2
	ldr r1, _08058288 @ =_0805828C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058284: .4byte 0x030057A0
_08058288: .4byte _0805828C
_0805828C: @ jump table
	.4byte _080582A4 @ case 0
	.4byte _080582C0 @ case 1
	.4byte _08058314 @ case 2
	.4byte _080582DC @ case 3
	.4byte _080582F8 @ case 4
	.4byte _08058314 @ case 5
_080582A4:
	ldr r1, _080582BC @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #0xc0
	bl sub_08058A88
	b _080586F6
	.align 2, 0
_080582BC: .4byte 0x030057A0
_080582C0:
	ldr r1, _080582D8 @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #0x10
	bl sub_08058A88
	b _080586F6
	.align 2, 0
_080582D8: .4byte 0x030057A0
_080582DC:
	ldr r1, _080582F4 @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #4
	bl sub_08058A88
	b _080586F6
	.align 2, 0
_080582F4: .4byte 0x030057A0
_080582F8:
	ldr r1, _08058310 @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #0xa
	bl sub_08058A88
	b _080586F6
	.align 2, 0
_08058310: .4byte 0x030057A0
_08058314:
	ldr r1, _0805832C @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #2
	bl sub_08058A88
	b _080586F6
	.align 2, 0
_0805832C: .4byte 0x030057A0
_08058330:
	movs r0, #3
	bl sub_0805889C
	ldr r1, _08058354 @ =0x030057A0
	adds r0, r1, #0
	adds r0, #0x16
	ldrb r1, [r1, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _0805836C
	cmp r0, #1
	bgt _08058358
	cmp r0, #0
	beq _0805835E
	b _080586F6
	.align 2, 0
_08058354: .4byte 0x030057A0
_08058358:
	cmp r0, #2
	beq _08058376
	b _080586F6
_0805835E:
	ldr r1, _08058368 @ =0x00000BB8
	movs r0, #0
	bl sub_08058908
	b _080586F6
	.align 2, 0
_08058368: .4byte 0x00000BB8
_0805836C:
	movs r0, #1
	movs r1, #2
	bl sub_08058908
	b _080586F6
_08058376:
	movs r0, #2
	movs r1, #8
	bl sub_08058908
	b _080586F6
_08058380:
	ldr r2, _080583F8 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	ldr r4, _080583FC @ =0x030057E0
	cmp r0, #0
	beq _08058398
	ldr r0, _08058400 @ =0x00000C54
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
_08058398:
	ldrb r2, [r2]
	movs r0, #0x80
	ands r0, r2
	adds r3, r2, #0
	cmp r0, #0
	beq _080583AE
	ldr r0, _08058400 @ =0x00000C54
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
_080583AE:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _080583C0
	ldr r3, _08058404 @ =0x00000C52
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
_080583C0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080583D2
	ldr r0, _08058404 @ =0x00000C52
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
_080583D2:
	ldr r1, _08058404 @ =0x00000C52
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _08058408 @ =0x00000C56
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _08058400 @ =0x00000C54
	adds r0, r4, r3
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _0805840C @ =0x00000C57
	adds r1, r4, r2
	strb r0, [r1]
	bl calculate_camera_scroll_from_npc
	b _080586F6
	.align 2, 0
_080583F8: .4byte 0x03001798
_080583FC: .4byte 0x030057E0
_08058400: .4byte 0x00000C54
_08058404: .4byte 0x00000C52
_08058408: .4byte 0x00000C56
_0805840C: .4byte 0x00000C57
_08058410:
	ldr r0, _08058454 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0805842E
	ldrb r0, [r4, #0x12]
	subs r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0805842E
	movs r0, #0x1f
	strb r0, [r4, #0x12]
_0805842E:
	ldr r0, _08058454 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0805843C
	b _080586F6
_0805843C:
	ldrb r0, [r4, #0x12]
	adds r0, #1
	strb r0, [r4, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bhi _0805844C
	b _080586F6
_0805844C:
	movs r0, #0
	strb r0, [r4, #0x12]
	b _080586F6
	.align 2, 0
_08058454: .4byte 0x03001798
_08058458:
	movs r0, #6
	bl sub_0805889C
	ldr r1, _0805847C @ =0x030057A0
	adds r0, r1, #0
	adds r0, #0x16
	ldrb r1, [r1, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #5
	bhi _08058504
	lsls r0, r0, #2
	ldr r1, _08058480 @ =_08058484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805847C: .4byte 0x030057A0
_08058480: .4byte _08058484
_08058484: @ jump table
	.4byte _080584D4 @ case 0
	.4byte _0805849C @ case 1
	.4byte _080584B8 @ case 2
	.4byte _080584D4 @ case 3
	.4byte _080584D4 @ case 4
	.4byte _080584F0 @ case 5
_0805849C:
	ldr r1, _080584B4 @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #3
	bl sub_08058A88
	b _08058504
	.align 2, 0
_080584B4: .4byte 0x030057A0
_080584B8:
	ldr r1, _080584D0 @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #4
	bl sub_08058A88
	b _08058504
	.align 2, 0
_080584D0: .4byte 0x030057A0
_080584D4:
	ldr r1, _080584EC @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #2
	bl sub_08058A88
	b _08058504
	.align 2, 0
_080584EC: .4byte 0x030057A0
_080584F0:
	ldr r1, _08058528 @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #3
	bl sub_08058A88
_08058504:
	ldr r5, _0805852C @ =0x04000052
	ldr r4, _08058530 @ =0x03006F40
	ldrb r0, [r4, #4]
	movs r2, #0x3f
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #8
	ldrb r3, [r4, #3]
	adds r0, r2, #0
	ands r0, r3
	orrs r0, r1
	strh r0, [r5]
	ldr r1, _08058534 @ =0x04000054
	ldrb r0, [r4, #5]
	ands r2, r0
	strh r2, [r1]
	b _080586F6
	.align 2, 0
_08058528: .4byte 0x030057A0
_0805852C: .4byte 0x04000052
_08058530: .4byte 0x03006F40
_08058534: .4byte 0x04000054
_08058538:
	ldrb r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x16
	adds r1, r0, r1
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r2, #0xb0
	bl sub_08058A88
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	b _080586F6
_08058556:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	beq _08058562
	b _080586F6
_08058562:
	movs r0, #3
	bl sub_0805889C
	adds r0, r4, #0
	adds r0, #0x16
	ldrb r3, [r4, #0x14]
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _08058594
	cmp r0, #1
	bgt _08058584
	cmp r0, #0
	beq _0805858A
	b _080585A6
_08058584:
	cmp r0, #2
	beq _0805859E
	b _080585A6
_0805858A:
	movs r0, #0
	movs r1, #0x10
	bl sub_080589B0
	b _080585A6
_08058594:
	ldrh r1, [r4, #0x1e]
	movs r0, #1
	bl sub_080589B0
	b _080585A6
_0805859E:
	movs r0, #2
	movs r1, #2
	bl sub_080589B0
_080585A6:
	ldr r0, _080585E0 @ =0x0847E45C
	ldr r3, _080585E4 @ =0x030057A0
	ldrh r1, [r3, #0x20]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r2, #0
	ldr r0, [r1]
	adds r4, r3, #0
	cmp r0, #0
	beq _080585CC
	ldr r3, _080585E8 @ =0x00000FFF
_080585BE:
	adds r1, #4
	adds r2, #1
	cmp r2, r3
	bgt _080585CC
	ldr r0, [r1]
	cmp r0, #0
	bne _080585BE
_080585CC:
	strh r2, [r4, #0x1e]
	ldrh r1, [r4, #0x30]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhs _080585DA
	b _080586F6
_080585DA:
	subs r0, r2, #1
	strh r0, [r4, #0x30]
	b _080586F6
	.align 2, 0
_080585E0: .4byte 0x0847E45C
_080585E4: .4byte 0x030057A0
_080585E8: .4byte 0x00000FFF
_080585EC:
	movs r0, #5
	bl sub_0805889C
	ldr r1, _08058610 @ =0x030057A0
	adds r0, r1, #0
	adds r0, #0x16
	ldrb r1, [r1, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bhi _08058698
	lsls r0, r0, #2
	ldr r1, _08058614 @ =_08058618
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058610: .4byte 0x030057A0
_08058614: .4byte _08058618
_08058618: @ jump table
	.4byte _0805862C @ case 0
	.4byte _0805862C @ case 1
	.4byte _08058648 @ case 2
	.4byte _08058664 @ case 3
	.4byte _08058680 @ case 4
_0805862C:
	ldr r0, _08058644 @ =0x030057A0
	adds r1, r0, #0
	adds r1, #0x16
	ldrb r0, [r0, #0x14]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0x20
	bl update_anim_counter
	b _08058698
	.align 2, 0
_08058644: .4byte 0x030057A0
_08058648:
	ldr r0, _08058660 @ =0x030057A0
	adds r1, r0, #0
	adds r1, #0x16
	ldrb r0, [r0, #0x14]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0x80
	bl update_anim_counter
	b _08058698
	.align 2, 0
_08058660: .4byte 0x030057A0
_08058664:
	ldr r0, _0805867C @ =0x030057A0
	adds r1, r0, #0
	adds r1, #0x16
	ldrb r0, [r0, #0x14]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0xa0
	bl update_anim_counter
	b _08058698
	.align 2, 0
_0805867C: .4byte 0x030057A0
_08058680:
	ldr r1, _080586B8 @ =0x030057A0
	adds r0, r1, #0
	adds r0, #0x16
	ldrb r1, [r1, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #1
	bl update_anim_counter
_08058698:
	ldr r2, _080586B8 @ =0x030057A0
	adds r0, r2, #0
	adds r0, #0x16
	ldrb r1, [r2, #0x14]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _080586BC
	cmp r0, #2
	ble _080586F6
	cmp r0, #3
	beq _080586DC
	b _080586F6
	.align 2, 0
_080586B8: .4byte 0x030057A0
_080586BC:
	ldr r0, _080586D8 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080586F6
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_08047BB4
	b _080586F6
	.align 2, 0
_080586D8: .4byte 0x03001798
_080586DC:
	ldr r0, _08058754 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080586F6
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl sub_08047BA8
_080586F6:
	ldr r0, _08058758 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08058720
	ldr r4, _0805875C @ =0x030057A0
	ldrb r0, [r4, #0x14]
	adds r0, #1
	strb r0, [r4, #0x14]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08058716
	movs r0, #0
	strb r0, [r4, #0x14]
_08058716:
	bl clear_all_battle_sprites
	ldrb r0, [r4, #0x14]
	bl dispatch_by_index
_08058720:
	ldr r4, _08058754 @ =0x03001798
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08058730
	bl handle_battle_end_state_transition
_08058730:
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0805873C
	b _08058896
_0805873C:
	ldr r1, _0805875C @ =0x030057A0
	ldrb r0, [r1, #0x14]
	adds r4, r1, #0
	cmp r0, #6
	bls _08058748
	b _08058896
_08058748:
	lsls r0, r0, #2
	ldr r1, _08058760 @ =_08058764
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058754: .4byte 0x03001798
_08058758: .4byte 0x0300058C
_0805875C: .4byte 0x030057A0
_08058760: .4byte _08058764
_08058764: @ jump table
	.4byte _08058896 @ case 0
	.4byte _08058896 @ case 1
	.4byte _08058896 @ case 2
	.4byte _08058780 @ case 3
	.4byte _08058844 @ case 4
	.4byte _08058896 @ case 5
	.4byte _0805884C @ case 6
_08058780:
	ldr r4, _080587B0 @ =0x030057A0
	movs r0, #0
	strb r0, [r4, #0x10]
	bl clear_all_battle_sprites
	ldrb r0, [r4, #0x12]
	ldr r5, _080587B4 @ =0x030057E0
	ldr r2, _080587B8 @ =0x00000C52
	adds r1, r5, r2
	ldrh r1, [r1]
	ldr r3, _080587BC @ =0x00000C54
	adds r2, r5, r3
	ldrh r2, [r2]
	movs r3, #0
	bl init_sprite_affine_matrices_and_state
	ldrb r0, [r4, #0x12]
	cmp r0, #0xe
	bne _080587C4
	ldr r0, _080587C0 @ =0x00000C5C
	adds r1, r5, r0
	movs r0, #0xc
	b _080587CE
	.align 2, 0
_080587B0: .4byte 0x030057A0
_080587B4: .4byte 0x030057E0
_080587B8: .4byte 0x00000C52
_080587BC: .4byte 0x00000C54
_080587C0: .4byte 0x00000C5C
_080587C4:
	cmp r0, #0x12
	bne _080587D0
	ldr r2, _0805881C @ =0x00000C5C
	adds r1, r5, r2
	movs r0, #0xb
_080587CE:
	strb r0, [r1]
_080587D0:
	ldr r0, _08058820 @ =0x030057A0
	ldrb r0, [r0, #0x12]
	cmp r0, #0xe
	beq _080587DC
	cmp r0, #0x12
	bne _08058810
_080587DC:
	bl decompress_battle_tile_graphics
	ldr r1, _08058824 @ =0x040000D4
	ldr r4, _08058828 @ =0x083F8634
	ldr r3, _0805882C @ =0x083D29A6
	ldr r2, _08058830 @ =0x030057E0
	ldr r0, _0805881C @ =0x00000C5C
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _08058834 @ =0x05000200
	str r0, [r1, #4]
	ldr r0, _08058838 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldrb r0, [r5]
	ldr r1, _0805883C @ =0x00000C28
	adds r2, r2, r1
	strb r0, [r2]
	bl load_battle_terrain_data
_08058810:
	ldr r1, _08058840 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08058896
	.align 2, 0
_0805881C: .4byte 0x00000C5C
_08058820: .4byte 0x030057A0
_08058824: .4byte 0x040000D4
_08058828: .4byte 0x083F8634
_0805882C: .4byte 0x083D29A6
_08058830: .4byte 0x030057E0
_08058834: .4byte 0x05000200
_08058838: .4byte 0x84000008
_0805883C: .4byte 0x00000C28
_08058840: .4byte 0x0300137C
_08058844:
	ldrb r0, [r4]
	bl play_sound_effect
	b _08058896
_0805884C:
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r1, [r0]
	cmp r1, #0
	bne _08058896
	ldrh r0, [r4, #0x24]
	cmp r0, #0
	beq _0805887E
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r4, #0x1e]
	cmp r0, r2
	blo _0805887E
	strh r1, [r4, #0x30]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0805887E
	strh r1, [r4, #0x2e]
_0805887E:
	movs r0, #0
	strb r0, [r4, #0x15]
	ldrb r0, [r4, #0x14]
	bl sub_08058B04
	bl init_cursor_state
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08058896:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
