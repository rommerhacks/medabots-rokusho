	.syntax unified

	thumb_func_start sub_08028078
sub_08028078: @ 0x08028078
	push {lr}
	ldr r2, _080280B0 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080280BC
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0x5a
	bne _080280BC
	ldr r0, _080280B4 @ =0x03002C30
	ldr r1, _080280B8 @ =0x00000867
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _080280CA
	.align 2, 0
_080280B0: .4byte 0x03001800
_080280B4: .4byte 0x03002C30
_080280B8: .4byte 0x00000867
_080280BC:
	movs r0, #0x3e
	bl play_sound_effect
	ldr r1, _080280D0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #2
_080280CA:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080280D0: .4byte 0x03001800
	.syntax divided
