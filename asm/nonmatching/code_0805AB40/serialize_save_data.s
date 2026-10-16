	.syntax unified

	thumb_func_start serialize_save_data
serialize_save_data: @ 0x0805DEA8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r4, #0
	ldr r3, _0805DF84 @ =0x03002B70
	ldr r2, _0805DF88 @ =0x08483C20
_0805DEB2:
	adds r0, r7, r4
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, #1
	cmp r4, #0xf
	ble _0805DEB2
	adds r0, r7, #0
	adds r0, #0x10
	adds r1, r3, #0
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r6, _0805DF8C @ =0x03000BE0
	movs r4, #0x1d
_0805DEDA:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x40
	bl memcpy_optimized
	adds r5, #0x40
	adds r6, #0x40
	subs r4, #1
	cmp r4, #0
	bge _0805DEDA
	movs r4, #0
	ldr r3, _0805DF90 @ =0x000003BF
	ldr r5, _0805DF94 @ =0x03002BA0
	ldr r2, _0805DF98 @ =0x03004C40
	ldr r0, _0805DF9C @ =0x000007AC
	adds r1, r7, r0
_0805DEFA:
	adds r0, r4, r2
	ldrb r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r4, #1
	cmp r4, r3
	ble _0805DEFA
	ldr r3, _0805DFA0 @ =0x030017A0
	ldr r1, _0805DFA4 @ =0x00000F2C
	adds r2, r7, r1
	movs r4, #8
_0805DF10:
	ldm r3!, {r0, r1}
	stm r2!, {r0, r1}
	subs r4, #1
	cmp r4, #0
	bge _0805DF10
	ldr r2, _0805DFA8 @ =0x00000F74
	adds r1, r7, r2
	adds r0, r5, #0
	movs r2, #0x40
	bl CpuSet
	ldr r0, _0805DFAC @ =0x030057E0
	ldr r3, _0805DFB0 @ =0x00000FF8
	adds r1, r7, r3
	movs r2, #0xcc
	lsls r2, r2, #3
	bl CpuSet
	ldr r2, _0805DFB4 @ =0x03001788
	ldr r0, _0805DFB8 @ =0x03001360
	ldrb r1, [r0]
	lsls r1, r1, #2
	ldrb r0, [r2]
	orrs r1, r0
	ldr r0, _0805DFBC @ =0x03000B94
	ldrb r0, [r0]
	lsls r0, r0, #3
	orrs r1, r0
	ldr r0, _0805DFC0 @ =0x03001784
	ldr r0, [r0]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	lsls r0, r0, #5
	orrs r1, r0
	ldr r4, _0805DFC4 @ =0x00001CB8
	adds r0, r7, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0805DFC8 @ =0x00000FF4
	adds r0, r7, r1
	strh r2, [r0]
	adds r1, r7, #0
	movs r4, #0
	ldr r3, _0805DFCC @ =0x00001CBB
_0805DF68:
	ldrb r0, [r1]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r1, #1
	adds r4, #1
	cmp r4, r3
	bls _0805DF68
	ldr r3, _0805DFC8 @ =0x00000FF4
	adds r0, r7, r3
	strh r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805DF84: .4byte 0x03002B70
_0805DF88: .4byte 0x08483C20
_0805DF8C: .4byte 0x03000BE0
_0805DF90: .4byte 0x000003BF
_0805DF94: .4byte 0x03002BA0
_0805DF98: .4byte 0x03004C40
_0805DF9C: .4byte 0x000007AC
_0805DFA0: .4byte 0x030017A0
_0805DFA4: .4byte 0x00000F2C
_0805DFA8: .4byte 0x00000F74
_0805DFAC: .4byte 0x030057E0
_0805DFB0: .4byte 0x00000FF8
_0805DFB4: .4byte 0x03001788
_0805DFB8: .4byte 0x03001360
_0805DFBC: .4byte 0x03000B94
_0805DFC0: .4byte 0x03001784
_0805DFC4: .4byte 0x00001CB8
_0805DFC8: .4byte 0x00000FF4
_0805DFCC: .4byte 0x00001CBB
	.syntax divided
