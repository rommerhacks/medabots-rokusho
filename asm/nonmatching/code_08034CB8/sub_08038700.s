	.syntax unified

	thumb_func_start sub_08038700
sub_08038700: @ 0x08038700
	push {r4, r5, r6, r7, lr}
	ldr r4, _08038750 @ =0x03002C30
	ldr r2, _08038754 @ =0x03000440
	ldr r0, _08038758 @ =0x0000012F
	adds r3, r2, r0
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x28
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r3, [r3]
	lsls r0, r3, #6
	adds r0, r0, r4
	adds r0, #0x28
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _08038760
	ldr r2, _0803875C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x60
	ldrb r0, [r0]
	subs r0, #0x21
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r4
	adds r0, r0, r2
	movs r3, #0x9f
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #2
	b _08038782
	.align 2, 0
_08038750: .4byte 0x03002C30
_08038754: .4byte 0x03000440
_08038758: .4byte 0x0000012F
_0803875C: .4byte 0x03001800
_08038760:
	ldr r2, _080387F4 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x60
	ldrb r0, [r0]
	subs r0, #0x21
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r4
	adds r0, r0, r2
	movs r3, #0x9f
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	adds r0, #4
_08038782:
	strh r0, [r1, #4]
	adds r6, r2, #0
	adds r5, r6, #0
	adds r5, #0x60
	ldrb r0, [r5]
	ldr r1, _080387F8 @ =0x0000012F
	adds r4, r7, r1
	subs r0, #0x21
	ldrb r2, [r4]
	adds r0, r0, r2
	bl sub_080350E0
	ldr r0, _080387FC @ =0x083B5F80
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r1, [r4]
	bl process_sprite_anim_commands
	ldr r2, _08038800 @ =0x03002C30
	ldrb r1, [r4]
	lsls r0, r1, #6
	adds r0, r0, r2
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080387EC
	ldrb r0, [r5]
	subs r0, #0x21
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x5d
	lsls r1, r1, #6
	adds r1, r1, r2
	adds r0, r0, r6
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #4
	strh r0, [r1, #4]
	ldrb r0, [r5]
	subs r0, #0x21
	ldrb r3, [r4]
	adds r0, r0, r3
	bl sub_080350E0
	ldrb r0, [r4]
	movs r1, #1
	bl clear_battle_sprite_slot
_080387EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080387F4: .4byte 0x03001800
_080387F8: .4byte 0x0000012F
_080387FC: .4byte 0x083B5F80
_08038800: .4byte 0x03002C30
	.syntax divided
