	.syntax unified

	thumb_func_start sub_08016080
sub_08016080: @ 0x08016080
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _080160DC @ =0x03002C30
	lsls r0, r6, #6
	adds r4, r0, r1
	ldr r0, _080160E0 @ =0x0000C604
	strh r0, [r4]
	ldr r0, _080160E4 @ =0x03001800
	adds r0, #0x81
	ldrb r0, [r0]
	subs r5, r6, r0
	cmp r5, #5
	bls _080160A8
	adds r5, #6
_080160A8:
	ldr r0, _080160E8 @ =0x083AD370
	adds r0, r5, r0
	ldrb r1, [r0]
	movs r0, #0x80
	str r0, [sp]
	movs r7, #8
	str r7, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0x18
	movs r3, #0x78
	bl compute_polar_to_screen_position
	ldr r0, [sp, #0xc]
	strh r0, [r4, #2]
	asrs r0, r0, #0x10
	strh r0, [r4, #4]
	ldr r2, _080160EC @ =0x0000060C
	adds r1, r6, r2
	strh r1, [r4, #6]
	cmp r0, #0x87
	ble _080160F0
	strb r7, [r4, #0xa]
	b _080160FC
	.align 2, 0
_080160DC: .4byte 0x03002C30
_080160E0: .4byte 0x0000C604
_080160E4: .4byte 0x03001800
_080160E8: .4byte 0x083AD370
_080160EC: .4byte 0x0000060C
_080160F0:
	cmp r0, #0x77
	ble _080160F8
	movs r0, #9
	b _080160FA
_080160F8:
	movs r0, #0xa
_080160FA:
	strb r0, [r4, #0xa]
_080160FC:
	ldr r1, _08016130 @ =0x03002C30
	lsls r0, r6, #6
	adds r3, r0, r1
	movs r2, #0
	strb r2, [r3, #0x1c]
	movs r0, #1
	strb r0, [r3, #9]
	strb r0, [r3, #8]
	ldrb r0, [r3, #4]
	subs r0, #0x70
	strb r0, [r3, #0xb]
	ldr r0, _08016134 @ =0x083AD370
	adds r0, r5, r0
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x20
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016130: .4byte 0x03002C30
_08016134: .4byte 0x083AD370
	.syntax divided
