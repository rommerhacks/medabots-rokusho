	.syntax unified

	thumb_func_start sub_08010C50
sub_08010C50: @ 0x08010C50
	push {r4, r5, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08010C74 @ =0x030057E0
	ldr r2, _08010C78 @ =0x00000C2E
	adds r1, r0, r2
	ldrb r0, [r1]
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	beq _08010C80
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08010C7C @ =0x0300137C
	movs r0, #0x3e
	b _08010CD4
	.align 2, 0
_08010C74: .4byte 0x030057E0
_08010C78: .4byte 0x00000C2E
_08010C7C: .4byte 0x0300137C
_08010C80:
	bl sub_080121CC
	ldr r4, _08010CA8 @ =0x03001800
	ldr r1, _08010CAC @ =0x00000169
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrb r1, [r1]
	bl sub_08042114
	cmp r0, #0
	beq _08010CB0
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	b _08010CBA
	.align 2, 0
_08010CA8: .4byte 0x03001800
_08010CAC: .4byte 0x00000169
_08010CB0:
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_08010CBA:
	ldr r1, _08010CDC @ =0x03001800
	ldr r2, _08010CE0 @ =0x00000169
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #1
	bl medapart_add_quantity
	ldr r1, _08010CE4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08010CD4:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010CDC: .4byte 0x03001800
_08010CE0: .4byte 0x00000169
_08010CE4: .4byte 0x0300137C
	.syntax divided
