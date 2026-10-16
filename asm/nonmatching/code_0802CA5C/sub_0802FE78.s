	.syntax unified

	thumb_func_start sub_0802FE78
sub_0802FE78: @ 0x0802FE78
	push {r4, r5, r6, r7, lr}
	ldr r0, _0802FF04 @ =0x084E1EA4
	ldr r1, _0802FF08 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802FF0C @ =0x0850EF18
	ldr r1, _0802FF10 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0802FF14 @ =0x084E30B8
	ldr r1, _0802FF18 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0802FF1C @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r3, r0
	movs r2, #0
	ldr r0, _0802FF20 @ =0x0000C404
	strh r0, [r1]
	ldr r1, _0802FF24 @ =0x0000085C
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, _0802FF28 @ =0x03001800
	movs r4, #0x87
	adds r4, r4, r2
	mov ip, r4
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #0x1c
	ldr r4, _0802FF2C @ =0x00000844
	adds r1, r3, r4
	strh r0, [r1]
	ldr r7, _0802FF30 @ =0x0000084A
	adds r1, r3, r7
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0802FF34 @ =0x0000084B
	adds r1, r3, r0
	movs r0, #0xf0
	strb r0, [r1]
	adds r4, #2
	adds r1, r3, r4
	movs r0, #0x84
	lsls r0, r0, #8
	strh r0, [r1]
	adds r2, #0xf8
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802FF38
	mov r7, ip
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	subs r0, #0x18
	b _0802FF4A
	.align 2, 0
_0802FF04: .4byte 0x084E1EA4
_0802FF08: .4byte 0x06014800
_0802FF0C: .4byte 0x0850EF18
_0802FF10: .4byte 0x050002C0
_0802FF14: .4byte 0x084E30B8
_0802FF18: .4byte 0x050002E0
_0802FF1C: .4byte 0x03002C30
_0802FF20: .4byte 0x0000C404
_0802FF24: .4byte 0x0000085C
_0802FF28: .4byte 0x03001800
_0802FF2C: .4byte 0x00000844
_0802FF30: .4byte 0x0000084A
_0802FF34: .4byte 0x0000084B
_0802FF38:
	mov r4, ip
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	adds r0, #0x18
_0802FF4A:
	ldr r2, _0802FFC0 @ =0x00000842
	adds r1, r3, r2
	strh r0, [r1]
	ldr r2, _0802FFC4 @ =0x03002C30
	movs r3, #0x88
	lsls r3, r3, #4
	adds r1, r2, r3
	movs r3, #0
	ldr r0, _0802FFC8 @ =0x0000C404
	strh r0, [r1]
	ldr r4, _0802FFCC @ =0x0000089C
	adds r0, r2, r4
	strb r3, [r0]
	ldr r3, _0802FFD0 @ =0x03001800
	movs r7, #0x87
	adds r7, r7, r3
	mov ip, r7
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #0x1c
	subs r4, #0x18
	adds r1, r2, r4
	strh r0, [r1]
	ldr r7, _0802FFD4 @ =0x0000088A
	adds r1, r2, r7
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0802FFD8 @ =0x0000088B
	adds r1, r2, r0
	movs r0, #0xf0
	strb r0, [r1]
	adds r4, #2
	adds r1, r2, r4
	ldr r0, _0802FFDC @ =0x00008401
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	bne _0802FFE0
	mov r7, ip
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	subs r0, #0x18
	b _0802FFF2
	.align 2, 0
_0802FFC0: .4byte 0x00000842
_0802FFC4: .4byte 0x03002C30
_0802FFC8: .4byte 0x0000C404
_0802FFCC: .4byte 0x0000089C
_0802FFD0: .4byte 0x03001800
_0802FFD4: .4byte 0x0000088A
_0802FFD8: .4byte 0x0000088B
_0802FFDC: .4byte 0x00008401
_0802FFE0:
	mov r7, ip
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	adds r0, #0x18
_0802FFF2:
	ldr r3, _08030064 @ =0x00000882
	adds r1, r2, r3
	strh r0, [r1]
	movs r7, #0x8c
	lsls r7, r7, #4
	adds r7, r7, r2
	mov ip, r7
	movs r6, #0
	ldr r5, _08030068 @ =0x0000C404
	strh r5, [r7]
	ldr r1, _0803006C @ =0x000008DC
	adds r0, r2, r1
	strb r6, [r0]
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #0x1c
	ldr r7, _08030070 @ =0x000008C4
	adds r1, r2, r7
	strh r0, [r1]
	ldr r0, _08030074 @ =0x000008CA
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	adds r7, #7
	adds r1, r2, r7
	movs r0, #0xf1
	strb r0, [r1]
	ldr r0, _08030078 @ =0x000008C6
	adds r1, r2, r0
	ldr r0, _0803007C @ =0x00008402
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08030084
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	adds r0, #0x18
	ldr r3, _08030080 @ =0x000008C2
	adds r1, r2, r3
	b _080300A6
	.align 2, 0
_08030064: .4byte 0x00000882
_08030068: .4byte 0x0000C404
_0803006C: .4byte 0x000008DC
_08030070: .4byte 0x000008C4
_08030074: .4byte 0x000008CA
_08030078: .4byte 0x000008C6
_0803007C: .4byte 0x00008402
_08030080: .4byte 0x000008C2
_08030084:
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	subs r0, #0x18
	ldr r3, _08030114 @ =0x000008C2
	adds r1, r2, r3
	strh r0, [r1]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r1, r7, #0
	adds r0, r5, #0
	orrs r0, r1
	mov r1, ip
_080300A6:
	strh r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #4
	adds r3, r3, r2
	mov ip, r3
	movs r6, #0
	ldr r5, _08030118 @ =0x0000C404
	strh r5, [r3]
	ldr r7, _0803011C @ =0x0000091C
	adds r0, r2, r7
	strb r6, [r0]
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #0x1c
	subs r7, #0x18
	adds r1, r2, r7
	strh r0, [r1]
	ldr r0, _08030120 @ =0x0000090A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	adds r7, #7
	adds r1, r2, r7
	movs r0, #0xf1
	strb r0, [r1]
	ldr r0, _08030124 @ =0x00000906
	adds r1, r2, r0
	ldr r0, _08030128 @ =0x00008403
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08030130
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	adds r0, #0x18
	ldr r3, _0803012C @ =0x00000902
	adds r1, r2, r3
	b _08030152
	.align 2, 0
_08030114: .4byte 0x000008C2
_08030118: .4byte 0x0000C404
_0803011C: .4byte 0x0000091C
_08030120: .4byte 0x0000090A
_08030124: .4byte 0x00000906
_08030128: .4byte 0x00008403
_0803012C: .4byte 0x00000902
_08030130:
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r4, #0xba
	lsls r4, r4, #5
	adds r0, r0, r4
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	subs r0, #0x18
	ldr r7, _08030174 @ =0x00000902
	adds r1, r2, r7
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	adds r1, r0, #0
	adds r0, r5, #0
	orrs r0, r1
	mov r1, ip
_08030152:
	strh r0, [r1]
	ldr r0, _08030178 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _0803017C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08030174: .4byte 0x00000902
_08030178: .4byte 0x03000440
_0803017C: .4byte 0x03001800
_08030180:
	.byte 0x06, 0x48, 0x01, 0x1C, 0x86, 0x31, 0x08, 0x88, 0x18, 0x28, 0x0B, 0xD1, 0x00, 0x20, 0x08, 0x80
	.byte 0x03, 0x49, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x42, 0xE0, 0x40, 0x04, 0x00, 0x03
	.byte 0x00, 0x18, 0x00, 0x03, 0x01, 0x30, 0x08, 0x80, 0x0D, 0x48, 0xF8, 0x30, 0x01, 0x78, 0x01, 0x20
	.byte 0x08, 0x40, 0x00, 0x28, 0x20, 0xD1, 0x0B, 0x49, 0x0B, 0x48, 0x0A, 0x18, 0x10, 0x88, 0x01, 0x30
	.byte 0x10, 0x80, 0x0A, 0x48, 0x0A, 0x18, 0x10, 0x88, 0x01, 0x30, 0x10, 0x80, 0x08, 0x48, 0x0A, 0x18
	.byte 0x10, 0x88, 0x01, 0x38, 0x10, 0x80, 0x07, 0x48, 0x09, 0x18, 0x08, 0x88, 0x01, 0x38, 0x1F, 0xE0
	.byte 0x00, 0x18, 0x00, 0x03, 0x30, 0x2C, 0x00, 0x03, 0x42, 0x08, 0x00, 0x00, 0x82, 0x08, 0x00, 0x00
	.byte 0xC2, 0x08, 0x00, 0x00, 0x02, 0x09, 0x00, 0x00, 0x0A, 0x49, 0x0B, 0x48, 0x0A, 0x18, 0x10, 0x88
	.byte 0x01, 0x38, 0x10, 0x80, 0x09, 0x48, 0x0A, 0x18, 0x10, 0x88, 0x01, 0x38, 0x10, 0x80, 0x08, 0x48
	.byte 0x0A, 0x18, 0x10, 0x88, 0x01, 0x30, 0x10, 0x80, 0x06, 0x48, 0x09, 0x18, 0x08, 0x88, 0x01, 0x30
	.byte 0x08, 0x80, 0x70, 0x47, 0x30, 0x2C, 0x00, 0x03, 0x42, 0x08, 0x00, 0x00, 0x82, 0x08, 0x00, 0x00
	.byte 0xC2, 0x08, 0x00, 0x00, 0x02, 0x09, 0x00, 0x00, 0x05, 0x48, 0x01, 0x1C, 0x86, 0x31, 0x08, 0x88
	.byte 0x0C, 0x28, 0x09, 0xD1, 0x03, 0x49, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x1A, 0xE0
	.byte 0x40, 0x04, 0x00, 0x03, 0x00, 0x18, 0x00, 0x03, 0x01, 0x30, 0x08, 0x80, 0x0A, 0x49, 0x0B, 0x48
	.byte 0x0A, 0x18, 0x10, 0x88, 0x02, 0x30, 0x10, 0x80, 0x09, 0x48, 0x0A, 0x18, 0x10, 0x88, 0x02, 0x30
	.byte 0x10, 0x80, 0x08, 0x48, 0x0A, 0x18, 0x10, 0x88, 0x02, 0x30, 0x10, 0x80, 0x06, 0x48, 0x09, 0x18
	.byte 0x08, 0x88, 0x02, 0x30, 0x08, 0x80, 0x70, 0x47, 0x30, 0x2C, 0x00, 0x03, 0x44, 0x08, 0x00, 0x00
	.byte 0x84, 0x08, 0x00, 0x00, 0xC4, 0x08, 0x00, 0x00, 0x04, 0x09, 0x00, 0x00
	.syntax divided
