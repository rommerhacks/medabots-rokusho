	.syntax unified

	thumb_func_start sub_08029FE0
sub_08029FE0: @ 0x08029FE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r5, #0
_08029FEE:
	ldr r1, _0802A0BC @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r2, r5, #1
	mov sl, r2
	cmp r0, #0
	beq _0802A094
	movs r6, #0
	mov sb, r6
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x60
	movs r7, #0xd0
	adds r7, r7, r4
	mov r8, r7
	lsls r1, r5, #1
	adds r0, r4, #0
	adds r0, #0xd6
	adds r1, r1, r0
	str r1, [sp, #4]
_0802A01A:
	ldrb r0, [r3]
	adds r0, r0, r5
	str r3, [sp]
	bl find_random_available_part_slot
	ldr r3, [sp]
	cmp r0, #0
	beq _0802A094
	subs r0, #1
	mov r1, r8
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, r0, r5
	ldrb r1, [r1]
	ldr r6, _0802A0C0 @ =0x030018EC
	movs r7, #0
	ldrsh r2, [r6, r7]
	str r3, [sp]
	bl battle_set_damage_display
	mov r1, r8
	ldrb r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r3, [sp]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r1, r0
	ldr r2, _0802A0C4 @ =0x03000590
	adds r1, r1, r2
	adds r1, #0x59
	ldr r6, _0802A0C8 @ =0x030018C8
	ldrb r0, [r6]
	ldrb r7, [r1]
	adds r0, r0, r7
	strb r0, [r1]
	ldrh r0, [r6]
	ldr r1, [sp, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r2, [sp, #4]
	strh r0, [r2]
	ldrb r0, [r3]
	adds r0, r0, r5
	str r3, [sp]
	bl sub_080351E8
	ldr r6, _0802A0CC @ =0x030018CA
	ldrh r0, [r6]
	ldr r3, [sp]
	cmp r0, #0
	beq _0802A094
	ldr r7, _0802A0C0 @ =0x030018EC
	strh r0, [r7]
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	bls _0802A01A
_0802A094:
	mov r5, sl
	cmp r5, #2
	bls _08029FEE
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	ldr r1, _0802A0BC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A0BC: .4byte 0x03001800
_0802A0C0: .4byte 0x030018EC
_0802A0C4: .4byte 0x03000590
_0802A0C8: .4byte 0x030018C8
_0802A0CC: .4byte 0x030018CA
_0802A0D0:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x3C, 0x20, 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30
	.byte 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
