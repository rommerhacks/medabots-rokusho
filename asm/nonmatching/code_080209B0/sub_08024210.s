	.syntax unified

	thumb_func_start sub_08024210
sub_08024210: @ 0x08024210
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, _080242E4 @ =0x03002C30
	ldr r1, _080242E8 @ =0x00000863
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	ldr r2, _080242EC @ =0x03001800
	mov r8, r2
	mov r5, r8
	adds r5, #0x88
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r2, #0xb4
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r0, r1
	movs r2, #0x88
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r2, #0xb6
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r0, r1
	movs r2, #0x8c
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r0, r1
	movs r2, #0x90
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r4, r2
	adds r0, r0, r1
	movs r2, #0x94
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	movs r0, #0x22
	movs r1, #4
	bl clear_sprite_table_mask
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	ldr r1, _080242F0 @ =0x000016A3
	adds r0, r0, r1
	strb r6, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	ldr r2, _080242F4 @ =0x000016E3
	adds r0, r0, r2
	strb r6, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r1, #0x80
	adds r0, r0, r1
	strb r6, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r2, #0x80
	adds r0, r0, r2
	strb r6, [r0]
	ldrb r0, [r5]
	adds r0, #0x72
	bl sub_08035694
	movs r0, #0x34
	bl play_sound_effect
	movs r0, #0xaa
	add r8, r0
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080242E4: .4byte 0x03002C30
_080242E8: .4byte 0x00000863
_080242EC: .4byte 0x03001800
_080242F0: .4byte 0x000016A3
_080242F4: .4byte 0x000016E3
	.syntax divided
