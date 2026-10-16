	.syntax unified

	thumb_func_start battle_set_damage_vs_armor
	.global battle_set_damage_vs_armor
battle_set_damage_vs_armor: @ 0x08034F68
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08034F9C @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x59
	ldrb r2, [r2]
	cmp r2, r4
	ble _08034FA4
	ldr r3, _08034FA0 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xc8
	movs r2, #0
	movs r1, #0
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r0, #7
	strb r2, [r0]
	b _08034FBE
	.align 2, 0
_08034F9C: .4byte 0x03000590
_08034FA0: .4byte 0x03001800
_08034FA4:
	ldr r1, _08034FC4 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xc8
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	subs r0, r4, r2
	adds r2, r1, #0
	adds r2, #0xca
	strh r0, [r2]
	adds r1, #0xd1
	movs r0, #1
	strb r0, [r1]
_08034FBE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034FC4: .4byte 0x03001800
	.syntax divided
