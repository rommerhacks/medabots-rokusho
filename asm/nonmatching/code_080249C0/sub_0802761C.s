	.syntax unified

	thumb_func_start sub_0802761C
sub_0802761C: @ 0x0802761C
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r6, _08027644 @ =0x03000590
	ldr r5, _08027648 @ =0x03001860
_08027624:
	ldrb r1, [r5]
	adds r2, r1, r4
	lsls r0, r2, #8
	adds r0, r0, r6
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027672
	cmp r4, #1
	beq _08027658
	cmp r4, #1
	blo _0802764C
	cmp r4, #2
	beq _08027668
	b _08027672
	.align 2, 0
_08027644: .4byte 0x03000590
_08027648: .4byte 0x03001860
_0802764C:
	ldr r0, _08027654 @ =0x030004DE
	adds r1, r2, #0
	b _0802765C
	.align 2, 0
_08027654: .4byte 0x030004DE
_08027658:
	adds r1, #1
	ldr r0, _08027664 @ =0x030004F2
_0802765C:
	movs r2, #0x21
	bl update_battle_sprite_animations
	b _08027672
	.align 2, 0
_08027664: .4byte 0x030004F2
_08027668:
	adds r1, #2
	ldr r0, _080276D8 @ =0x03000506
	movs r2, #0x21
	bl update_battle_sprite_animations
_08027672:
	adds r4, #1
	cmp r4, #2
	bls _08027624
	ldr r0, _080276DC @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x84
	ldrb r1, [r3]
	adds r2, r1, #1
	strb r2, [r3]
	adds r1, r0, #0
	adds r1, #0x89
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	bne _080276A8
	ldr r0, _080276E0 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080276A8
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x32
	bls _080276A8
	movs r0, #0x78
	strb r0, [r3]
_080276A8:
	adds r0, r4, #0
	adds r0, #0x84
	ldrb r0, [r0]
	cmp r0, #0x78
	bne _080276D2
	ldr r4, _080276E4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	movs r1, #0x84
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	movs r1, #0xc
	bl clear_battle_sprite_slot
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080276D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080276D8: .4byte 0x03000506
_080276DC: .4byte 0x03000440
_080276E0: .4byte 0x03001798
_080276E4: .4byte 0x03001800
	.syntax divided
