	.syntax unified

	thumb_func_start sub_0800725C
	.global sub_0800725C
sub_0800725C: @ 0x0800725C
	push {r4, lr}
	ldr r1, _08007284 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #3
	bgt _0800728C
	cmp r0, #1
	blt _0800728C
	movs r2, #2
	ldr r3, _08007288 @ =0x03001841
_08007272:
	adds r1, r2, r3
	ldrb r0, [r1]
	cmp r0, #0
	bne _080072C4
	subs r2, #1
	cmp r2, #0
	bge _08007272
	b _080072E0
	.align 2, 0
_08007284: .4byte 0x03000440
_08007288: .4byte 0x03001841
_0800728C:
	adds r4, r1, #0
	adds r4, #0x52
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080072AA
	movs r0, #2
	bl play_sound_effect
	movs r0, #0
	strb r0, [r4]
	bl update_battle_icon_blink_and_orbit
	b _080072E0
_080072AA:
	bl sub_080440B4
	cmp r0, #0
	beq _080072D4
	movs r0, #5
	bl play_sound_effect
	ldr r1, _080072C0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080072DE
	.align 2, 0
_080072C0: .4byte 0x0300137C
_080072C4:
	movs r0, #0
	strb r0, [r1]
	bl sub_0800712C
	movs r0, #5
	bl play_sound_effect
	b _080072E0
_080072D4:
	movs r0, #6
	bl play_sound_effect
	ldr r1, _080072E8 @ =0x0300137C
	movs r0, #0xb
_080072DE:
	str r0, [r1]
_080072E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080072E8: .4byte 0x0300137C
	.syntax divided
