	.syntax unified

	thumb_func_start sound_update_channel_output_routing
sound_update_channel_output_routing: @ 0x0807348C
	push {r4, lr}
	mov ip, r0
	mov r4, ip
	adds r4, #0x50
	ldrb r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08073516
	ldr r0, _080734B4 @ =0x03007014
	ldr r2, [r0]
	ldr r1, _080734B8 @ =0x0000072C
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080734BC
	movs r3, #3
	b _080734EE
	.align 2, 0
_080734B4: .4byte 0x03007014
_080734B8: .4byte 0x0000072C
_080734BC:
	mov r1, ip
	adds r1, #0x70
	ldrb r0, [r1]
	cmp r0, #0
	beq _080734CA
	adds r3, r0, #0
	b _080734EE
_080734CA:
	mov r0, ip
	adds r0, #0x63
	ldrb r0, [r0]
	cmp r0, #2
	bne _080734E8
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r2, [r0]
	mov r0, ip
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r0, [r2, #4]
	adds r0, r0, r1
	b _080734EC
_080734E8:
	mov r0, ip
	adds r0, #0x6f
_080734EC:
	ldrb r3, [r0]
_080734EE:
	ldr r1, _0807351C @ =0x083ABA72
	mov r0, ip
	adds r0, #0x64
	ldrb r0, [r0]
	adds r1, r0, r1
	ldrb r1, [r1]
	ldr r2, _08073520 @ =0x083ABA76
	lsls r0, r0, #2
	adds r0, r3, r0
	adds r0, r0, r2
	ldrb r3, [r0]
	ldr r2, _08073524 @ =0x04000081
	ldrb r0, [r2]
	ands r1, r0
	orrs r1, r3
	strb r1, [r2]
	ldrb r1, [r4]
	movs r0, #0xbf
	ands r0, r1
	strb r0, [r4]
_08073516:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807351C: .4byte 0x083ABA72
_08073520: .4byte 0x083ABA76
_08073524: .4byte 0x04000081
	.syntax divided
