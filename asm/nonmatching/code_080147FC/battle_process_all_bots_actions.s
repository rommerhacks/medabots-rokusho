	.syntax unified

	thumb_func_start battle_process_all_bots_actions
	.global battle_process_all_bots_actions
battle_process_all_bots_actions: @ 0x0801528C
	push {r4, r5, lr}
	ldr r0, _080152C4 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _080152A0
	ldr r0, _080152C8 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	bne _080152D0
_080152A0:
	movs r4, #0
	ldr r0, _080152CC @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_080152A8:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080152B4
	adds r0, r4, #0
	bl battle_process_all_bot_actions
_080152B4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _080152A8
	b _08015312
	.align 2, 0
_080152C4: .4byte 0x03000440
_080152C8: .4byte 0x03000B90
_080152CC: .4byte 0x03000590
_080152D0:
	movs r4, #3
	ldr r0, _08015318 @ =0x03000590
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r5, r0, r1
_080152DA:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080152E6
	adds r0, r4, #0
	bl battle_process_all_bot_actions
_080152E6:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	bls _080152DA
	movs r4, #0
	ldr r0, _08015318 @ =0x03000590
	adds r5, r0, #0
	adds r5, #0x40
_080152FA:
	ldrb r0, [r5]
	cmp r0, #0
	beq _08015306
	adds r0, r4, #0
	bl battle_process_all_bot_actions
_08015306:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, #1
	cmp r4, #2
	bls _080152FA
_08015312:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08015318: .4byte 0x03000590
	.syntax divided
