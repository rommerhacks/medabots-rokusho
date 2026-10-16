	.syntax unified

	thumb_func_start handle_battle_fade_transition
handle_battle_fade_transition: @ 0x08065B04
	push {r4, lr}
	ldr r2, _08065B1C @ =0x03000B90
	ldrb r0, [r2]
	cmp r0, #1
	bls _08065B24
	bl sub_0803FB0C
	ldr r0, _08065B20 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #8]
	b _08065B52
	.align 2, 0
_08065B1C: .4byte 0x03000B90
_08065B20: .4byte 0x03006F74
_08065B24:
	ldr r0, _08065B40 @ =0x03005010
	movs r4, #1
	adds r1, r4, #0
	ldrb r2, [r2]
	lsls r1, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065B48
	ldr r1, _08065B44 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08065B58
	.align 2, 0
_08065B40: .4byte 0x03005010
_08065B44: .4byte 0x0300137C
_08065B48:
	bl sub_0803FB0C
	ldr r0, _08065B60 @ =0x03006F74
	ldr r0, [r0]
	str r4, [r0, #8]
_08065B52:
	ldr r1, _08065B64 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #2
_08065B58:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08065B60: .4byte 0x03006F74
_08065B64: .4byte 0x0300137C
	.syntax divided
