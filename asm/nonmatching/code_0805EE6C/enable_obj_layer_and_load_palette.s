	.syntax unified

	thumb_func_start enable_obj_layer_and_load_palette
enable_obj_layer_and_load_palette: @ 0x08061B78
	push {r4, lr}
	sub sp, #8
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08061CD4 @ =0x0850DDB8
	ldr r1, _08061CD8 @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08061CDC @ =0x084E2E58
	ldr r1, _08061CE0 @ =0x0202F840
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08061CE4 @ =0x084C69B8
	ldr r1, _08061CE8 @ =0x0202F860
	movs r2, #8
	bl CpuFastSet
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _08061CEC @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0xc0
	ldr r1, _08061CF0 @ =0x0202F9E0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08061CF4 @ =0x0202F980
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08061CF8 @ =0x0850DEF8
	ldr r1, _08061CFC @ =0x0202F880
	movs r2, #0x40
	bl CpuFastSet
	ldr r0, _08061D00 @ =0x08798D2C
	ldr r1, _08061D04 @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _08061D08 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08061D0C @ =0x03006F74
	ldr r0, [r4]
	ldrb r0, [r0, #5]
	bl render_battle_medapart_list
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08061C3A
	ldr r1, _08061D10 @ =0x02023000
	adds r0, r1, #0
	adds r0, #0x78
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08061D14 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0xa
	bl draw_number_tall
	ldr r1, _08061D18 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
_08061C3A:
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #1
	bls _08061C68
	ldr r0, _08061D1C @ =0x02023078
	ldrb r0, [r0]
	ldr r1, _08061D20 @ =0x02023001
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08061D14 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0xc
	bl draw_number_tall
_08061C68:
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #2
	bls _08061C96
	ldr r0, _08061D1C @ =0x02023078
	ldrb r0, [r0]
	ldr r3, _08061D24 @ =0x02023002
	adds r0, r0, r3
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08061D14 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0xe
	bl draw_number_tall
_08061C96:
	ldr r0, [r4]
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #3
	bls _08061CC4
	ldr r0, _08061D1C @ =0x02023078
	ldrb r0, [r0]
	ldr r1, _08061D28 @ =0x02023003
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #6
	str r1, [sp]
	ldr r1, _08061D14 @ =0x0400000A
	ldrh r1, [r1]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	str r1, [sp, #4]
	movs r1, #2
	movs r2, #0x1b
	movs r3, #0x10
	bl draw_number_tall
_08061CC4:
	ldr r1, _08061D2C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061CD4: .4byte 0x0850DDB8
_08061CD8: .4byte 0x0202F9A0
_08061CDC: .4byte 0x084E2E58
_08061CE0: .4byte 0x0202F840
_08061CE4: .4byte 0x084C69B8
_08061CE8: .4byte 0x0202F860
_08061CEC: .4byte 0x0202F9C0
_08061CF0: .4byte 0x0202F9E0
_08061CF4: .4byte 0x0202F980
_08061CF8: .4byte 0x0850DEF8
_08061CFC: .4byte 0x0202F880
_08061D00: .4byte 0x08798D2C
_08061D04: .4byte 0x0202FA00
_08061D08: .4byte 0x03000440
_08061D0C: .4byte 0x03006F74
_08061D10: .4byte 0x02023000
_08061D14: .4byte 0x0400000A
_08061D18: .4byte 0x03002C30
_08061D1C: .4byte 0x02023078
_08061D20: .4byte 0x02023001
_08061D24: .4byte 0x02023002
_08061D28: .4byte 0x02023003
_08061D2C: .4byte 0x0300137C
	.syntax divided
