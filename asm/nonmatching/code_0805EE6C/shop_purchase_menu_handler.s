	.syntax unified

	thumb_func_start shop_purchase_menu_handler
shop_purchase_menu_handler: @ 0x08061D98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r4, _08061DE4 @ =0x03001780
	ldrb r1, [r4]
	movs r0, #8
	movs r2, #4
	bl sub_08041C14
	bl update_battle_sprite_priority_flags
	ldr r0, _08061DE8 @ =0x03001798
	ldrb r1, [r0]
	movs r3, #8
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08061DF8
	ldr r0, _08061DEC @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	bne _08061DCE
	b _080620B6
_08061DCE:
	movs r0, #4
	bl play_sound_effect
	ldr r0, _08061DF0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08061DF4 @ =0x0300137C
	movs r0, #9
	str r0, [r1]
	b _08062306
	.align 2, 0
_08061DE4: .4byte 0x03001780
_08061DE8: .4byte 0x03001798
_08061DEC: .4byte 0x03006F74
_08061DF0: .4byte 0x03000440
_08061DF4: .4byte 0x0300137C
_08061DF8:
	ldr r0, _08061E84 @ =0x03006F74
	ldr r2, [r0]
	ldrb r1, [r2, #5]
	mov r8, r0
	cmp r1, #0
	bne _08061E94
	ldr r0, [r4]
	ands r0, r3
	cmp r0, #0
	beq _08061EF8
	ldr r6, _08061E88 @ =0x02023000
	ldrb r0, [r2, #0x1a]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08061E2C
	ldr r0, _08061E8C @ =0x03002C30
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
_08061E2C:
	ldr r4, _08061E90 @ =0x03002B70
	ldrb r2, [r6]
	movs r1, #0x81
	lsls r1, r1, #0x12
	ldr r0, [r1, #4]
	muls r2, r0, r2
	ldrb r3, [r6, #1]
	ldr r0, [r1, #0xc]
	muls r0, r3, r0
	adds r2, r2, r0
	ldrb r3, [r6, #2]
	ldr r0, [r1, #0x14]
	muls r0, r3, r0
	adds r2, r2, r0
	ldrb r3, [r6, #3]
	ldr r0, [r1, #0x1c]
	muls r0, r3, r0
	adds r2, r2, r0
	mov r5, r8
	ldr r0, [r5]
	ldrb r5, [r0, #0x1a]
	lsls r3, r5, #3
	adds r1, #4
	adds r1, r3, r1
	ldr r0, [r1]
	adds r2, r2, r0
	ldr r0, [r4]
	cmp r0, r2
	blo _08061F16
	movs r1, #0x81
	lsls r1, r1, #0x12
	adds r0, r3, r1
	ldrb r0, [r0, #2]
	adds r1, r5, r6
	ldrb r1, [r1]
	adds r0, r0, r1
	cmp r0, #0x62
	bgt _08061F16
	ldr r0, _08061E8C @ =0x03002C30
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r0, r2
	b _08061EE0
	.align 2, 0
_08061E84: .4byte 0x03006F74
_08061E88: .4byte 0x02023000
_08061E8C: .4byte 0x03002C30
_08061E90: .4byte 0x03002B70
_08061E94:
	ldr r0, [r4]
	ands r0, r3
	cmp r0, #0
	beq _08061EF8
	ldr r1, _08061EF0 @ =0x02023000
	adds r0, r1, #0
	adds r0, #0x78
	ldrb r0, [r0]
	ldrb r2, [r2, #0x1a]
	adds r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r3, r6, r1
	ldrb r0, [r3]
	cmp r0, #0
	beq _08061EC8
	ldr r0, _08061EF4 @ =0x03002C30
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r4, #0
	orrs r1, r2
	strh r1, [r0]
_08061EC8:
	lsls r0, r6, #3
	movs r5, #0x81
	lsls r5, r5, #0x12
	adds r0, r0, r5
	ldrb r0, [r0, #2]
	ldrb r3, [r3]
	cmp r0, r3
	bls _08061F16
	ldr r0, _08061EF4 @ =0x03002C30
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
_08061EE0:
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r1, r2
	strh r1, [r0]
	b _08061F16
	.align 2, 0
_08061EF0: .4byte 0x02023000
_08061EF4: .4byte 0x03002C30
_08061EF8:
	ldr r4, _08061F48 @ =0x03002C30
	movs r5, #0xb0
	lsls r5, r5, #2
	adds r3, r4, r5
	ldrh r2, [r3]
	ldr r1, _08061F4C @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
_08061F16:
	mov r1, r8
	ldr r5, [r1]
	adds r3, r5, #0
	adds r3, #0x20
	ldrb r0, [r3]
	ldr r7, _08061F50 @ =0x03001798
	cmp r0, #1
	bls _08061FA2
	ldrb r1, [r7]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08061F5C
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	bne _08061F58
	ldr r1, _08061F54 @ =0x02023078
	ldrb r0, [r1]
	cmp r0, #0
	bne _08061F40
	b _08062158
_08061F40:
	subs r0, #1
	strb r0, [r1]
	b _08061F80
	.align 2, 0
_08061F48: .4byte 0x03002C30
_08061F4C: .4byte 0x0000BFFF
_08061F50: .4byte 0x03001798
_08061F54: .4byte 0x02023078
_08061F58:
	subs r0, #1
	b _08061F98
_08061F5C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08061FA2
	ldrb r2, [r5, #0x1a]
	ldr r6, _08061F8C @ =0x02023078
	ldrb r4, [r6]
	adds r1, r2, r4
	ldrb r3, [r3]
	subs r0, r3, #1
	cmp r1, r0
	blt _08061F76
	b _08062158
_08061F76:
	adds r0, r2, #0
	cmp r0, #3
	bne _08061F90
	adds r0, r4, #1
	strb r0, [r6]
_08061F80:
	movs r0, #1
	bl render_battle_medapart_list
	bl update_battle_sprite_priority_flags
	b _08062194
	.align 2, 0
_08061F8C: .4byte 0x02023078
_08061F90:
	cmp r0, r3
	blo _08061F96
	b _08062158
_08061F96:
	adds r0, r2, #1
_08061F98:
	strb r0, [r5, #0x1a]
	movs r0, #2
	bl play_sound_effect
	b _08062158
_08061FA2:
	ldrb r1, [r7]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08062070
	mov r2, r8
	ldr r0, [r2]
	ldr r3, _0806203C @ =0x02023000
	mov ip, r3
	mov r2, ip
	adds r2, #0x78
	ldrb r1, [r2]
	ldrb r4, [r0, #0x1a]
	adds r1, r1, r4
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldrb r0, [r0, #5]
	cmp r0, #0
	bne _08062050
	ldr r5, _08062040 @ =0x03002B70
	mov sb, r5
	ldrb r2, [r2]
	adds r0, r2, r3
	ldrb r1, [r0]
	lsls r0, r2, #3
	ldr r4, _08062044 @ =0x02040004
	adds r0, r0, r4
	ldr r0, [r0]
	adds r3, r1, #0
	muls r3, r0, r3
	adds r0, r2, #1
	ldr r5, _08062048 @ =0x02023001
	adds r1, r2, r5
	ldrb r1, [r1]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	muls r0, r1, r0
	adds r3, r3, r0
	adds r0, r2, #2
	adds r5, #1
	adds r1, r2, r5
	ldrb r1, [r1]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	muls r0, r1, r0
	adds r3, r3, r0
	adds r0, r2, #3
	ldr r1, _0806204C @ =0x02023003
	adds r2, r2, r1
	ldrb r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	muls r0, r1, r0
	adds r3, r3, r0
	lsls r1, r6, #3
	adds r4, r1, r4
	ldr r0, [r4]
	adds r3, r3, r0
	mov r2, sb
	ldr r0, [r2]
	cmp r0, r3
	blo _08062070
	movs r3, #0x81
	lsls r3, r3, #0x12
	adds r0, r1, r3
	ldrb r0, [r0, #2]
	mov r4, ip
	adds r1, r6, r4
	ldrb r2, [r1]
	adds r0, r0, r2
	cmp r0, #0x62
	bgt _08062070
	b _08062064
	.align 2, 0
_0806203C: .4byte 0x02023000
_08062040: .4byte 0x03002B70
_08062044: .4byte 0x02040004
_08062048: .4byte 0x02023001
_0806204C: .4byte 0x02023003
_08062050:
	lsls r0, r6, #3
	movs r5, #0x81
	lsls r5, r5, #0x12
	adds r0, r0, r5
	ldr r2, _0806206C @ =0x02023000
	adds r1, r6, r2
	ldrb r0, [r0, #2]
	ldrb r2, [r1]
	cmp r0, r2
	bls _08062070
_08062064:
	adds r0, r2, #1
	strb r0, [r1]
	b _08062194
	.align 2, 0
_0806206C: .4byte 0x02023000
_08062070:
	ldrb r1, [r7]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080620A0
	mov r3, r8
	ldr r1, [r3]
	ldr r2, _0806209C @ =0x02023000
	adds r0, r2, #0
	adds r0, #0x78
	ldrb r0, [r0]
	ldrb r1, [r1, #0x1a]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080620A0
	subs r0, #1
	strb r0, [r1]
	b _08062194
	.align 2, 0
_0806209C: .4byte 0x02023000
_080620A0:
	ldr r0, _080620C0 @ =0x0300058C
	ldrb r1, [r0]
	movs r4, #1
	ands r4, r1
	cmp r4, #0
	beq _08062118
	mov r4, r8
	ldr r0, [r4]
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	bne _080620C4
_080620B6:
	movs r0, #6
	bl play_sound_effect
	b _08062306
	.align 2, 0
_080620C0: .4byte 0x0300058C
_080620C4:
	movs r0, #4
	bl play_sound_effect
	movs r2, #0
	ldr r4, _0806210C @ =0x03002C30
	ldr r5, _08062110 @ =0x0000BFFF
_080620D0:
	lsls r1, r2, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	adds r2, #0xb
	lsls r2, r2, #6
	adds r2, r2, r4
	ldrh r3, [r2]
	adds r0, r5, #0
	ands r0, r3
	strh r0, [r2]
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #1
	ble _080620D0
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _08062114 @ =0x0300137C
	movs r0, #6
	str r0, [r1]
	b _08062306
	.align 2, 0
_0806210C: .4byte 0x03002C30
_08062110: .4byte 0x0000BFFF
_08062114: .4byte 0x0300137C
_08062118:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08062122
	b _08062306
_08062122:
	movs r0, #5
	bl play_sound_effect
	movs r0, #0x61
	movs r1, #7
	bl clear_sprite_table_mask
	movs r0, #0xd
	movs r1, #0x34
	bl clear_sprite_table_mask
	movs r0, #0x45
	movs r1, #0x1c
	bl clear_sprite_table_mask
	ldr r0, _08062150 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _08062154 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08062306
	.align 2, 0
_08062150: .4byte 0x03000440
_08062154: .4byte 0x0300137C
_08062158:
	ldr r3, _0806218C @ =0x03002C30
	ldr r0, _08062190 @ =0x03006F74
	ldr r2, [r0]
	ldrb r0, [r2, #0x1a]
	lsls r0, r0, #4
	adds r0, #0x54
	movs r5, #0x81
	lsls r5, r5, #2
	adds r1, r3, r5
	strh r0, [r1]
	ldrb r0, [r2, #0x1a]
	lsls r0, r0, #4
	adds r0, #0x54
	movs r4, #0xb1
	lsls r4, r4, #2
	adds r1, r3, r4
	strh r0, [r1]
	ldrb r0, [r2, #0x1a]
	lsls r0, r0, #4
	adds r0, #0x54
	movs r5, #0xc1
	lsls r5, r5, #2
	adds r1, r3, r5
	strh r0, [r1]
	b _08062306
	.align 2, 0
_0806218C: .4byte 0x03002C30
_08062190: .4byte 0x03006F74
_08062194:
	movs r0, #2
	bl play_sound_effect
	ldr r4, _08062280 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _080621CC
	ldr r1, _08062284 @ =0x02023000
	adds r0, r1, #0
	adds r0, #0x78
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08062288 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0xa
	bl draw_number_tall
_080621CC:
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #1
	bls _080621FA
	ldr r0, _0806228C @ =0x02023078
	ldrb r0, [r0]
	ldr r1, _08062290 @ =0x02023001
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08062288 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0xc
	bl draw_number_tall
_080621FA:
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #2
	bls _08062228
	ldr r0, _0806228C @ =0x02023078
	ldrb r0, [r0]
	ldr r2, _08062294 @ =0x02023002
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08062288 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0xe
	bl draw_number_tall
_08062228:
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #3
	bls _08062256
	ldr r0, _0806228C @ =0x02023078
	ldrb r0, [r0]
	ldr r3, _08062298 @ =0x02023003
	adds r0, r0, r3
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08062288 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0x10
	bl draw_number_tall
_08062256:
	ldr r1, [r4]
	movs r0, #0
	str r0, [r1, #0x1c]
	movs r2, #0
	mov r8, r4
	ldr r5, _08062284 @ =0x02023000
	ldr r4, _0806229C @ =0x02040004
_08062264:
	mov r0, r8
	ldr r3, [r0]
	ldrb r0, [r3, #5]
	cmp r0, #0
	bne _080622A0
	lsls r2, r2, #0x18
	asrs r0, r2, #0x18
	adds r1, r0, r5
	ldrb r1, [r1]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	muls r1, r0, r1
	b _080622B2
	.align 2, 0
_08062280: .4byte 0x03006F74
_08062284: .4byte 0x02023000
_08062288: .4byte 0x0400000A
_0806228C: .4byte 0x02023078
_08062290: .4byte 0x02023001
_08062294: .4byte 0x02023002
_08062298: .4byte 0x02023003
_0806229C: .4byte 0x02040004
_080622A0:
	lsls r2, r2, #0x18
	asrs r0, r2, #0x18
	adds r1, r0, r5
	ldrb r1, [r1]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	muls r1, r0, r1
	lsrs r1, r1, #1
_080622B2:
	ldr r0, [r3, #0x1c]
	adds r0, r0, r1
	str r0, [r3, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r2, r1
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x77
	ble _08062264
	mov r2, r8
	ldr r1, [r2]
	ldr r0, [r1, #0x1c]
	ldr r2, _08062314 @ =0x0001869F
	cmp r0, r2
	bls _080622D4
	str r2, [r1, #0x1c]
_080622D4:
	movs r0, #0x61
	movs r1, #7
	bl clear_sprite_table_mask
	ldr r4, _08062318 @ =0x030004DE
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r0, #0x1c]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x61
	movs r2, #0x13
	movs r3, #5
	bl render_text_sprites_08040DB8
_08062306:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062314: .4byte 0x0001869F
_08062318: .4byte 0x030004DE
	.syntax divided
