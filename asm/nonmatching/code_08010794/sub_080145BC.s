	.syntax unified

	thumb_func_start sub_080145BC
sub_080145BC: @ 0x080145BC
	push {r4, r5, r6, r7, lr}
	bl update_all_battle_status_sprites
	bl iterate_bots_setup_battle_sprites
	movs r5, #0
	ldr r1, _08014624 @ =0x03000590
	ldr r0, _08014628 @ =0x03002C30
	movs r2, #0x40
	mov ip, r2
	movs r3, #0x8c
	lsls r3, r3, #5
	adds r2, r0, r3
	adds r4, r1, #0
	adds r4, #0xce
	adds r3, r1, #0
	adds r3, #0x40
	movs r6, #0x80
	lsls r6, r6, #1
_080145E2:
	ldrb r0, [r3]
	cmp r0, #0
	beq _08014602
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08014602
	ldrh r1, [r2]
	ldr r7, _0801462C @ =0x00008220
	adds r0, r7, #0
	orrs r0, r1
	strh r0, [r2]
	mov r0, ip
	strb r0, [r2, #9]
	strb r0, [r2, #8]
_08014602:
	adds r2, #0xc0
	adds r4, r4, r6
	adds r3, r3, r6
	adds r5, #1
	cmp r5, #5
	bls _080145E2
	movs r0, #0x37
	bl play_sound_effect
	ldr r1, _08014630 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014624: .4byte 0x03000590
_08014628: .4byte 0x03002C30
_0801462C: .4byte 0x00008220
_08014630: .4byte 0x0300137C
	.syntax divided
