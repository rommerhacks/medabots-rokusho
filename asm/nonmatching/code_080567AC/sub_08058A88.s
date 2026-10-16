	.syntax unified

	thumb_func_start sub_08058A88
sub_08058A88: @ 0x08058A88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	movs r2, #0
	ldr r0, _08058AC0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08058AC8
	ldr r1, _08058AC4 @ =0x083D60DC
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrb r3, [r1]
	subs r3, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne _08058ABA
	subs r3, r5, #1
_08058ABA:
	strb r3, [r1]
	b _08058AF0
	.align 2, 0
_08058AC0: .4byte 0x03001798
_08058AC4: .4byte 0x083D60DC
_08058AC8:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08058AEC
	ldr r0, _08058B00 @ =0x083D60DC
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r3, [r0]
	adds r3, #1
	cmp r3, r5
	blt _08058AE8
	movs r3, #0
_08058AE8:
	strb r3, [r0]
	movs r2, #1
_08058AEC:
	cmp r2, #0
	beq _08058AF8
_08058AF0:
	cmp r4, #5
	bne _08058AF8
	bl init_battle_field_sprites
_08058AF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08058B00: .4byte 0x083D60DC
	.syntax divided
