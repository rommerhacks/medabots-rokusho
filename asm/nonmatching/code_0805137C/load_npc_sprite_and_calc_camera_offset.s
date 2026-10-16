	.syntax unified

	thumb_func_start load_npc_sprite_and_calc_camera_offset
	.global load_npc_sprite_and_calc_camera_offset
load_npc_sprite_and_calc_camera_offset: @ 0x080528AC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _080528F4 @ =0x083F92F4
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _080528F8 @ =0x03006D14
	ldr r1, [r1]
	bl LZ77UnCompVram
	ldr r5, _080528FC @ =0x030057E0
	ldr r1, _08052900 @ =0x000007FE
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0
	bl sub_08052960
	lsrs r0, r0, #1
	cmp r0, #0xe
	bhi _08052908
	adds r0, r4, #0
	movs r1, #0
	bl sub_08052960
	lsrs r0, r0, #1
	movs r1, #0xf
	subs r1, r1, r0
	lsls r1, r1, #3
	ldr r2, _08052904 @ =0x00000C48
	adds r0, r5, r2
	strh r1, [r0]
	b _08052910
	.align 2, 0
_080528F4: .4byte 0x083F92F4
_080528F8: .4byte 0x03006D14
_080528FC: .4byte 0x030057E0
_08052900: .4byte 0x000007FE
_08052904: .4byte 0x00000C48
_08052908:
	ldr r0, _0805293C @ =0x00000C48
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
_08052910:
	ldr r5, _08052940 @ =0x030057E0
	ldr r1, _08052944 @ =0x000007FE
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #1
	bl sub_08052960
	lsrs r0, r0, #1
	cmp r0, #9
	bhi _0805294C
	adds r0, r4, #0
	movs r1, #1
	bl sub_08052960
	lsrs r0, r0, #1
	movs r1, #0xa
	subs r1, r1, r0
	lsls r1, r1, #3
	ldr r2, _08052948 @ =0x00000C4A
	adds r0, r5, r2
	strh r1, [r0]
	b _08052954
	.align 2, 0
_0805293C: .4byte 0x00000C48
_08052940: .4byte 0x030057E0
_08052944: .4byte 0x000007FE
_08052948: .4byte 0x00000C4A
_0805294C:
	ldr r0, _0805295C @ =0x00000C4A
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
_08052954:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805295C: .4byte 0x00000C4A
	.syntax divided
