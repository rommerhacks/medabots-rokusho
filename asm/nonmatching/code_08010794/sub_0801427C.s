	.syntax unified

	thumb_func_start sub_0801427C
sub_0801427C: @ 0x0801427C
	push {r4, lr}
	ldr r0, _080142A4 @ =0x03001800
	adds r4, r0, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #0
	bne _08014292
	bl sub_08018C38
	bl sub_08018C78
_08014292:
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080142AC
	ldr r1, _080142A8 @ =0x0300137C
	movs r0, #0x60
	b _08014306
	.align 2, 0
_080142A4: .4byte 0x03001800
_080142A8: .4byte 0x0300137C
_080142AC:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080142C0
	ldr r1, _080142BC @ =0x0300137C
	movs r0, #0x68
	b _08014306
	.align 2, 0
_080142BC: .4byte 0x0300137C
_080142C0:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080142D4
	ldr r1, _080142D0 @ =0x0300137C
	movs r0, #0x70
	b _08014306
	.align 2, 0
_080142D0: .4byte 0x0300137C
_080142D4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080142E8
	ldr r1, _080142E4 @ =0x0300137C
	movs r0, #0x78
	b _08014306
	.align 2, 0
_080142E4: .4byte 0x0300137C
_080142E8:
	bl sub_0801902C
	bl update_all_battle_status_sprites
	bl init_battle_bot_sprites
	bl sub_08019EF0
	cmp r0, #0
	beq _08014308
	bl sub_08019078
	ldr r1, _08014310 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08014306:
	str r0, [r1]
_08014308:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014310: .4byte 0x0300137C
	.syntax divided
