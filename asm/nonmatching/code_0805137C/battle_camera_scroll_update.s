	.syntax unified

	thumb_func_start battle_camera_scroll_update
battle_camera_scroll_update: @ 0x08051FF0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r3, r1, #0
	ldr r2, _08052020 @ =0x030057E0
	ldr r4, _08052024 @ =0x00000C76
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08052006
	b _08052116
_08052006:
	subs r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08052012
	b _08052116
_08052012:
	cmp r1, #1
	beq _08052044
	cmp r1, #1
	bgt _08052028
	cmp r1, #0
	beq _08052032
	b _080520D4
	.align 2, 0
_08052020: .4byte 0x030057E0
_08052024: .4byte 0x00000C76
_08052028:
	cmp r3, #2
	beq _08052078
	cmp r3, #3
	beq _080520A4
	b _080520D4
_08052032:
	movs r0, #0xc7
	lsls r0, r0, #4
	adds r4, r2, r0
	ldrh r1, [r4]
	ldr r3, _08052040 @ =0x00000C4A
	b _08052080
	.align 2, 0
_08052040: .4byte 0x00000C4A
_08052044:
	movs r0, #0xc7
	lsls r0, r0, #4
	adds r4, r2, r0
	ldrh r1, [r4]
	ldr r3, _08052070 @ =0x00000C4A
	adds r0, r2, r3
	ldrh r0, [r0]
	subs r1, r1, r0
	adds r1, #0x10
	ldr r3, _08052074 @ =0x00000802
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, r0, #3
	cmp r1, r0
	bge _080520D4
	movs r0, #0x30
	bl sub_080518F4
	ldrh r1, [r4]
	adds r1, r1, r0
	b _08052092
	.align 2, 0
_08052070: .4byte 0x00000C4A
_08052074: .4byte 0x00000802
_08052078:
	ldr r0, _0805209C @ =0x00000C6E
	adds r4, r2, r0
	ldrh r1, [r4]
	ldr r3, _080520A0 @ =0x00000C48
_08052080:
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r1, r0
	beq _080520D4
	movs r0, #0x30
	bl sub_080518F4
	ldrh r1, [r4]
	subs r1, r1, r0
_08052092:
	strh r1, [r4]
	movs r0, #0x30
	bl advance_sprite_by_terrain_modifier
	b _080520D4
	.align 2, 0
_0805209C: .4byte 0x00000C6E
_080520A0: .4byte 0x00000C48
_080520A4:
	ldr r0, _0805211C @ =0x00000C6E
	adds r4, r2, r0
	ldrh r1, [r4]
	ldr r3, _08052120 @ =0x00000C48
	adds r0, r2, r3
	ldrh r0, [r0]
	subs r1, r1, r0
	adds r1, #0x10
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrh r0, [r0]
	lsls r0, r0, #3
	cmp r1, r0
	bge _080520D4
	movs r0, #0x30
	bl sub_080518F4
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r0, #0x30
	bl advance_sprite_by_terrain_modifier
_080520D4:
	ldr r4, _08052124 @ =0x030057E0
	ldr r0, _08052128 @ =0x00000C74
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052116
	ldr r0, _0805212C @ =0x03002C30
	ldr r2, _08052130 @ =0x00000BEA
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _08052134 @ =0x00000C2A
	adds r0, r0, r3
	strb r1, [r0]
	ldr r1, _0805211C @ =0x00000C6E
	adds r0, r4, r1
	ldrh r0, [r0]
	bl sub_080526F0
	ldr r2, _08052138 @ =0x00000C72
	adds r1, r4, r2
	strb r0, [r1]
	movs r3, #0xc7
	lsls r3, r3, #4
	adds r0, r4, r3
	ldrh r0, [r0]
	bl sub_08052714
	ldr r2, _0805213C @ =0x00000C73
	adds r1, r4, r2
	strb r0, [r1]
_08052116:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805211C: .4byte 0x00000C6E
_08052120: .4byte 0x00000C48
_08052124: .4byte 0x030057E0
_08052128: .4byte 0x00000C74
_0805212C: .4byte 0x03002C30
_08052130: .4byte 0x00000BEA
_08052134: .4byte 0x00000C2A
_08052138: .4byte 0x00000C72
_0805213C: .4byte 0x00000C73
	.syntax divided
