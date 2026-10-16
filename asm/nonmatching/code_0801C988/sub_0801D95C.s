	.syntax unified

	thumb_func_start sub_0801D95C
sub_0801D95C: @ 0x0801D95C
	push {r4, r5, r6, lr}
	ldr r5, _0801D9AC @ =0x03001800
	adds r6, r5, #0
	adds r6, #0xde
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, #0x59
	movs r1, #0x20
	rsbs r1, r1, #0
	movs r2, #0x10
	rsbs r2, r2, #0
	bl update_sprite_deceleration
	cmp r0, #0
	beq _0801D9B0
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, #0x59
	adds r1, #0x71
	bl check_sprite_overlap_and_adjust
	ldrb r1, [r6]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, #0x5a
	adds r2, r5, #0
	adds r2, #0xf8
	ldrb r3, [r2]
	movs r4, #1
	movs r2, #1
	ands r2, r3
	eors r2, r4
	bl update_battle_sprite_orbiting_positions
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801D9D6
	.align 2, 0
_0801D9AC: .4byte 0x03001800
_0801D9B0:
	ldrb r1, [r6]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, #0x5a
	adds r2, r5, #0
	adds r2, #0xf8
	ldrb r3, [r2]
	movs r4, #1
	movs r2, #1
	ands r2, r3
	eors r2, r4
	bl update_battle_sprite_orbiting_positions
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, #0x59
	adds r1, #0x71
	bl check_sprite_overlap_and_adjust
_0801D9D6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
