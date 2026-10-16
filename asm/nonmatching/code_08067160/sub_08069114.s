	.syntax unified

	thumb_func_start sub_08069114
sub_08069114: @ 0x08069114
	push {lr}
	bl sub_0806A230
	cmp r0, #0
	beq _08069142
	ldr r1, _08069148 @ =0x04000054
	movs r0, #0
	strh r0, [r1]
	subs r1, #4
	movs r0, #0xff
	strh r0, [r1]
	ldr r1, _0806914C @ =0x03006F88
	movs r0, #0
	str r0, [r1]
	movs r0, #0x20
	bl sound_stop_all_with_fade_guard
	ldr r1, _08069150 @ =0x03006F80
	movs r0, #0xc
	str r0, [r1]
	ldr r1, _08069154 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08069142:
	pop {r0}
	bx r0
	.align 2, 0
_08069148: .4byte 0x04000054
_0806914C: .4byte 0x03006F88
_08069150: .4byte 0x03006F80
_08069154: .4byte 0x0300137C
	.syntax divided
