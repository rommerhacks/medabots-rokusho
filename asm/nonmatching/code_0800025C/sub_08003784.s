	.syntax unified

	thumb_func_start sub_08003784
sub_08003784: @ 0x08003784
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0xc
	bl sub_080415BC
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov r8, r0
	ldrh r1, [r0]
	ldr r0, _0800387C @ =0x0000F0FF
	ands r0, r1
	mov r1, r8
	strh r0, [r1]
	ldr r6, _08003880 @ =0x0400000A
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r6]
	ldr r1, _08003884 @ =0x00001805
	adds r0, r1, #0
	strh r0, [r6]
	ldr r2, _08003888 @ =0x0400000C
	mov sb, r2
	ldr r1, _0800388C @ =0x00001906
	adds r0, r1, #0
	strh r0, [r2]
	adds r2, #2
	mov sl, r2
	ldr r1, _08003890 @ =0x00001A07
	adds r0, r1, #0
	strh r0, [r2]
	ldr r0, _08003894 @ =0x084E30D8
	ldr r1, _08003898 @ =0x06004000
	bl lz_decompress_dispatch
	bl sub_08003904
	ldr r4, _0800389C @ =0x040000D4
	ldr r0, _080038A0 @ =0x02020800
	str r0, [r4]
	ldr r0, _080038A4 @ =0x06002800
	str r0, [r4, #4]
	ldr r0, _080038A8 @ =0x84000200
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r2, _080038AC @ =0x084EF6A0
	ldrh r3, [r6]
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080038B0 @ =0x084F023C
	mov r0, sb
	ldrh r3, [r0]
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080038B4 @ =0x084F0F2C
	mov r1, sl
	ldrh r3, [r1]
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _080038B8 @ =0x084F24E0
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _080038BC @ =0x84000060
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080038C0 @ =0x083B4AE0
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #4
	movs r1, #4
	movs r2, #5
	movs r3, #9
	bl write_tilemap_rect
	mov r1, r8
	ldrh r0, [r1]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	mov r1, r8
	strh r0, [r1]
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r0, _080038C4 @ =0x03000440
	adds r0, #0x84
	strb r5, [r0]
	ldr r1, _080038C8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800387C: .4byte 0x0000F0FF
_08003880: .4byte 0x0400000A
_08003884: .4byte 0x00001805
_08003888: .4byte 0x0400000C
_0800388C: .4byte 0x00001906
_08003890: .4byte 0x00001A07
_08003894: .4byte 0x084E30D8
_08003898: .4byte 0x06004000
_0800389C: .4byte 0x040000D4
_080038A0: .4byte 0x02020800
_080038A4: .4byte 0x06002800
_080038A8: .4byte 0x84000200
_080038AC: .4byte 0x084EF6A0
_080038B0: .4byte 0x084F023C
_080038B4: .4byte 0x084F0F2C
_080038B8: .4byte 0x084F24E0
_080038BC: .4byte 0x84000060
_080038C0: .4byte 0x083B4AE0
_080038C4: .4byte 0x03000440
_080038C8: .4byte 0x0300137C
	.syntax divided
