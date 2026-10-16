	.syntax unified

	thumb_func_start sub_0801B894
	.global sub_0801B894
sub_0801B894: @ 0x0801B894
	push {r4, r5, r6, lr}
	movs r0, #9
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r2, _0801B9A8 @ =0x03001800
	movs r0, #0x82
	adds r0, r0, r2
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801B9A0
	mov r1, ip
	ldrb r0, [r1]
	subs r1, r0, #1
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801B9A0
	ldr r6, _0801B9AC @ =0x03000590
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r4, r0, #3
	adds r5, r2, #0
	adds r5, #0x80
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r4, r0
	adds r0, r0, r6
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801B9A0
	ldr r2, _0801B9B0 @ =0x03002C30
	movs r0, #0x90
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _0801B9B4 @ =0x0000C404
	strh r0, [r1]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r3, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r4, r0
	adds r0, r0, r6
	adds r0, #0x56
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r4, #0xb2
	lsls r4, r4, #5
	adds r0, r0, r4
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	movs r4, #0x91
	lsls r4, r4, #2
	adds r1, r2, r4
	strh r0, [r1]
	mov r0, ip
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r6
	adds r0, #0x56
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	subs r4, #2
	adds r0, r2, r4
	strh r1, [r0]
	ldr r0, _0801B9B8 @ =0x0000024A
	adds r1, r2, r0
	movs r0, #6
	strb r0, [r1]
	adds r4, #9
	adds r1, r2, r4
	movs r0, #0xf0
	strb r0, [r1]
	mov r0, ip
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r6
	adds r0, #0x57
	ldrb r1, [r0]
	adds r4, #0x19
	adds r0, r2, r4
	strb r1, [r0]
	mov r0, ip
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r6
	adds r0, #0x56
	ldrb r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	ldr r1, _0801B9BC @ =0x00000266
	adds r0, r2, r1
	strb r3, [r0]
	adds r4, #2
	adds r2, r2, r4
	strb r3, [r2]
	ldr r0, _0801B9C0 @ =0x083B5F80
	ldr r0, [r0, #0x60]
	movs r1, #9
	bl init_battle_sprite_entry_08040B90
_0801B9A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801B9A8: .4byte 0x03001800
_0801B9AC: .4byte 0x03000590
_0801B9B0: .4byte 0x03002C30
_0801B9B4: .4byte 0x0000C404
_0801B9B8: .4byte 0x0000024A
_0801B9BC: .4byte 0x00000266
_0801B9C0: .4byte 0x083B5F80
	.syntax divided
