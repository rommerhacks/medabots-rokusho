	.syntax unified

	thumb_func_start sub_0803858C
sub_0803858C: @ 0x0803858C
	push {r4, lr}
	ldr r2, _080385C0 @ =0x03002C30
	ldr r0, _080385C4 @ =0x03000440
	ldr r1, _080385C8 @ =0x0000012F
	adds r4, r0, r1
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrh r0, [r1, #0x18]
	adds r0, #0x10
	ldr r3, _080385CC @ =0x000003FF
	adds r2, r3, #0
	ands r0, r2
	strh r0, [r1, #0x18]
	ldrb r0, [r4]
	bl move_sprite_toward_target
	cmp r0, #0
	beq _080385BA
	ldrb r0, [r4]
	movs r1, #1
	bl clear_battle_sprite_slot
_080385BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080385C0: .4byte 0x03002C30
_080385C4: .4byte 0x03000440
_080385C8: .4byte 0x0000012F
_080385CC: .4byte 0x000003FF
	.syntax divided
