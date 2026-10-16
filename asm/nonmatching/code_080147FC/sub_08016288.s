	.syntax unified

	thumb_func_start sub_08016288
	.global sub_08016288
sub_08016288: @ 0x08016288
	push {r4, r5, lr}
	ldr r4, _080162AC @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x83
	ldrb r0, [r5]
	cmp r0, #0
	beq _080162D8
	subs r0, #1
	bl sub_08016138
	cmp r0, #0
	beq _08016302
	ldrb r0, [r5]
	cmp r0, #1
	bne _080162B4
	ldr r2, _080162B0 @ =0x083AD376
	b _080162B6
	.align 2, 0
_080162AC: .4byte 0x03001800
_080162B0: .4byte 0x083AD376
_080162B4:
	ldr r2, _080162D0 @ =0x083AD37C
_080162B6:
	adds r1, r4, #0
	adds r1, #0x81
	ldrb r0, [r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, _080162D4 @ =0x03001800
	adds r0, #0x83
	movs r1, #0
	strb r1, [r0]
	bl battle_load_sprite_data
	b _08016302
	.align 2, 0
_080162D0: .4byte 0x083AD37C
_080162D4: .4byte 0x03001800
_080162D8:
	ldr r4, _08016308 @ =0x03001798
	ldrb r1, [r4]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080162EE
	movs r0, #2
	bl play_sound_effect
	movs r0, #1
	strb r0, [r5]
_080162EE:
	ldrb r1, [r4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08016302
	movs r0, #2
	bl play_sound_effect
	movs r0, #2
	strb r0, [r5]
_08016302:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016308: .4byte 0x03001798
	.syntax divided
