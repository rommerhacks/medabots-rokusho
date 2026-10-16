	.syntax unified

	thumb_func_start battle_sprite_set_action
	.global battle_sprite_set_action
battle_sprite_set_action: @ 0x08070644
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	ldr r2, _08070688 @ =0x03002C30
	lsrs r1, r1, #0x12
	adds r4, r1, r2
	adds r1, r4, #0
	adds r1, #0x20
	movs r6, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x21
	strb r6, [r0]
	cmp r5, #0
	beq _0807067A
	movs r0, #0
	bl rng_next_080012F0
	movs r1, #3
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x22
	strb r0, [r1]
	subs r0, r5, #4
	adds r1, #1
	strb r0, [r1]
_0807067A:
	ldrh r0, [r4, #6]
	strh r0, [r4, #0x30]
	strh r6, [r4, #0x1a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08070688: .4byte 0x03002C30
	.syntax divided
