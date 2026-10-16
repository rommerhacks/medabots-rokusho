	.syntax unified

	thumb_func_start init_scene_graphics
init_scene_graphics: @ 0x0806ED1C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x58
	ldr r0, _0806EEBC @ =0x087BE494
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UnCompVram
	ldr r0, _0806EEC0 @ =0x087C88F4
	ldr r1, _0806EEC4 @ =0x06008020
	bl LZ77UnCompVram
	ldr r0, _0806EEC8 @ =0x087C8BD8
	ldr r1, _0806EECC @ =0x06008C80
	bl LZ77UnCompVram
	ldr r0, _0806EED0 @ =0x087C8C94
	ldr r1, _0806EED4 @ =0x06009900
	bl LZ77UnCompVram
	ldr r0, _0806EED8 @ =0x087C8CE4
	ldr r1, _0806EEDC @ =0x06009A40
	bl LZ77UnCompVram
	ldr r4, _0806EEE0 @ =0x040000D4
	ldr r0, _0806EEE4 @ =0x087C09C0
	str r0, [r4]
	movs r2, #0xa0
	lsls r2, r2, #0x13
	str r2, [r4, #4]
	ldr r0, _0806EEE8 @ =0x84000080
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806EEEC @ =0x087C8CF4
	str r0, [r4]
	ldr r0, _0806EEF0 @ =0x05000100
	str r0, [r4, #4]
	ldr r1, _0806EEF4 @ =0x84000008
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806EEF8 @ =0x087C8D14
	str r0, [r4]
	ldr r0, _0806EEFC @ =0x05000120
	str r0, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806EF00 @ =0x087C8D34
	str r0, [r4]
	str r2, [r4, #4]
	str r1, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806EF04 @ =0x087C0BC0
	ldr r1, _0806EF08 @ =0x06007000
	bl LZ77UnCompVram
	ldr r0, _0806EF0C @ =0x087C0E0C
	ldr r1, _0806EF10 @ =0x06007800
	bl LZ77UnCompVram
	movs r0, #0
	mov r8, r0
	str r0, [sp, #0x54]
	add r0, sp, #0x54
	str r0, [r4]
	ldr r0, _0806EF14 @ =0x0600F800
	str r0, [r4, #4]
	ldr r0, _0806EF18 @ =0x85000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _0806EF1C @ =0x0400000A
	ldr r2, _0806EF20 @ =0x00001F09
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0806EF24 @ =0x00000E02
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0806EF28 @ =0x00000F03
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #4
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r6, #0xc8
	lsls r6, r6, #8
	ldr r2, _0806EF2C @ =0x00000404
	movs r5, #3
	str r5, [sp]
	movs r0, #9
	adds r1, r6, #0
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	ldr r4, _0806EF30 @ =0x03002C30
	ldr r3, _0806EF34 @ =0x00000242
	adds r1, r4, r3
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x91
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xa0
	strh r0, [r1]
	ldr r2, _0806EF38 @ =0x00000405
	str r5, [sp]
	movs r0, #0xa
	adds r1, r6, #0
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806EF3C @ =0x00000282
	adds r0, r4, r1
	mov r2, r8
	strh r2, [r0]
	movs r3, #0xa1
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0x90
	strh r0, [r1]
	movs r5, #0
	ldr r0, _0806EF40 @ =0x000002C2
	adds r4, r4, r0
_0806EE18:
	adds r0, r5, #0
	adds r0, #0xb
	movs r1, #0x80
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r1, #3
	str r1, [sp]
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	movs r0, #0xc0
	strh r0, [r4]
	movs r0, #0xc8
	strh r0, [r4, #2]
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	ble _0806EE18
	movs r5, #0
	ldr r0, _0806EF30 @ =0x03002C30
	adds r4, r0, #0
	adds r4, #0xc2
	movs r6, #0xa0
_0806EE4A:
	adds r0, r5, #3
	movs r1, #3
	str r1, [sp]
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x81
	lsls r2, r2, #3
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	strh r6, [r4]
	movs r0, #0xc8
	strh r0, [r4, #2]
	movs r0, #0x20
	strb r0, [r4, #9]
	adds r4, #0x40
	adds r6, #8
	adds r5, #1
	cmp r5, #5
	ble _0806EE4A
	bl sub_0806FF50
	bl sub_0806FF90
	bl sub_08070030
	bl sub_0806FFF8
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xf0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806EF44 @ =0x04000050
	ldr r2, _0806EF48 @ =0x00001844
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0806EF4C @ =0x0000080B
	adds r0, r3, #0
	strh r0, [r1]
	ldr r1, _0806EF50 @ =0x03001800
	ldrh r0, [r1, #0xc]
	strh r0, [r1, #4]
	ldr r1, _0806EF54 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	add sp, #0x58
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806EEBC: .4byte 0x087BE494
_0806EEC0: .4byte 0x087C88F4
_0806EEC4: .4byte 0x06008020
_0806EEC8: .4byte 0x087C8BD8
_0806EECC: .4byte 0x06008C80
_0806EED0: .4byte 0x087C8C94
_0806EED4: .4byte 0x06009900
_0806EED8: .4byte 0x087C8CE4
_0806EEDC: .4byte 0x06009A40
_0806EEE0: .4byte 0x040000D4
_0806EEE4: .4byte 0x087C09C0
_0806EEE8: .4byte 0x84000080
_0806EEEC: .4byte 0x087C8CF4
_0806EEF0: .4byte 0x05000100
_0806EEF4: .4byte 0x84000008
_0806EEF8: .4byte 0x087C8D14
_0806EEFC: .4byte 0x05000120
_0806EF00: .4byte 0x087C8D34
_0806EF04: .4byte 0x087C0BC0
_0806EF08: .4byte 0x06007000
_0806EF0C: .4byte 0x087C0E0C
_0806EF10: .4byte 0x06007800
_0806EF14: .4byte 0x0600F800
_0806EF18: .4byte 0x85000200
_0806EF1C: .4byte 0x0400000A
_0806EF20: .4byte 0x00001F09
_0806EF24: .4byte 0x00000E02
_0806EF28: .4byte 0x00000F03
_0806EF2C: .4byte 0x00000404
_0806EF30: .4byte 0x03002C30
_0806EF34: .4byte 0x00000242
_0806EF38: .4byte 0x00000405
_0806EF3C: .4byte 0x00000282
_0806EF40: .4byte 0x000002C2
_0806EF44: .4byte 0x04000050
_0806EF48: .4byte 0x00001844
_0806EF4C: .4byte 0x0000080B
_0806EF50: .4byte 0x03001800
_0806EF54: .4byte 0x0300137C
	.syntax divided
