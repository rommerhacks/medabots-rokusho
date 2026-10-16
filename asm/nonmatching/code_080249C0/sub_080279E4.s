	.syntax unified

	thumb_func_start sub_080279E4
sub_080279E4: @ 0x080279E4
	push {r4, r5, r6, lr}
	ldr r0, _08027A18 @ =0x084DBB28
	ldr r1, _08027A1C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08027A20 @ =0x084E30B8
	ldr r1, _08027A24 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08027A28 @ =0x03000590
	ldr r0, _08027A2C @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xa8
	ldrb r0, [r0]
	subs r0, #4
	cmp r0, #4
	bhi _08027AA0
	lsls r0, r0, #2
	ldr r1, _08027A30 @ =_08027A34
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08027A18: .4byte 0x084DBB28
_08027A1C: .4byte 0x06014800
_08027A20: .4byte 0x084E30B8
_08027A24: .4byte 0x050002C0
_08027A28: .4byte 0x03000590
_08027A2C: .4byte 0x03001800
_08027A30: .4byte _08027A34
_08027A34: @ jump table
	.4byte _08027A48 @ case 0
	.4byte _08027A48 @ case 1
	.4byte _08027A74 @ case 2
	.4byte _08027A74 @ case 3
	.4byte _08027AA0 @ case 4
_08027A48:
	ldr r0, _08027A64 @ =0x084DBCAC
	ldr r1, _08027A68 @ =0x06014C00
	bl lz_decompress_dispatch
	ldr r0, _08027A6C @ =0x0850EB58
	ldr r1, _08027A70 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x27
	bl play_sound_effect
	b _08027AB8
	.align 2, 0
_08027A64: .4byte 0x084DBCAC
_08027A68: .4byte 0x06014C00
_08027A6C: .4byte 0x0850EB58
_08027A70: .4byte 0x050002E0
_08027A74:
	ldr r0, _08027A90 @ =0x084DBD0C
	ldr r1, _08027A94 @ =0x06014C00
	bl lz_decompress_dispatch
	ldr r0, _08027A98 @ =0x0850EB78
	ldr r1, _08027A9C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x45
	bl play_sound_effect
	b _08027AB8
	.align 2, 0
_08027A90: .4byte 0x084DBD0C
_08027A94: .4byte 0x06014C00
_08027A98: .4byte 0x0850EB78
_08027A9C: .4byte 0x050002E0
_08027AA0:
	ldr r0, _08027B3C @ =0x084DBD60
	ldr r1, _08027B40 @ =0x06014C00
	bl lz_decompress_dispatch
	ldr r0, _08027B44 @ =0x0850EB98
	ldr r1, _08027B48 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0x33
	bl play_sound_effect
_08027AB8:
	ldr r4, _08027B4C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r5, #0
	movs r3, #0
	ldr r0, _08027B50 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _08027B54 @ =0x0000085C
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08027B58 @ =0x03001800
	movs r6, #0x87
	adds r6, r6, r2
	mov ip, r6
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldr r6, _08027B5C @ =0x00000842
	adds r0, r4, r6
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r6, _08027B60 @ =0x00000844
	adds r1, r4, r6
	strh r0, [r1]
	ldr r1, _08027B64 @ =0x00000848
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r6, #5
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08027B68 @ =0x00000858
	adds r0, r4, r1
	strh r3, [r0]
	adds r6, #1
	adds r1, r4, r6
	movs r0, #6
	strb r0, [r1]
	ldr r0, _08027B6C @ =0x0000084B
	adds r1, r4, r0
	movs r0, #0xf0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08027B74
	subs r6, #4
	adds r1, r4, r6
	ldr r0, _08027B70 @ =0x00006601
	b _08027B7C
	.align 2, 0
_08027B3C: .4byte 0x084DBD60
_08027B40: .4byte 0x06014C00
_08027B44: .4byte 0x0850EB98
_08027B48: .4byte 0x050002E0
_08027B4C: .4byte 0x03002C30
_08027B50: .4byte 0x0000C604
_08027B54: .4byte 0x0000085C
_08027B58: .4byte 0x03001800
_08027B5C: .4byte 0x00000842
_08027B60: .4byte 0x00000844
_08027B64: .4byte 0x00000848
_08027B68: .4byte 0x00000858
_08027B6C: .4byte 0x0000084B
_08027B70: .4byte 0x00006601
_08027B74:
	ldr r0, _08027B98 @ =0x00000846
	adds r1, r4, r0
	movs r0, #0xcc
	lsls r0, r0, #7
_08027B7C:
	strh r0, [r1]
	ldr r0, _08027B9C @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	adds r1, r2, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027B98: .4byte 0x00000846
_08027B9C: .4byte 0x03000440
	.syntax divided
