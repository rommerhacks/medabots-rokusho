	.syntax unified

	thumb_func_start setup_screen_transition_effect_080684F0
	.global setup_screen_transition_effect_080684F0
setup_screen_transition_effect_080684F0: @ 0x080684F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08068530 @ =0xFFFFFA80
	add sp, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _08068534 @ =0x03000000
	str r1, [r0]
	ldr r3, _08068538 @ =0x03000028
	strh r2, [r3]
	ldr r0, _0806853C @ =0x03000004
	strb r4, [r0]
	ldr r2, _08068540 @ =0x03000005
	strb r1, [r2]
	mov sb, r3
	cmp r1, #0
	bne _08068522
	movs r0, #1
	strb r0, [r2]
_08068522:
	cmp r4, #2
	beq _0806855C
	cmp r4, #2
	bgt _08068544
	cmp r4, #1
	beq _08068550
	b _080686AA
	.align 2, 0
_08068530: .4byte 0xFFFFFA80
_08068534: .4byte 0x03000000
_08068538: .4byte 0x03000028
_0806853C: .4byte 0x03000004
_08068540: .4byte 0x03000005
_08068544:
	cmp r5, #3
	beq _08068568
	cmp r5, #4
	bne _0806854E
	b _08068690
_0806854E:
	b _080686AA
_08068550:
	ldr r1, _08068558 @ =0x04000050
	movs r0, #0xbf
	strh r0, [r1]
	b _080686AA
	.align 2, 0
_08068558: .4byte 0x04000050
_0806855C:
	ldr r1, _08068564 @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	b _080686AA
	.align 2, 0
_08068564: .4byte 0x04000050
_08068568:
	add r0, sp, #0x80
	mov ip, r0
	ldr r1, _0806864C @ =0x03001780
	mov sl, r1
	movs r1, #0x11
	mov r0, sp
	adds r0, #0x7f
_08068576:
	strb r1, [r0]
	subs r0, #1
	cmp r0, sp
	bge _08068576
	ldr r1, _08068650 @ =0x040000D4
	mov r2, sp
	str r2, [r1]
	ldr r0, _08068654 @ =0x0600FF80
	str r0, [r1, #4]
	ldr r0, _08068658 @ =0x80000040
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r4, #0
	ldr r3, _0806865C @ =0x0000027F
	mov r8, r3
	ldr r7, _08068660 @ =0x083F7FF4
	ldr r0, _0806864C @ =0x03001780
	ldr r2, [r0]
	mov r1, ip
	movs r6, #0xff
	movs r3, #3
	ldr r0, _08068664 @ =0x0000F1FC
	adds r5, r0, #0
_080685A4:
	adds r0, r2, r4
	ands r0, r6
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r3
	adds r0, r0, r5
	strh r0, [r1]
	adds r1, #2
	adds r4, #1
	cmp r4, r8
	ble _080685A4
	ldr r0, _08068650 @ =0x040000D4
	mov r1, ip
	str r1, [r0]
	ldr r1, _08068668 @ =0x0600F800
	str r1, [r0, #4]
	ldr r1, _0806866C @ =0x84000140
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	mov r2, sb
	str r2, [r0]
	ldr r1, _08068670 @ =0x050001E2
	str r1, [r0, #4]
	ldr r1, _08068674 @ =0x80000001
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _08068678 @ =0x04000008
	ldr r3, _0806867C @ =0x00001F0C
	adds r0, r3, #0
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0
	ldr r0, _08068680 @ =0x03000008
	ldr r5, _08068684 @ =0x00003F92
	ldr r3, _08068688 @ =0x00003F90
	ldr r2, _0806868C @ =0x00003F82
	movs r1, #0xfe
	lsls r1, r1, #6
_080685FE:
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #4]
	strh r5, [r0, #6]
	adds r0, #8
	adds r5, #0x20
	adds r3, #0x20
	adds r2, #0x20
	adds r1, #0x20
	adds r4, #1
	cmp r4, #3
	ble _080685FE
	movs r4, #0
	ldr r5, _08068680 @ =0x03000008
	adds r6, r5, #0
_0806861C:
	mov r1, sl
	ldr r0, [r1]
	adds r0, r0, r4
	movs r1, #0xff
	ands r0, r1
	ldr r2, _08068660 @ =0x083F7FF4
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #0x10
	subs r1, r1, r4
	bl sub_0807CC88
	adds r0, r0, r4
	ldrh r2, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	strh r1, [r5]
	strh r2, [r0]
	adds r5, #2
	adds r4, #1
	cmp r4, #0xe
	ble _0806861C
	b _080686AA
	.align 2, 0
_0806864C: .4byte 0x03001780
_08068650: .4byte 0x040000D4
_08068654: .4byte 0x0600FF80
_08068658: .4byte 0x80000040
_0806865C: .4byte 0x0000027F
_08068660: .4byte 0x083F7FF4
_08068664: .4byte 0x0000F1FC
_08068668: .4byte 0x0600F800
_0806866C: .4byte 0x84000140
_08068670: .4byte 0x050001E2
_08068674: .4byte 0x80000001
_08068678: .4byte 0x04000008
_0806867C: .4byte 0x00001F0C
_08068680: .4byte 0x03000008
_08068684: .4byte 0x00003F92
_08068688: .4byte 0x00003F90
_0806868C: .4byte 0x00003F82
_08068690:
	ldr r0, _080686C0 @ =0x0300002C
	ldr r2, _080686C4 @ =0x0202F800
	str r2, [r0]
	ldr r1, _080686C8 @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _080686CC @ =0x80000200
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl scene_step_palette_fade_out
_080686AA:
	movs r3, #0xb0
	lsls r3, r3, #3
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080686C0: .4byte 0x0300002C
_080686C4: .4byte 0x0202F800
_080686C8: .4byte 0x040000D4
_080686CC: .4byte 0x80000200
	.syntax divided
