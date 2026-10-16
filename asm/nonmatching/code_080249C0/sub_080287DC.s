	.syntax unified

	thumb_func_start sub_080287DC
sub_080287DC: @ 0x080287DC
	push {r4, r5, r6, lr}
	bl sub_0803836C
	ldr r4, _08028848 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r4, #0x60
	strb r0, [r4]
	movs r5, #0
_080287F4:
	ldr r6, _0802884C @ =0x03000590
	ldr r4, _08028848 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r2, r0, r5
	lsls r0, r2, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _08028810
	b _080289E4
_08028810:
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802881C
	b _080289E4
_0802881C:
	adds r0, r2, #0
	bl sub_080331F8
	cmp r0, #0
	bne _08028828
	b _080289E4
_08028828:
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0xa8
	ldrb r0, [r0]
	subs r0, #0xc
	cmp r0, #0x1c
	bls _0802883E
	b _080289E4
_0802883E:
	lsls r0, r0, #2
	ldr r1, _08028850 @ =_08028854
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028848: .4byte 0x03001800
_0802884C: .4byte 0x03000590
_08028850: .4byte _08028854
_08028854: @ jump table
	.4byte _080288C8 @ case 0
	.4byte _080289E4 @ case 1
	.4byte _08028908 @ case 2
	.4byte _080289E4 @ case 3
	.4byte _08028944 @ case 4
	.4byte _080289E4 @ case 5
	.4byte _08028980 @ case 6
	.4byte _080289E4 @ case 7
	.4byte _080289E4 @ case 8
	.4byte _080289E4 @ case 9
	.4byte _080289E4 @ case 10
	.4byte _080289E4 @ case 11
	.4byte _080289E4 @ case 12
	.4byte _080289E4 @ case 13
	.4byte _080289E4 @ case 14
	.4byte _080289E4 @ case 15
	.4byte _080289E4 @ case 16
	.4byte _080289E4 @ case 17
	.4byte _080289E4 @ case 18
	.4byte _080289E4 @ case 19
	.4byte _080289E4 @ case 20
	.4byte _080289E4 @ case 21
	.4byte _080289E4 @ case 22
	.4byte _080289E4 @ case 23
	.4byte _080289E4 @ case 24
	.4byte _080289E4 @ case 25
	.4byte _080289E4 @ case 26
	.4byte _080289E4 @ case 27
	.4byte _080289BC @ case 28
_080288C8:
	ldr r4, _08028904 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x60
	ldrb r0, [r6]
	adds r0, r0, r5
	movs r1, #0xd
	bl sub_08036D64
	cmp r0, #0
	beq _080288DE
	b _080289E4
_080288DE:
	adds r0, r4, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0xe8
	movs r3, #0
	ldrsh r2, [r1, r3]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0xd
	bl battle_set_action_params
	b _080289E4
	.align 2, 0
_08028904: .4byte 0x03001800
_08028908:
	ldr r4, _08028940 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x60
	ldrb r0, [r6]
	adds r0, r0, r5
	movs r1, #0x10
	bl sub_08036D64
	cmp r0, #0
	bne _080289E4
	adds r0, r4, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0xe8
	movs r3, #0
	ldrsh r2, [r1, r3]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x10
	bl battle_set_action_params
	b _080289E4
	.align 2, 0
_08028940: .4byte 0x03001800
_08028944:
	ldr r4, _0802897C @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x60
	ldrb r0, [r6]
	adds r0, r0, r5
	movs r1, #0x12
	bl sub_08036D64
	cmp r0, #0
	bne _080289E4
	adds r0, r4, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0xe8
	movs r3, #0
	ldrsh r2, [r1, r3]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x12
	bl battle_set_action_params
	b _080289E4
	.align 2, 0
_0802897C: .4byte 0x03001800
_08028980:
	ldr r4, _080289B8 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0x60
	ldrb r0, [r6]
	adds r0, r0, r5
	movs r1, #0x13
	bl sub_08036D64
	cmp r0, #0
	bne _080289E4
	adds r0, r4, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0xe8
	movs r3, #0
	ldrsh r2, [r1, r3]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x13
	bl battle_set_action_params
	b _080289E4
	.align 2, 0
_080289B8: .4byte 0x03001800
_080289BC:
	ldr r3, _080289FC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xd2
	adds r0, r5, r0
	movs r1, #1
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r5
	adds r1, r3, #0
	adds r1, #0xe8
	movs r4, #0
	ldrsh r2, [r1, r4]
	adds r1, #4
	movs r4, #0
	ldrsh r3, [r1, r4]
	movs r1, #0x2c
	bl battle_set_action_params
_080289E4:
	adds r5, #1
	cmp r5, #2
	bhi _080289EC
	b _080287F4
_080289EC:
	ldr r1, _080289FC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080289FC: .4byte 0x03001800
	.syntax divided
