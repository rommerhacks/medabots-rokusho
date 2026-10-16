	.syntax unified

	thumb_func_start load_map_npc_sprites
	.global load_map_npc_sprites
load_map_npc_sprites: @ 0x0805137C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08051424 @ =0xFFFFFDD0
	add sp, r4
	str r0, [sp, #0x204]
	ldr r0, _08051428 @ =0x03005DBC
	str r0, [sp, #0x218]
	movs r4, #0x80
	lsls r4, r4, #2
	add r0, sp, #4
	adds r1, r4, #0
	bl sub_080496C8
	ldr r0, [sp, #0x218]
	add r1, sp, #4
	adds r2, r4, #0
	bl memcpy_u8
	ldr r0, [sp, #0x218]
	adds r1, r4, #0
	bl sub_080496C8
	movs r1, #0
	str r1, [sp, #0x210]
	movs r5, #0
	movs r2, #0
	str r2, [sp, #0x208]
	movs r3, #0
	str r3, [sp, #0x20c]
_080513BC:
	ldr r2, _0805142C @ =0x084837A0
	ldr r1, _08051430 @ =0x030057E0
	ldr r4, _08051434 @ =0x000007FE
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r7, [r0]
	ldrb r0, [r7]
	adds r6, r1, #0
	ldr r1, [sp, #0x20c]
	adds r1, #1
	str r1, [sp, #0x220]
	cmp r0, #0xff
	bne _080513DC
	b _08051718
_080513DC:
	ldrh r0, [r7, #6]
	ldr r2, _08051438 @ =0x03005FDF
	ldrb r2, [r2]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	adds r3, r7, #0
	adds r3, #8
	str r3, [sp, #0x228]
	cmp r0, #0
	bne _080513F4
	b _0805170C
_080513F4:
	ldrb r0, [r7, #5]
	ldr r4, [sp, #0x20c]
	cmp r0, r4
	beq _080513FE
	b _0805170C
_080513FE:
	ldrh r1, [r7, #2]
	ldr r2, _0805143C @ =0x00000FFF
	adds r0, r2, #0
	ands r0, r1
	bl sub_08053194
	cmp r0, #0
	beq _08051410
	b _0805170C
_08051410:
	movs r4, #0
	movs r3, #0
	str r3, [sp, #0x214]
	ldr r0, [sp, #0x204]
	cmp r0, #0
	bne _08051440
	ldr r6, _08051430 @ =0x030057E0
	adds r1, r5, #1
	str r1, [sp, #0x21c]
	b _080514BE
	.align 2, 0
_08051424: .4byte 0xFFFFFDD0
_08051428: .4byte 0x03005DBC
_0805142C: .4byte 0x084837A0
_08051430: .4byte 0x030057E0
_08051434: .4byte 0x000007FE
_08051438: .4byte 0x03005FDF
_0805143C: .4byte 0x00000FFF
_08051440:
	ldr r6, _08051458 @ =0x030057E0
	adds r2, r5, #1
	str r2, [sp, #0x21c]
	ldr r3, [sp, #0x204]
	cmp r3, #0
	blt _080514B8
	cmp r3, #2
	bgt _080514B8
	movs r0, #0
	str r0, [sp, #0x208]
	b _08051462
	.align 2, 0
_08051458: .4byte 0x030057E0
_0805145C:
	ldr r1, [sp, #0x208]
	adds r1, #1
	str r1, [sp, #0x208]
_08051462:
	ldr r2, [sp, #0x208]
	cmp r2, #0x3f
	bgt _08051488
	ldrh r3, [r7, #2]
	lsls r0, r2, #3
	add r0, sp
	adds r0, #4
	ldrh r2, [r0, #2]
	ldr r1, _080514AC @ =0x00000FFF
	ands r1, r3
	ldr r0, _080514AC @ =0x00000FFF
	ands r0, r2
	cmp r1, r0
	bne _08051482
	movs r3, #1
	str r3, [sp, #0x214]
_08051482:
	ldr r0, [sp, #0x214]
	cmp r0, #0
	beq _0805145C
_08051488:
	ldr r1, [sp, #0x208]
	cmp r1, #0x40
	beq _080514B0
	ldr r2, [sp, #0x204]
	cmp r2, #1
	beq _080514BE
	ldr r3, [sp, #0x204]
	cmp r3, #2
	bne _080514B8
	ldr r1, [sp, #0x208]
	lsls r0, r1, #3
	add r0, sp
	adds r0, #4
	ldrb r0, [r0, #4]
	lsrs r0, r0, #7
	cmp r0, #1
	beq _080514B8
	b _0805170A
	.align 2, 0
_080514AC: .4byte 0x00000FFF
_080514B0:
	ldr r2, [sp, #0x204]
	cmp r2, #2
	bne _080514B8
	movs r4, #1
_080514B8:
	cmp r4, #0
	beq _080514BE
	b _0805170A
_080514BE:
	ldrb r0, [r7, #4]
	lsrs r0, r0, #4
	mov sb, r0
	lsls r3, r5, #3
	adds r1, r3, r6
	ldrb r2, [r7]
	ldr r4, _080514F4 @ =0x000005DC
	adds r0, r1, r4
	strb r2, [r0]
	ldrb r2, [r7, #1]
	adds r4, #1
	adds r0, r1, r4
	strb r2, [r0]
	ldrh r0, [r7, #2]
	ldr r2, _080514F8 @ =0x000005DE
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r7, #2]
	lsrs r0, r0, #0xc
	str r3, [sp, #0x224]
	cmp r0, #4
	beq _08051500
	cmp r0, #4
	bgt _080514FC
	cmp r0, #0
	beq _08051500
	b _0805151C
	.align 2, 0
_080514F4: .4byte 0x000005DC
_080514F8: .4byte 0x000005DE
_080514FC:
	cmp r0, #6
	bne _0805151C
_08051500:
	ldrb r1, [r7, #1]
	ldr r3, _0805155C @ =0x030057E0
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r3, r4
	ldrh r0, [r0]
	lsrs r0, r0, #1
	muls r0, r1, r0
	ldrb r1, [r7]
	adds r0, r0, r1
	ldr r2, _08051560 @ =0x03005FF0
	adds r0, r0, r2
	movs r1, #7
	strb r1, [r0]
_0805151C:
	ldr r3, [sp, #0x224]
	ldr r4, _0805155C @ =0x030057E0
	adds r2, r3, r4
	movs r0, #0xbc
	lsls r0, r0, #3
	adds r2, r2, r0
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r7, #4]
	cmp r0, #0xff
	bne _08051538
	b _0805170A
_08051538:
	ldr r1, [sp, #0x210]
	cmp r1, #0x1d
	ble _08051540
	b _08051704
_08051540:
	ldrh r0, [r7, #2]
	lsrs r0, r0, #0xc
	cmp r0, #2
	beq _08051578
	cmp r0, #2
	bgt _08051564
	cmp r0, #0
	beq _08051578
	adds r1, #0x31
	mov r8, r1
	ldr r2, [sp, #0x210]
	adds r2, #0x5b
	mov sl, r2
	b _080515E8
	.align 2, 0
_0805155C: .4byte 0x030057E0
_08051560: .4byte 0x03005FF0
_08051564:
	cmp r0, #4
	beq _08051578
	ldr r3, [sp, #0x210]
	adds r3, #0x31
	mov r8, r3
	ldr r4, [sp, #0x210]
	adds r4, #0x5b
	mov sl, r4
	cmp r0, #6
	bne _080515E8
_08051578:
	ldr r6, [sp, #0x210]
	adds r6, #0x31
	lsls r5, r6, #0x18
	lsrs r5, r5, #0x18
	mov r0, sb
	lsls r2, r0, #1
	add r2, sb
	lsls r2, r2, #2
	mov r4, sb
	movs r1, #1
	mov sb, r1
	str r1, [sp]
	adds r0, r5, #0
	ldr r1, _08051748 @ =0x0000C804
	adds r3, r4, #0
	bl init_battle_sprite_entry_08048818
	ldr r3, [sp, #0x224]
	ldr r0, _0805174C @ =0x030057E0
	adds r2, r3, r0
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r2, r2, r1
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl resolve_tile_from_battle_state
	lsls r4, r6, #6
	ldr r2, _08051750 @ =0x03002C30
	adds r4, r4, r2
	strh r0, [r4, #0x30]
	adds r0, r5, #0
	bl sub_0804877C
	ldr r1, _08051754 @ =0x083D2B8D
	ldrh r0, [r4, #0x30]
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r6
	ldr r3, [sp, #0x210]
	adds r3, #0x5b
	mov sl, r3
	cmp r0, #0
	beq _080515E8
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov r4, sb
	str r4, [sp]
	ldr r1, _08051758 @ =0x0000CC0C
	movs r2, #0x90
	movs r3, #0xe
	bl init_battle_sprite_entry_08048818
_080515E8:
	ldr r0, [sp, #0x224]
	ldr r1, _0805174C @ =0x030057E0
	adds r3, r0, r1
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r3, r3, r2
	movs r0, #0x1f
	ldr r2, [sp, #0x210]
	ands r2, r0
	ldrb r0, [r3]
	movs r4, #0x20
	rsbs r4, r4, #0
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	ldrb r0, [r7, #4]
	lsrs r0, r0, #4
	mov sb, r0
	ldr r0, _0805175C @ =0x030055A0
	mov r1, r8
	lsls r2, r1, #2
	adds r2, r2, r0
	ldrh r0, [r7, #2]
	ldr r3, _08051760 @ =0x00000FFF
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2]
	mov r4, r8
	lsls r2, r4, #6
	ldr r0, _08051750 @ =0x03002C30
	adds r2, r2, r0
	adds r0, r2, #0
	adds r0, #0x2b
	mov r1, sb
	strb r1, [r0]
	ldrb r1, [r7]
	ldr r3, _0805174C @ =0x030057E0
	ldr r4, _08051764 @ =0x00000C48
	adds r0, r3, r4
	lsls r1, r1, #4
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r2, #0xc]
	movs r3, #0xff
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #0xc]
	ldrb r1, [r7, #1]
	ldr r4, _0805174C @ =0x030057E0
	ldr r3, _08051768 @ =0x00000C4A
	adds r0, r4, r3
	lsls r1, r1, #4
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #8
	ldr r0, [r2, #0x10]
	movs r4, #0xff
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #0x10]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r7, #4]
	movs r4, #0xf
	adds r1, r4, #0
	ands r1, r0
	ldr r2, [sp, #0x224]
	ldr r0, _0805176C @ =0x03005DBC
	adds r3, r2, r0
	adds r0, r5, #0
	adds r2, r3, #0
	str r3, [sp, #0x22c]
	bl set_sprite_anim_and_store
	mov r1, sb
	lsls r6, r1, #2
	ldrb r0, [r7, #4]
	ands r4, r0
	adds r4, r6, r4
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080493D4
	ldr r3, [sp, #0x22c]
	ldr r2, [sp, #0x204]
	cmp r2, #0
	beq _080516C4
	ldr r4, [sp, #0x214]
	cmp r4, #0
	beq _080516C4
	ldr r1, [sp, #0x208]
	lsls r0, r1, #3
	mov r4, sp
	adds r4, r4, r0
	adds r4, #4
	ldrb r1, [r4, #5]
	adds r0, r5, #0
	adds r2, r3, #0
	bl set_sprite_anim_and_store
	ldrb r1, [r4, #5]
	adds r1, r1, r6
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_080493D4
_080516C4:
	mov r2, r8
	lsls r3, r2, #6
	ldr r4, _08051750 @ =0x03002C30
	adds r3, r3, r4
	adds r1, r3, #0
	adds r1, #0x2c
	movs r0, #0
	strb r0, [r1]
	mov r0, sl
	lsls r2, r0, #6
	adds r2, r2, r4
	ldr r1, [r3, #0xc]
	asrs r1, r1, #8
	lsls r1, r1, #8
	ldr r0, [r2, #0xc]
	movs r4, #0xff
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #0xc]
	ldr r1, [r3, #0x10]
	asrs r1, r1, #8
	subs r1, #5
	lsls r1, r1, #8
	ldr r0, [r2, #0x10]
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #0x10]
	ldrh r0, [r3, #2]
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	subs r0, #5
	strh r0, [r2, #4]
_08051704:
	ldr r0, [sp, #0x210]
	adds r0, #1
	str r0, [sp, #0x210]
_0805170A:
	ldr r5, [sp, #0x21c]
_0805170C:
	ldr r7, [sp, #0x228]
	ldrb r0, [r7]
	ldr r6, _0805174C @ =0x030057E0
	cmp r0, #0xff
	beq _08051718
	b _080513DC
_08051718:
	ldr r1, [sp, #0x220]
	str r1, [sp, #0x20c]
	cmp r1, #0x1f
	bgt _08051722
	b _080513BC
_08051722:
	ldr r2, _08051770 @ =0x00000C8E
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08051784
	movs r2, #0
	ldr r5, _08051760 @ =0x00000FFF
	adds r3, r0, #0
	ldr r0, _08051774 @ =0x00000CB4
	adds r4, r6, r0
_08051736:
	ldr r0, [sp, #0x218]
	ldrh r1, [r0, #2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, r3
	bne _08051778
	strb r2, [r4]
	b _08051784
	.align 2, 0
_08051748: .4byte 0x0000C804
_0805174C: .4byte 0x030057E0
_08051750: .4byte 0x03002C30
_08051754: .4byte 0x083D2B8D
_08051758: .4byte 0x0000CC0C
_0805175C: .4byte 0x030055A0
_08051760: .4byte 0x00000FFF
_08051764: .4byte 0x00000C48
_08051768: .4byte 0x00000C4A
_0805176C: .4byte 0x03005DBC
_08051770: .4byte 0x00000C8E
_08051774: .4byte 0x00000CB4
_08051778:
	ldr r1, [sp, #0x218]
	adds r1, #8
	str r1, [sp, #0x218]
	adds r2, #1
	cmp r2, #0x3f
	ble _08051736
_08051784:
	ldr r2, _080517A0 @ =0x00000CBA
	adds r1, r6, r2
	movs r0, #2
	strb r0, [r1]
	movs r3, #0x8c
	lsls r3, r3, #2
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080517A0: .4byte 0x00000CBA
	.syntax divided
