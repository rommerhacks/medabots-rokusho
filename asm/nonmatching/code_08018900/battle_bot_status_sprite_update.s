	.syntax unified

	thumb_func_start battle_bot_status_sprite_update
battle_bot_status_sprite_update: @ 0x08019600
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08019644 @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	adds r0, #0xc4
	ldrb r3, [r0]
	cmp r3, #0
	beq _08019708
	cmp r3, #0x1f
	bne _08019698
	ldr r2, _08019648 @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r3, r0, #0
	adds r3, #0x46
	lsls r0, r3, #6
	adds r2, r0, r2
	ldrh r0, [r2]
	cmp r0, #0
	beq _08019650
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #0x1f
	bne _08019650
	ldr r0, _0801964C @ =0x083B5F80
	ldr r0, [r0, #0x3c]
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _08019660
	.align 2, 0
_08019644: .4byte 0x03000590
_08019648: .4byte 0x03002C30
_0801964C: .4byte 0x083B5F80
_08019650:
	ldr r0, _08019688 @ =0x083B5F80
	ldr r0, [r0, #0x3c]
	adds r1, r1, r4
	adds r1, #0x46
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08019660:
	ldr r0, _0801968C @ =0x083C4C88
	ldr r1, _08019690 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	ldr r1, _08019694 @ =0x03002C30
	lsls r0, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r3, [r0, #0xb]
	adds r3, #4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl battle_setup_part_sprite
	b _08019708
	.align 2, 0
_08019688: .4byte 0x083B5F80
_0801968C: .4byte 0x083C4C88
_08019690: .4byte 0x0300052E
_08019694: .4byte 0x03002C30
_08019698:
	cmp r3, #0x26
	beq _080196A0
	cmp r3, #0x29
	bne _08019708
_080196A0:
	ldr r2, _080196CC @ =0x03002C30
	lsls r1, r4, #1
	adds r0, r1, r4
	adds r5, r0, #0
	adds r5, #0x46
	lsls r0, r5, #6
	adds r2, r0, r2
	ldrh r0, [r2]
	cmp r0, #0
	beq _080196D4
	adds r0, r2, #0
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, r3
	bne _080196D4
	ldr r0, _080196D0 @ =0x083B5F80
	ldr r0, [r0, #0x20]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	b _080196E4
	.align 2, 0
_080196CC: .4byte 0x03002C30
_080196D0: .4byte 0x083B5F80
_080196D4:
	ldr r0, _08019710 @ =0x083B5F80
	ldr r0, [r0, #0x20]
	adds r1, r1, r4
	adds r1, #0x46
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_080196E4:
	ldr r0, _08019714 @ =0x083C4C8C
	ldr r1, _08019718 @ =0x0300052E
	movs r2, #4
	bl memcpy_bytes_08041D04
	ldr r1, _0801971C @ =0x03002C30
	lsls r0, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r3, [r0, #0xb]
	adds r3, #4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl battle_setup_part_sprite
_08019708:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08019710: .4byte 0x083B5F80
_08019714: .4byte 0x083C4C8C
_08019718: .4byte 0x0300052E
_0801971C: .4byte 0x03002C30
	.syntax divided
