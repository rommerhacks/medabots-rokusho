	.syntax unified

	thumb_func_start sub_0801D878
sub_0801D878: @ 0x0801D878
	push {r4, r5, r6, lr}
	ldr r2, _0801D8BC @ =0x03001800
	adds r5, r2, #0
	adds r5, #0xde
	ldrb r1, [r5]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, #0x5a
	adds r2, #0xf8
	ldrb r3, [r2]
	movs r4, #1
	movs r2, #1
	ands r2, r3
	eors r2, r4
	bl update_battle_sprite_orbiting_positions
	ldr r0, _0801D8C0 @ =0x03000440
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801D8C4
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	movs r1, #0xac
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl clear_sprite_table_mask
	b _0801D8D6
	.align 2, 0
_0801D8BC: .4byte 0x03001800
_0801D8C0: .4byte 0x03000440
_0801D8C4:
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	movs r1, #0xac
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl set_sprite_hidden_flags
_0801D8D6:
	ldr r1, _0801D948 @ =0x03000440
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	movs r6, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bne _0801D940
	ldr r4, _0801D94C @ =0x03001800
	adds r5, r4, #0
	adds r5, #0xde
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	movs r1, #0xac
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #4
	bl set_sprite_hidden_flags
	movs r0, #0x40
	bl play_sound_effect
	ldr r2, _0801D950 @ =0x03002C30
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldr r1, _0801D954 @ =0x00001664
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldr r1, _0801D958 @ =0x00001665
	adds r0, r0, r1
	strb r6, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	subs r1, #0x25
	adds r0, r0, r1
	adds r0, r0, r2
	strh r6, [r0, #0x30]
	ldrb r0, [r5]
	adds r0, #0x71
	bl sub_08035694
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801D940:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D948: .4byte 0x03000440
_0801D94C: .4byte 0x03001800
_0801D950: .4byte 0x03002C30
_0801D954: .4byte 0x00001664
_0801D958: .4byte 0x00001665
	.syntax divided
