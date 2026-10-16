	.syntax unified

	thumb_func_start sub_080080C8
sub_080080C8: @ 0x080080C8
	push {r4, lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _080080F4 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #8
	bl sub_08041C14
	bl sub_0800A8A0
	cmp r0, #0
	beq _080080FC
	bl sub_0803FB0C
	ldr r1, _080080F8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080081AC
	.align 2, 0
_080080F4: .4byte 0x03001780
_080080F8: .4byte 0x0300137C
_080080FC:
	bl sub_0800A1E4
	bl sub_0800A928
	cmp r0, #0
	beq _08008118
	bl sub_0803FB0C
	ldr r1, _08008114 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080081AC
	.align 2, 0
_08008114: .4byte 0x0300137C
_08008118:
	ldr r1, _08008134 @ =0x0300058C
	ldrb r3, [r1]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _0800813C
	movs r0, #5
	bl play_sound_effect
	ldr r1, _08008138 @ =0x0300137C
	movs r0, #0x1e
	b _080081AC
	.align 2, 0
_08008134: .4byte 0x0300058C
_08008138: .4byte 0x0300137C
_0800813C:
	ldrb r1, [r1, #1]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08008168
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08008160 @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08008164 @ =0x0300137C
	movs r0, #0x24
	b _080081AC
	.align 2, 0
_08008160: .4byte 0x03000440
_08008164: .4byte 0x0300137C
_08008168:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08008194
	movs r0, #2
	bl play_sound_effect
	ldr r2, _0800818C @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08008190 @ =0x0300137C
	movs r0, #0x24
	b _080081AC
	.align 2, 0
_0800818C: .4byte 0x03000440
_08008190: .4byte 0x0300137C
_08008194:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _080081AE
	movs r0, #4
	bl play_sound_effect
	ldr r0, _080081B4 @ =0x03000440
	adds r0, #0x43
	strb r4, [r0]
	ldr r1, _080081B8 @ =0x0300137C
	movs r0, #0x48
_080081AC:
	str r0, [r1]
_080081AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080081B4: .4byte 0x03000440
_080081B8: .4byte 0x0300137C
	.syntax divided
