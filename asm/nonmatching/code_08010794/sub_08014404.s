	.syntax unified

	thumb_func_start sub_08014404
sub_08014404: @ 0x08014404
	push {r4, r5, lr}
	bl update_all_battle_status_sprites
	bl sub_08019078
	ldr r5, _08014468 @ =0x03000590
	ldr r0, _0801446C @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x87
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r2, #4
	eors r1, r2
	strb r1, [r0]
	ldrb r0, [r4]
	ldr r1, _08014470 @ =0x03002C30
	lsls r2, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r2, r2, r3
	adds r2, r2, r1
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r2, #4
	bl setup_bot_battle_sprites_08015A00
	bl sub_0801A678
	ldrb r0, [r4]
	bl battle_process_all_bot_actions
	ldrb r0, [r4]
	cmp r0, #2
	bls _0801449C
	ldr r0, _08014474 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801447C
	ldrb r0, [r4]
	bl process_bot_battle_turn
	ldr r1, _08014478 @ =0x0300137C
	movs r0, #0x45
	b _08014538
	.align 2, 0
_08014468: .4byte 0x03000590
_0801446C: .4byte 0x03001800
_08014470: .4byte 0x03002C30
_08014474: .4byte 0x03000440
_08014478: .4byte 0x0300137C
_0801447C:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r5
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2c
	bne _08014490
	adds r0, r1, #0
	bl process_bot_battle_turn
_08014490:
	ldr r1, _08014498 @ =0x0300137C
	movs r0, #0xa0
	b _08014538
	.align 2, 0
_08014498: .4byte 0x0300137C
_0801449C:
	ldrb r1, [r4]
	lsls r0, r1, #8
	adds r0, r0, r5
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2c
	bne _080144DC
	adds r0, r1, #0
	bl process_bot_battle_turn
	ldrb r0, [r4]
	bl sub_08018900
	ldr r0, _080144C8 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _080144D0
	ldr r1, _080144CC @ =0x0300137C
	movs r0, #0x45
	b _08014538
	.align 2, 0
_080144C8: .4byte 0x03000440
_080144CC: .4byte 0x0300137C
_080144D0:
	ldr r1, _080144D8 @ =0x0300137C
	movs r0, #0xa0
	b _08014538
	.align 2, 0
_080144D8: .4byte 0x0300137C
_080144DC:
	adds r0, r1, #0
	bl sub_0801A6EC
	cmp r0, #0
	beq _08014512
	ldr r0, _08014504 @ =0x03002B64
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801450C
	ldrb r0, [r4]
	bl process_bot_battle_turn
	ldrb r0, [r4]
	bl sub_08018900
	ldr r1, _08014508 @ =0x0300137C
	movs r0, #0x45
	b _08014538
	.align 2, 0
_08014504: .4byte 0x03002B64
_08014508: .4byte 0x0300137C
_0801450C:
	ldrb r0, [r4]
	bl sub_0801A744
_08014512:
	ldr r3, _08014540 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r2, [r0]
	subs r0, #7
	movs r1, #0
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #2
	strb r1, [r0]
	bl iterate_bots_setup_battle_sprites
	ldr r1, _08014544 @ =0x0300137C
	movs r0, #4
_08014538:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014540: .4byte 0x03001800
_08014544: .4byte 0x0300137C
	.syntax divided
