	.syntax unified

	thumb_func_start sub_08030E78
sub_08030E78: @ 0x08030E78
	push {r4, lr}
	ldr r0, _08030EC0 @ =0x084C6A98
	ldr r1, _08030EC4 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r4, _08030EC8 @ =0x03001800
	adds r4, #0x87
	ldrb r0, [r4]
	bl increment_medal_skill_level
	ldrb r0, [r4]
	bl sub_0801B274
	ldr r0, _08030ECC @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x9c
	movs r0, #0
	strb r0, [r2]
	ldr r1, _08030ED0 @ =0x03000590
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _08030ED8
	movs r0, #2
	strb r0, [r2]
	movs r0, #4
	bl sound_stop_all_with_fade_guard
	movs r0, #0x6f
	bl play_sound_effect
	ldr r1, _08030ED4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08030F04
	.align 2, 0
_08030EC0: .4byte 0x084C6A98
_08030EC4: .4byte 0x06017400
_08030EC8: .4byte 0x03001800
_08030ECC: .4byte 0x03000440
_08030ED0: .4byte 0x03000590
_08030ED4: .4byte 0x0300137C
_08030ED8:
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08030F00
	movs r0, #1
	strb r0, [r2]
	movs r0, #4
	bl sound_stop_all_with_fade_guard
	movs r0, #0x6f
	bl play_sound_effect
	ldr r1, _08030EFC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08030F04
	.align 2, 0
_08030EFC: .4byte 0x0300137C
_08030F00:
	ldr r1, _08030F0C @ =0x0300137C
	movs r0, #0x48
_08030F04:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030F0C: .4byte 0x0300137C
	.syntax divided
