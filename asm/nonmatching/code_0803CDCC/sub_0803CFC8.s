	.syntax unified

	thumb_func_start sub_0803CFC8
sub_0803CFC8: @ 0x0803CFC8
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, _0803CFEC @ =0x03002C30
	ldr r0, _0803CFF0 @ =0x03000440
	ldr r1, _0803CFF4 @ =0x0000012F
	adds r3, r0, r1
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r2, r0, r4
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803CFF8
	subs r0, #1
	strb r0, [r1]
	b _0803D01A
	.align 2, 0
_0803CFEC: .4byte 0x03002C30
_0803CFF0: .4byte 0x03000440
_0803CFF4: .4byte 0x0000012F
_0803CFF8:
	ldrh r1, [r2]
	movs r5, #0x80
	lsls r5, r5, #8
	adds r0, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0803D038 @ =0x083B5F80
	ldrb r1, [r3]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
_0803D01A:
	ldr r4, _0803D03C @ =0x03002C30
	ldr r0, _0803D040 @ =0x03000440
	ldr r1, _0803D044 @ =0x0000012F
	adds r5, r0, r1
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r1, r0, r4
	adds r2, r1, #0
	adds r2, #0x2b
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803D048
	subs r0, #1
	strb r0, [r2]
	b _0803D0B2
	.align 2, 0
_0803D038: .4byte 0x083B5F80
_0803D03C: .4byte 0x03002C30
_0803D040: .4byte 0x03000440
_0803D044: .4byte 0x0000012F
_0803D048:
	adds r0, r1, #0
	adds r0, #0x26
	ldrb r1, [r0]
	ldr r2, _0803D09C @ =0x00000282
	adds r0, r4, r2
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp]
	add r0, sp, #4
	movs r2, #0x10
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #4]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	strh r1, [r0, #2]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	asrs r1, r1, #0x10
	strh r1, [r0, #4]
	ldr r0, _0803D0A0 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0803D0A4
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x26
	ldrb r1, [r0]
	adds r1, #0x10
	b _0803D0B0
	.align 2, 0
_0803D09C: .4byte 0x00000282
_0803D0A0: .4byte 0x03001800
_0803D0A4:
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x26
	ldrb r1, [r0]
	subs r1, #0x10
_0803D0B0:
	strb r1, [r0]
_0803D0B2:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
