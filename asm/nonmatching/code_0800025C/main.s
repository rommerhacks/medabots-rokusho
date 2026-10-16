	.syntax unified

	thumb_func_start main
	.global main
main: @ 0x0800025C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _08000330 @ =0x04000204
	ldr r2, _08000334 @ =0x00004014
	adds r0, r2, #0
	strh r0, [r1]
	bl hw_reset_init
	bl irq_init
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	ldr r1, _08000338 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r0, _0800033C @ =0x03002B8C
	movs r4, #0
	str r4, [r0]
	ldr r0, _08000340 @ =0x0300137C
	str r4, [r0]
	bl serial_link_init
	ldr r0, _08000344 @ =0x03002430
	bl sound_init
	ldr r0, _08000348 @ =0x03001784
	movs r1, #0
	strh r4, [r0]
	ldr r0, _0800034C @ =0x03005030
	strb r1, [r0]
	ldr r0, _08000350 @ =0x03002410
	strb r1, [r0]
	ldr r0, _08000354 @ =0x03005010
	strb r1, [r0, #0x1e]
	strb r1, [r0, #0x1d]
_080002AC:
	bl VBlankIntrWait
	ldr r1, _08000350 @ =0x03002410
	movs r0, #0
	strb r0, [r1]
	bl read_keys
	ldr r1, _08000358 @ =0x03001780
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _0800035C @ =0x03000588
	ldrb r0, [r0]
	cmp r0, #0
	beq _080002D8
	ldr r2, _08000360 @ =0x03002B70
	ldr r1, [r2, #0x18]
	ldr r0, _08000364 @ =0x014996FE
	cmp r1, r0
	bhi _080002D8
	adds r0, r1, #1
	str r0, [r2, #0x18]
_080002D8:
	ldr r5, _08000368 @ =0x03005170
	ldrb r7, [r5, #2]
	mov sb, r7
	ldr r4, _08000354 @ =0x03005010
	movs r0, #0
	strb r0, [r4, #0x1d]
	strb r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #8
	bl serial_link_init_and_status
	str r0, [r4]
	movs r6, #0
	movs r0, #1
	mov sl, r0
	movs r1, #0xff
	mov r8, r1
	movs r2, #0x19
	adds r2, r2, r4
	mov ip, r2
_08000300:
	mov r1, sl
	lsls r1, r6
	ldr r3, [r4]
	ands r3, r1
	cmp r3, #0
	beq _0800036C
	movs r0, #0
	mov r7, ip
	strb r0, [r7]
	mov r0, sb
	asrs r0, r6
	mov r2, sl
	ands r0, r2
	cmp r0, #0
	bne _080003A6
	ldrb r0, [r5, #2]
	orrs r1, r0
	strb r1, [r5, #2]
	ldrb r0, [r4, #0x1d]
	mov r7, r8
	orrs r0, r7
	strb r0, [r4, #0x1d]
	b _080003A6
	.align 2, 0
_08000330: .4byte 0x04000204
_08000334: .4byte 0x00004014
_08000338: .4byte 0x0300178C
_0800033C: .4byte 0x03002B8C
_08000340: .4byte 0x0300137C
_08000344: .4byte 0x03002430
_08000348: .4byte 0x03001784
_0800034C: .4byte 0x03005030
_08000350: .4byte 0x03002410
_08000354: .4byte 0x03005010
_08000358: .4byte 0x03001780
_0800035C: .4byte 0x03000588
_08000360: .4byte 0x03002B70
_08000364: .4byte 0x014996FE
_08000368: .4byte 0x03005170
_0800036C:
	mov r0, ip
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xa
	ble _080003A0
	ldr r2, _0800039C @ =0x03005170
	ldrb r0, [r2, #2]
	asrs r0, r6
	mov r7, sl
	ands r0, r7
	cmp r0, #0
	beq _08000390
	ldrb r0, [r4, #0x1e]
	mov r7, r8
	orrs r0, r7
	strb r0, [r4, #0x1e]
_08000390:
	ldrb r0, [r2, #2]
	bics r0, r1
	strb r0, [r2, #2]
	mov r0, ip
	strb r3, [r0]
	b _080003A6
	.align 2, 0
_0800039C: .4byte 0x03005170
_080003A0:
	adds r0, r2, #1
	mov r1, ip
	strb r0, [r1]
_080003A6:
	movs r2, #1
	add ip, r2
	adds r6, #1
	cmp r6, #3
	ble _08000300
	bl check_soft_reset
	adds r4, r0, #0
	cmp r4, #0
	beq _080003D0
	bl VBlankIntrWait
	ldr r0, _080003CC @ =0x03002430
	bl sound_init
	bl VBlankIntrWait
	b _08000416
	.align 2, 0
_080003CC: .4byte 0x03002430
_080003D0:
	ldr r0, _08000434 @ =0x03005030
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _08000416
	movs r1, #0
	ldr r0, _08000438 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	bne _080003E8
	movs r1, #1
_080003E8:
	ldr r3, _0800043C @ =0x03005010
	lsls r2, r1, #2
	adds r0, r3, #0
	adds r0, #8
	adds r0, r2, r0
	ldrh r1, [r0]
	ldr r0, _08000440 @ =0x0000FFFF
	cmp r1, r0
	bne _08000416
	adds r0, r3, #0
	adds r0, #0xa
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, r1
	bne _08000416
	ldr r0, _08000444 @ =0x0300178C
	str r4, [r0]
	ldr r1, _08000448 @ =0x03002B8C
	movs r0, #0xa
	str r0, [r1]
	ldr r1, _0800044C @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
_08000416:
	ldr r1, _08000450 @ =0x083ABE18
	ldr r0, _08000444 @ =0x0300178C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	bl check_flag_and_fast_copy
	ldr r0, _08000454 @ =0x03005014
	bl serial_prepare_send_packet
	b _080002AC
	.align 2, 0
_08000434: .4byte 0x03005030
_08000438: .4byte 0x03000B90
_0800043C: .4byte 0x03005010
_08000440: .4byte 0x0000FFFF
_08000444: .4byte 0x0300178C
_08000448: .4byte 0x03002B8C
_0800044C: .4byte 0x0300137C
_08000450: .4byte 0x083ABE18
_08000454: .4byte 0x03005014
	.syntax divided
