	.syntax unified

	thumb_func_start setup_dialogue_script_from_rom
setup_dialogue_script_from_rom: @ 0x08066468
	push {lr}
	ldr r2, _0806649C @ =0x03006F74
	ldr r1, [r2]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r3, r1, r0
	movs r0, #0xfb
	strb r0, [r3]
	ldr r0, _080664A0 @ =0x00000271
	adds r3, r1, r0
	movs r0, #1
	strb r0, [r3]
	ldr r0, _080664A4 @ =0x00000272
	adds r3, r1, r0
	movs r0, #0xc
	strb r0, [r3]
	ldr r0, _080664A8 @ =0x00000273
	adds r3, r1, r0
	movs r0, #0
	strb r0, [r3]
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r3, r1, r0
	ldr r1, _080664AC @ =0x0848564F
	b _080664B4
	.align 2, 0
_0806649C: .4byte 0x03006F74
_080664A0: .4byte 0x00000271
_080664A4: .4byte 0x00000272
_080664A8: .4byte 0x00000273
_080664AC: .4byte 0x0848564F
_080664B0:
	adds r3, #1
	adds r1, #1
_080664B4:
	ldrb r0, [r1]
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080664B0
	movs r0, #0xff
	strb r0, [r3]
	movs r0, #4
	strb r0, [r3, #1]
	ldr r0, [r2]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r3, r0, r1
	adds r0, r3, #0
	bl run_message
	cmp r0, #0
	beq _080664F0
	bl sub_0803FB0C
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r1, _080664F4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080664F0:
	pop {r0}
	bx r0
	.align 2, 0
_080664F4: .4byte 0x0300137C
	.syntax divided
