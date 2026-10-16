	.syntax unified

	thumb_func_start sub_08033840
sub_08033840: @ 0x08033840
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl sub_0803EED8
	cmp r0, #0
	bne _080338B4
	ldr r0, _080338BC @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _0803386A
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r0, _080338C0 @ =0x03002414
	ldr r1, [r0]
	ldr r0, _080338C4 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _080338C8 @ =0x01000100
	mov r0, sp
	bl CpuFastSet
_0803386A:
	ldr r4, _080338CC @ =0x03001800
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803387C
	bl update_all_battle_status_sprites
_0803387C:
	ldr r0, _080338D0 @ =0x00000163
	adds r6, r4, r0
	ldr r5, _080338D4 @ =0x0300137C
	ldr r7, _080338D8 @ =0x083AF000
_08033884:
	movs r0, #0
	strb r0, [r6]
	bl sub_08034E94
	str r0, [r5]
	cmp r0, #0x7f
	ble _080338A2
	ldr r4, _080338D4 @ =0x0300137C
_08033894:
	bl sub_08034F08
	bl sub_08034E94
	str r0, [r4]
	cmp r0, #0x7f
	bgt _08033894
_080338A2:
	ldr r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _08033884
_080338B4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080338BC: .4byte 0x03000430
_080338C0: .4byte 0x03002414
_080338C4: .4byte 0x00000B84
_080338C8: .4byte 0x01000100
_080338CC: .4byte 0x03001800
_080338D0: .4byte 0x00000163
_080338D4: .4byte 0x0300137C
_080338D8: .4byte 0x083AF000
_080338DC:
	.byte 0x03, 0x49, 0x08, 0x20
	.byte 0x08, 0x60, 0x03, 0x49, 0x40, 0x20, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x8C, 0x2B, 0x00, 0x03
	.byte 0x7C, 0x13, 0x00, 0x03
	.syntax divided
