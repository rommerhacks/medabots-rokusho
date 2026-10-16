	.syntax unified

	thumb_func_start sub_0803D15C
sub_0803D15C: @ 0x0803D15C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r2, _0803D1C0 @ =0x083B5F80
	ldr r5, _0803D1C4 @ =0x03002C30
	ldr r0, _0803D1C8 @ =0x03000440
	ldr r1, _0803D1CC @ =0x0000012F
	adds r4, r0, r1
	ldrb r1, [r4]
	lsls r0, r1, #6
	adds r0, r0, r5
	adds r0, #0x2d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r1, r0, r5
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #6
	bhi _0803D1A0
	ldrb r0, [r1, #8]
	adds r0, #8
	strb r0, [r1, #8]
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r5
	ldrb r0, [r1, #9]
	adds r0, #8
	strb r0, [r1, #9]
_0803D1A0:
	ldrb r2, [r4]
	lsls r0, r2, #6
	adds r1, r0, r5
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, #0x3c
	bls _0803D1E0
	ldrb r0, [r1, #8]
	cmp r0, #8
	bne _0803D1D0
	adds r0, r2, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	b _0803D1E0
	.align 2, 0
_0803D1C0: .4byte 0x083B5F80
_0803D1C4: .4byte 0x03002C30
_0803D1C8: .4byte 0x03000440
_0803D1CC: .4byte 0x0000012F
_0803D1D0:
	subs r0, #4
	strb r0, [r1, #8]
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r5
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
_0803D1E0:
	ldr r1, _0803D214 @ =0x03002C30
	ldr r2, _0803D218 @ =0x03000440
	ldr r3, _0803D21C @ =0x0000012F
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r3, r0, r1
	adds r0, r3, #0
	adds r0, #0x23
	ldrb r0, [r0]
	adds r4, r1, #0
	cmp r0, #0
	bne _0803D220
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0803D238
	adds r1, r3, #0
	adds r1, #0x27
	ldrb r0, [r1]
	subs r0, #1
	b _0803D236
	.align 2, 0
_0803D214: .4byte 0x03002C30
_0803D218: .4byte 0x03000440
_0803D21C: .4byte 0x0000012F
_0803D220:
	adds r0, r3, #0
	adds r0, #0x2b
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0803D238
	adds r1, r3, #0
	adds r1, #0x27
	ldrb r0, [r1]
	adds r0, #1
_0803D236:
	strb r0, [r1]
_0803D238:
	ldr r6, _0803D2A0 @ =0x0000012F
	adds r5, r2, r6
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x26
	ldrb r1, [r0]
	adds r1, #4
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2b
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r1, r0, #0
	adds r1, #0x26
	ldrb r1, [r1]
	adds r0, #0x27
	ldrb r2, [r0]
	ldr r3, _0803D2A4 @ =0x00000282
	adds r0, r4, r3
	movs r6, #0
	ldrsh r3, [r0, r6]
	movs r6, #0xa1
	lsls r6, r6, #2
	adds r0, r4, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	str r0, [sp]
	add r0, sp, #4
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
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803D2A0: .4byte 0x0000012F
_0803D2A4: .4byte 0x00000282
	.syntax divided
