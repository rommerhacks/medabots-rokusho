	.syntax unified

	thumb_func_start sub_08014050
sub_08014050: @ 0x08014050
	push {r4, lr}
	bl sub_080189EC
	ldr r0, _08014094 @ =0x03001800
	adds r0, #0x84
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r0, _08014098 @ =0x084C84E4
	ldr r1, _0801409C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080140A0 @ =0x084E2FD8
	ldr r1, _080140A4 @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	movs r0, #0x6e
	bl play_sound_effect
	ldr r0, _080140A8 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _080140AC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014094: .4byte 0x03001800
_08014098: .4byte 0x084C84E4
_0801409C: .4byte 0x06014800
_080140A0: .4byte 0x084E2FD8
_080140A4: .4byte 0x050003E0
_080140A8: .4byte 0x03000440
_080140AC: .4byte 0x0300137C
	.syntax divided
