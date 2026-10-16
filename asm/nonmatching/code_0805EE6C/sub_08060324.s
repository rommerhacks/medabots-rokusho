	.syntax unified

	thumb_func_start sub_08060324
sub_08060324: @ 0x08060324
	push {lr}
	bl sub_080600E0
	ldr r0, _08060350 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0806034C
	movs r0, #4
	bl play_sound_effect
	ldr r0, _08060354 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08060358 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806034C:
	pop {r0}
	bx r0
	.align 2, 0
_08060350: .4byte 0x0300058C
_08060354: .4byte 0x03006F74
_08060358: .4byte 0x0300137C
	.syntax divided
