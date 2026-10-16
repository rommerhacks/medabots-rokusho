	.syntax unified

	thumb_func_start sub_080421B4
	.global sub_080421B4
sub_080421B4: @ 0x080421B4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r1, #0
	ldr r5, _08042200 @ =0x030017A0
	ldr r6, _08042204 @ =0x03004C40
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #4
	mov ip, r0
	adds r3, r5, #0
_080421CE:
	lsls r2, r1, #3
	ldrb r0, [r3, #7]
	cmp r0, r7
	bne _08042208
	adds r1, r5, #3
	adds r1, r2, r1
	adds r1, r1, r4
	ldrb r2, [r1]
	ldrb r0, [r3, #1]
	adds r0, #0x78
	strb r0, [r1]
	movs r0, #2
	strb r0, [r3]
	lsls r2, r2, #1
	add r2, ip
	adds r1, r2, r6
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r2, #1
	adds r2, r2, r6
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	b _08042210
	.align 2, 0
_08042200: .4byte 0x030017A0
_08042204: .4byte 0x03004C40
_08042208:
	adds r3, #8
	adds r1, #1
	cmp r1, #8
	bls _080421CE
_08042210:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
