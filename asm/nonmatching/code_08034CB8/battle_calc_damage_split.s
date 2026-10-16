	.syntax unified

	thumb_func_start battle_calc_damage_split
	.global battle_calc_damage_split
battle_calc_damage_split: @ 0x08036CCC
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08036D00 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r0, r2, #0
	adds r0, #0x4c
	ldrb r1, [r0]
	adds r2, #0x59
	ldrb r0, [r2]
	subs r1, r1, r0
	cmp r1, r4
	ble _08036D08
	ldr r2, _08036D04 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	movs r1, #0
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	b _08036D16
	.align 2, 0
_08036D00: .4byte 0x03000590
_08036D04: .4byte 0x03001800
_08036D08:
	ldr r3, _08036D20 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	subs r1, r4, r1
_08036D16:
	subs r0, #2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08036D20: .4byte 0x03001800
	.syntax divided
