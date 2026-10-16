	.syntax unified

	thumb_func_start sub_08021774
sub_08021774: @ 0x08021774
	push {lr}
	ldr r2, _080217B4 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x8a
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080217C0
	adds r0, r1, #0
	adds r0, #0x2b
	adds r1, r2, #0
	adds r1, #0x52
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080217C0
	ldr r0, _080217B8 @ =0x03002C30
	ldr r1, _080217BC @ =0x00000867
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080217CE
	.align 2, 0
_080217B4: .4byte 0x03001800
_080217B8: .4byte 0x03002C30
_080217BC: .4byte 0x00000867
_080217C0:
	movs r0, #0x3e
	bl play_sound_effect
	ldr r0, _080217D4 @ =0x03001800
	adds r0, #0xaa
	movs r1, #0x25
	strb r1, [r0]
_080217CE:
	pop {r0}
	bx r0
	.align 2, 0
_080217D4: .4byte 0x03001800
	.syntax divided
