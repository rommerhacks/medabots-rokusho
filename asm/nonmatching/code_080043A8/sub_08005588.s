	.syntax unified

	thumb_func_start sub_08005588
	.global sub_08005588
sub_08005588: @ 0x08005588
	push {r4, lr}
	movs r2, #0
	ldr r0, _080055D0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800559E
	ldr r0, _080055D4 @ =0x083AC484
	ldr r4, [r0]
	movs r2, #1
_0800559E:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080055AC
	ldr r0, _080055D4 @ =0x083AC484
	ldr r4, [r0, #4]
	movs r2, #1
_080055AC:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080055BA
	ldr r0, _080055D4 @ =0x083AC484
	ldr r4, [r0, #8]
	movs r2, #1
_080055BA:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080055C8
	ldr r0, _080055D4 @ =0x083AC484
	ldr r4, [r0, #0xc]
	movs r2, #1
_080055C8:
	cmp r2, #0
	bne _080055D8
	movs r0, #0
	b _0800561C
	.align 2, 0
_080055D0: .4byte 0x03001798
_080055D4: .4byte 0x083AC484
_080055D8:
	movs r0, #2
	bl play_sound_effect
	ldr r0, _08005624 @ =0x03000440
	adds r0, #0x51
	ldrb r1, [r0]
	adds r1, r4, r1
	ldrb r1, [r1]
	strb r1, [r0]
	movs r0, #0
	bl update_battle_sprite_orbit_clockwise
	movs r0, #1
	bl update_battle_sprite_orbit_clockwise
	movs r0, #2
	bl update_battle_sprite_orbit_clockwise
	movs r0, #3
	bl update_battle_sprite_orbit_clockwise
	bl sub_08005118
	bl sub_0800519C
	bl sub_0800522C
	bl sub_080053C8
	bl sub_08005000
	bl sub_08005948
	movs r0, #1
_0800561C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08005624: .4byte 0x03000440
	.syntax divided
