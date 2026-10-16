	.syntax unified

	thumb_func_start sub_08007C4C
sub_08007C4C: @ 0x08007C4C
	push {r4, lr}
	bl sub_080093F8
	bl sub_0800A180
	bl sub_0800A1E4
	bl sub_0800A2B4
	ldr r1, _08007C7C @ =0x0300058C
	ldrb r3, [r1]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _08007C84
	movs r0, #5
	bl play_sound_effect
	ldr r1, _08007C80 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08007CF4
	.align 2, 0
_08007C7C: .4byte 0x0300058C
_08007C80: .4byte 0x0300137C
_08007C84:
	ldrb r1, [r1, #1]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08007CB0
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08007CA8 @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08007CAC @ =0x0300137C
	movs r0, #0x14
	b _08007CF4
	.align 2, 0
_08007CA8: .4byte 0x03000440
_08007CAC: .4byte 0x0300137C
_08007CB0:
	movs r4, #1
	ands r4, r1
	cmp r4, #0
	beq _08007CDC
	movs r0, #2
	bl play_sound_effect
	ldr r2, _08007CD4 @ =0x03000440
	adds r2, #0x42
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08007CD8 @ =0x0300137C
	movs r0, #0x14
	b _08007CF4
	.align 2, 0
_08007CD4: .4byte 0x03000440
_08007CD8: .4byte 0x0300137C
_08007CDC:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _08007CF6
	movs r0, #4
	bl play_sound_effect
	ldr r0, _08007CFC @ =0x03000440
	adds r0, #0x43
	strb r4, [r0]
	ldr r1, _08007D00 @ =0x0300137C
	movs r0, #0x48
_08007CF4:
	str r0, [r1]
_08007CF6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08007CFC: .4byte 0x03000440
_08007D00: .4byte 0x0300137C
	.syntax divided
