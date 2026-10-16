	.syntax unified

	thumb_func_start sub_0806F7AC
sub_0806F7AC: @ 0x0806F7AC
	push {r4, r5, lr}
	movs r1, #0x3c
	ldr r5, _0806F7E4 @ =0x03001800
	ldr r0, [r5, #8]
	cmp r1, r0
	bne _0806F7F8
	ldr r1, _0806F7E8 @ =0x04000050
	movs r0, #0xbf
	strh r0, [r1]
	ldr r4, _0806F7EC @ =0x04000054
	movs r0, #0x10
	strh r0, [r4]
	bl load_bg_screen_c
	ldr r2, _0806F7F0 @ =0x00007FFF
	movs r0, #4
	movs r1, #4
	bl setup_screen_transition_effect_080682CC
	movs r0, #0
	strh r0, [r4]
	ldr r1, _0806F7F4 @ =0x0300137C
	ldr r0, [r1]
	strh r0, [r5, #4]
	movs r0, #1
	str r0, [r1]
	b _0806F81C
	.align 2, 0
_0806F7E4: .4byte 0x03001800
_0806F7E8: .4byte 0x04000050
_0806F7EC: .4byte 0x04000054
_0806F7F0: .4byte 0x00007FFF
_0806F7F4: .4byte 0x0300137C
_0806F7F8:
	cmp r1, r0
	bge _0806F81C
	movs r0, #0
	str r0, [r5, #8]
	movs r0, #0x12
	strh r0, [r5, #4]
	movs r0, #4
	movs r1, #4
	movs r2, #0
	bl setup_screen_transition_effect_080684F0
	ldr r1, _0806F818 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
	b _0806F824
	.align 2, 0
_0806F818: .4byte 0x0300137C
_0806F81C:
	ldr r1, _0806F82C @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
_0806F824:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806F82C: .4byte 0x03001800
_0806F830:
	.byte 0x04, 0x49, 0x03, 0x20, 0x08, 0x60, 0x04, 0x49, 0x02, 0x20, 0x08, 0x60, 0x03, 0x49, 0x00, 0x20
	.byte 0x08, 0x60, 0x70, 0x47, 0x8C, 0x17, 0x00, 0x03, 0x8C, 0x2B, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
