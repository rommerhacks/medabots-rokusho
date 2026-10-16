	.syntax unified

	thumb_func_start update_battle_sprite_animation
update_battle_sprite_animation: @ 0x08060438
	push {r4, r5, r6, r7, lr}
	ldr r4, _080604A0 @ =0x03006F74
	ldr r0, [r4]
	ldrb r7, [r0, #0x18]
	ldr r6, _080604A4 @ =0x03002C30
	ldrh r0, [r6, #0x1a]
	adds r0, #1
	strh r0, [r6, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x60
	bls _08060454
	movs r0, #0
	strh r0, [r6, #0x1a]
_08060454:
	ldr r5, _080604A8 @ =0x08483DC0
	ldr r4, [r4]
	ldrb r0, [r4, #0x17]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r3, _080604AC @ =0x08483DD4
	ldrh r2, [r6, #0x1a]
	lsrs r2, r2, #3
	movs r0, #3
	ands r2, r0
	lsls r2, r2, #1
	lsls r0, r7, #3
	adds r2, r2, r0
	adds r3, r2, r3
	lsls r1, r1, #3
	ldrh r3, [r3]
	adds r1, r1, r3
	strh r1, [r6, #2]
	ldrb r0, [r4, #0x17]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r0, _080604B0 @ =0x08483DE4
	adds r0, r2, r0
	lsls r1, r1, #3
	ldrh r0, [r0]
	adds r1, r1, r0
	strh r1, [r6, #4]
	ldr r0, _080604B4 @ =0x08483DF4
	adds r2, r2, r0
	ldrh r0, [r2]
	strh r0, [r6, #6]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080604A0: .4byte 0x03006F74
_080604A4: .4byte 0x03002C30
_080604A8: .4byte 0x08483DC0
_080604AC: .4byte 0x08483DD4
_080604B0: .4byte 0x08483DE4
_080604B4: .4byte 0x08483DF4
	.syntax divided
