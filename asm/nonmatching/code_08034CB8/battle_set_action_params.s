	.syntax unified

	thumb_func_start battle_set_action_params
	.global battle_set_action_params
battle_set_action_params: @ 0x08036E64
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r3, #0
	adds r0, r5, #0
	subs r0, #0xd
	cmp r0, #1
	bhi _08036EA8
	ldr r1, _08036EA0 @ =0x03000590
	lsls r0, r4, #8
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0xc9
	strb r5, [r0]
	ldr r0, _08036EA4 @ =0x03001800
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xca
	strb r0, [r1]
	adds r0, r2, #0
	bl sub_08036E54
	adds r1, r4, #0
	adds r1, #0xcb
	strb r0, [r1]
	lsls r0, r7, #1
	b _08036F86
	.align 2, 0
_08036EA0: .4byte 0x03000590
_08036EA4: .4byte 0x03001800
_08036EA8:
	adds r0, r5, #0
	subs r0, #0xf
	cmp r0, #1
	bhi _08036EE8
	ldr r1, _08036EE0 @ =0x03000590
	lsls r0, r4, #8
	adds r6, r0, r1
	adds r0, r6, #0
	adds r0, #0xc9
	movs r4, #0
	strb r5, [r0]
	ldr r0, _08036EE4 @ =0x03001800
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r0, #1
	adds r1, r6, #0
	adds r1, #0xca
	strb r0, [r1]
	lsrs r0, r7, #3
	bl sub_08036E54
	adds r1, r6, #0
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xcc
	strb r4, [r0]
	b _08036F90
	.align 2, 0
_08036EE0: .4byte 0x03000590
_08036EE4: .4byte 0x03001800
_08036EE8:
	adds r0, r5, #0
	subs r0, #0x11
	cmp r0, #1
	bhi _08036F24
	ldr r1, _08036F1C @ =0x03000590
	lsls r0, r4, #8
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0xc9
	strb r5, [r0]
	ldr r0, _08036F20 @ =0x03001800
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xca
	strb r0, [r1]
	adds r0, r2, #0
	bl sub_08036E54
	adds r1, r4, #0
	adds r1, #0xcb
	strb r0, [r1]
	lsrs r0, r7, #2
	b _08036F86
	.align 2, 0
_08036F1C: .4byte 0x03000590
_08036F20: .4byte 0x03001800
_08036F24:
	adds r0, r5, #0
	subs r0, #0x13
	cmp r0, #1
	bhi _08036F60
	ldr r1, _08036F58 @ =0x03000590
	lsls r0, r4, #8
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0xc9
	strb r5, [r0]
	ldr r0, _08036F5C @ =0x03001800
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xca
	strb r0, [r1]
	adds r0, r2, #0
	bl sub_08036E54
	adds r1, r4, #0
	adds r1, #0xcb
	strb r0, [r1]
	lsrs r0, r7, #1
	b _08036F86
	.align 2, 0
_08036F58: .4byte 0x03000590
_08036F5C: .4byte 0x03001800
_08036F60:
	ldr r1, _08036F98 @ =0x03000590
	lsls r0, r4, #8
	adds r4, r0, r1
	adds r0, r4, #0
	adds r0, #0xc9
	strb r5, [r0]
	ldr r0, _08036F9C @ =0x03001800
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xca
	strb r0, [r1]
	adds r0, r2, #0
	bl sub_08036E54
	adds r1, r4, #0
	adds r1, #0xcb
	strb r0, [r1]
	adds r0, r7, #0
_08036F86:
	bl sub_08036E54
	adds r1, r4, #0
	adds r1, #0xcc
	strb r0, [r1]
_08036F90:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036F98: .4byte 0x03000590
_08036F9C: .4byte 0x03001800
	.syntax divided
