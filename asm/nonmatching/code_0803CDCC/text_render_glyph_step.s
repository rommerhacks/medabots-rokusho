	.syntax unified

	thumb_func_start text_render_glyph_step
text_render_glyph_step: @ 0x08040038
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08040084 @ =0x03000440
	ldrb r1, [r0, #0x18]
	mov sl, r0
	cmp r1, #0
	bne _080400E0
	movs r4, #0
	mov r8, r4
	movs r6, #0
	ldrh r0, [r0, #0xc]
	mov sb, r0
	mov r7, sl
	adds r7, #0x27
	ldrb r1, [r7]
	mov ip, r1
	ldr r5, _08040088 @ =0x083B4E88
	ldr r3, _0804008C @ =0x083B4C88
_08040062:
	mov r0, r8
	adds r1, r0, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	ldr r2, _08040084 @ =0x03000440
	ldr r1, [r2, #8]
	add r0, sb
	adds r1, r1, r0
	ldrb r2, [r1]
	mov r0, ip
	cmp r0, #0
	beq _08040090
	lsls r0, r2, #1
	adds r0, r0, r5
	b _08040094
	.align 2, 0
_08040084: .4byte 0x03000440
_08040088: .4byte 0x083B4E88
_0804008C: .4byte 0x083B4C88
_08040090:
	lsls r0, r2, #1
	adds r0, r0, r3
_08040094:
	ldrb r0, [r0]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r1, sl
	ldrh r0, [r1, #0xc]
	ldr r1, [r1, #8]
	add r0, r8
	adds r1, r1, r0
	ldrb r2, [r1]
	cmp r2, #0xf7
	bhi _080400C8
	cmp r2, #0
	bne _080400C4
	movs r6, #1
	ldrb r0, [r7]
	cmp r0, #0
	beq _080400BC
	ldrb r0, [r5]
	b _080400BE
_080400BC:
	ldrb r0, [r3]
_080400BE:
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080400C4:
	cmp r6, #0
	beq _08040062
_080400C8:
	mov r2, sl
	strb r4, [r2, #0x15]
	ldrb r0, [r2, #0x14]
	adds r0, r0, r4
	cmp r0, #0xd0
	ble _080400DA
	movs r0, #1
	strb r0, [r2, #0x19]
	b _080400E0
_080400DA:
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #0x18]
_080400E0:
	mov r2, sl
	ldrb r0, [r2, #0x19]
	cmp r0, #0
	beq _080400EA
	b _08040294
_080400EA:
	ldrh r1, [r2, #0xc]
	ldr r0, [r2, #8]
	adds r0, r0, r1
	ldrb r2, [r0]
	mov r0, sl
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040104
	ldr r0, _08040100 @ =0x083B4E88
	b _08040106
	.align 2, 0
_08040100: .4byte 0x083B4E88
_08040104:
	ldr r0, _08040138 @ =0x083B4C88
_08040106:
	lsls r1, r2, #1
	adds r0, r1, r0
	ldrb r4, [r0]
	ldr r3, _0804013C @ =0x03000440
	ldrb r0, [r3, #0x14]
	adds r0, r4, r0
	strb r0, [r3, #0x14]
	ldrb r0, [r3, #0x15]
	subs r0, r0, r4
	strb r0, [r3, #0x15]
	ldrb r0, [r3, #0x16]
	cmp r0, #0
	bne _0804016C
	adds r0, r3, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040148
	ldr r0, _08040140 @ =0x083B4E88
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r3, #0x16]
	lsls r0, r2, #6
	ldr r1, _08040144 @ =0x084C5188
	b _08040154
	.align 2, 0
_08040138: .4byte 0x083B4C88
_0804013C: .4byte 0x03000440
_08040140: .4byte 0x083B4E88
_08040144: .4byte 0x084C5188
_08040148:
	ldr r0, _08040160 @ =0x083B4C88
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r3, #0x16]
	lsls r0, r2, #6
	ldr r1, _08040164 @ =0x084C01C8
_08040154:
	adds r0, r0, r1
	ldr r1, _08040168 @ =0x02020000
	movs r2, #0x20
	bl CpuSet
	b _080401CE
	.align 2, 0
_08040160: .4byte 0x083B4C88
_08040164: .4byte 0x084C01C8
_08040168: .4byte 0x02020000
_0804016C:
	ldrb r0, [r3, #0x16]
	mov r8, r0
	adds r0, r3, #0
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040194
	lsls r0, r2, #6
	ldr r1, _0804018C @ =0x084C5188
	adds r0, r0, r1
	ldr r1, _08040190 @ =0x02020040
	movs r2, #0x20
	bl CpuSet
	b _080401A2
	.align 2, 0
_0804018C: .4byte 0x084C5188
_08040190: .4byte 0x02020040
_08040194:
	lsls r0, r2, #6
	ldr r1, _08040210 @ =0x084C01C8
	adds r0, r0, r1
	ldr r1, _08040214 @ =0x02020040
	movs r2, #0x20
	bl CpuSet
_080401A2:
	movs r3, #0
	ldr r7, _08040218 @ =0x02020000
	ldr r6, _08040214 @ =0x02020040
	mov r1, r8
	lsls r5, r1, #2
_080401AC:
	lsls r0, r3, #2
	adds r2, r0, r7
	adds r0, r0, r6
	ldr r1, [r0]
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _080401AC
	ldr r1, _0804021C @ =0x03000440
	ldrb r0, [r1, #0x16]
	adds r0, r4, r0
	strb r0, [r1, #0x16]
_080401CE:
	ldr r0, _0804021C @ =0x03000440
	ldrb r1, [r0, #0x16]
	mov sl, r0
	cmp r1, #7
	bls _08040282
	ldrb r1, [r0, #0x14]
	lsrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r4, _08040218 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r2, [r0, #0x17]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r0, r0, #7
	ldr r2, _08040220 @ =0x06000280
	adds r0, r0, r2
	adds r1, r1, r0
	adds r0, r4, #0
	movs r2, #0x20
	bl CpuSet
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #0x13]
	ldrb r0, [r1, #0x16]
	cmp r0, #8
	bne _08040224
	movs r0, #0
	strb r0, [r1, #0x16]
	b _08040282
	.align 2, 0
_08040210: .4byte 0x084C01C8
_08040214: .4byte 0x02020040
_08040218: .4byte 0x02020000
_0804021C: .4byte 0x03000440
_08040220: .4byte 0x06000280
_08040224:
	subs r0, #8
	mov r2, sl
	strb r0, [r2, #0x16]
	movs r0, #8
	mov r1, r8
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	mov r0, sl
	adds r0, #0x27
	ldrb r0, [r0]
	cmp r0, #0
	beq _08040250
	ldr r0, _0804024C @ =0x084C5188
	adds r1, r4, #0
	movs r2, #0x20
	bl CpuSet
	b _0804025A
	.align 2, 0
_0804024C: .4byte 0x084C5188
_08040250:
	ldr r0, _080402A4 @ =0x084C01C8
	adds r1, r4, #0
	movs r2, #0x20
	bl CpuSet
_0804025A:
	movs r3, #0
	ldr r2, _080402A8 @ =0x03000440
	mov sl, r2
	ldr r6, _080402AC @ =0x02020000
	ldr r5, _080402B0 @ =0x02020040
	mov r0, r8
	lsls r4, r0, #2
_08040268:
	lsls r0, r3, #2
	adds r2, r0, r6
	adds r0, r0, r5
	ldr r1, [r0]
	lsrs r1, r4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _08040268
_08040282:
	mov r1, sl
	ldrb r0, [r1, #0x15]
	cmp r0, #0
	bne _0804028C
	strb r0, [r1, #0x18]
_0804028C:
	mov r1, sl
	ldrh r0, [r1, #0xc]
	adds r0, #1
	strh r0, [r1, #0xc]
_08040294:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080402A4: .4byte 0x084C01C8
_080402A8: .4byte 0x03000440
_080402AC: .4byte 0x02020000
_080402B0: .4byte 0x02020040
	.syntax divided
