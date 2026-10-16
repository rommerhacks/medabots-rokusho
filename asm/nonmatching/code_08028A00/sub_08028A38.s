	.syntax unified

	thumb_func_start sub_08028A38
sub_08028A38: @ 0x08028A38
	push {r4, r5, r6, r7, lr}
	ldr r0, _08028AB8 @ =0x084DCF54
	ldr r1, _08028ABC @ =0x06016000
	bl lz_decompress_dispatch
	ldr r0, _08028AC0 @ =0x0850EC58
	ldr r1, _08028AC4 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r6, #0
_08028A4E:
	ldr r0, _08028AC8 @ =0x03001800
	mov ip, r0
	adds r0, #0xd2
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08028B34
	ldr r3, _08028ACC @ =0x03002C30
	adds r5, r6, #0
	adds r5, #0x21
	lsls r1, r5, #6
	adds r1, r1, r3
	movs r4, #0
	ldr r0, _08028AD0 @ =0x0000C404
	strh r0, [r1]
	strb r4, [r1, #0x1c]
	mov r2, ip
	adds r2, #0x60
	ldrb r0, [r2]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldrb r0, [r2]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r2, r7, #0
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r1, #4]
	movs r0, #7
	strb r0, [r1, #0xa]
	movs r0, #0xf0
	strb r0, [r1, #0xb]
	adds r1, #0x23
	strb r4, [r1]
	mov r0, ip
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08028B34
	lsls r0, r0, #2
	ldr r1, _08028AD4 @ =_08028AD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028AB8: .4byte 0x084DCF54
_08028ABC: .4byte 0x06016000
_08028AC0: .4byte 0x0850EC58
_08028AC4: .4byte 0x050002E0
_08028AC8: .4byte 0x03001800
_08028ACC: .4byte 0x03002C30
_08028AD0: .4byte 0x0000C404
_08028AD4: .4byte _08028AD8
_08028AD8: @ jump table
	.4byte _08028AF0 @ case 0
	.4byte _08028AFA @ case 1
	.4byte _08028B08 @ case 2
	.4byte _08028B14 @ case 3
	.4byte _08028B20 @ case 4
	.4byte _08028B2C @ case 5
_08028AF0:
	lsls r0, r5, #6
	adds r0, r0, r3
	movs r1, #0xde
	lsls r1, r1, #7
	b _08028B32
_08028AFA:
	lsls r0, r5, #6
	adds r0, r0, r3
	ldr r1, _08028B04 @ =0x00006F03
	b _08028B32
	.align 2, 0
_08028B04: .4byte 0x00006F03
_08028B08:
	lsls r0, r5, #6
	adds r0, r0, r3
	ldr r1, _08028B10 @ =0x00006F01
	b _08028B32
	.align 2, 0
_08028B10: .4byte 0x00006F01
_08028B14:
	lsls r0, r5, #6
	adds r0, r0, r3
	ldr r1, _08028B1C @ =0x00006F02
	b _08028B32
	.align 2, 0
_08028B1C: .4byte 0x00006F02
_08028B20:
	lsls r0, r5, #6
	adds r0, r0, r3
	ldr r1, _08028B28 @ =0x00006F05
	b _08028B32
	.align 2, 0
_08028B28: .4byte 0x00006F05
_08028B2C:
	lsls r0, r5, #6
	adds r0, r0, r3
	ldr r1, _08028B50 @ =0x00006F04
_08028B32:
	strh r1, [r0, #6]
_08028B34:
	adds r6, #1
	cmp r6, #2
	bls _08028A4E
	movs r0, #0x5b
	bl play_sound_effect
	ldr r1, _08028B54 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028B50: .4byte 0x00006F04
_08028B54: .4byte 0x03001800
	.syntax divided
