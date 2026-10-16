	.syntax unified

	thumb_func_start sub_0806DAEC
sub_0806DAEC: @ 0x0806DAEC
	push {r4, r5, lr}
	ldr r5, _0806DB1C @ =0x03001800
	ldr r0, [r5, #8]
	cmp r0, #0x28
	ble _0806DB24
	movs r4, #0
	str r4, [r5, #8]
	movs r0, #2
	bl sub_0806B584
	movs r0, #4
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080684F0
	movs r1, #2
	strh r1, [r5]
	movs r0, #3
	strh r0, [r5, #2]
	strh r4, [r5, #4]
	ldr r0, _0806DB20 @ =0x0300137C
	str r1, [r0]
	b _0806DB28
	.align 2, 0
_0806DB1C: .4byte 0x03001800
_0806DB20: .4byte 0x0300137C
_0806DB24:
	adds r0, #1
	str r0, [r5, #8]
_0806DB28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
