	.syntax unified

	thumb_func_start load_save_data
load_save_data: @ 0x0805DDB0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0805DE68 @ =0x03002B70
	adds r1, r7, #0
	adds r1, #0x10
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r6, _0805DE6C @ =0x03000BE0
	movs r4, #0x1d
_0805DDCE:
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x40
	bl memcpy_optimized
	adds r5, #0x40
	adds r6, #0x40
	subs r4, #1
	cmp r4, #0
	bge _0805DDCE
	movs r4, #0
	ldr r5, _0805DE70 @ =0x000003BF
	ldr r6, _0805DE74 @ =0x03002BA0
	ldr r3, _0805DE78 @ =0x03004C40
	ldr r0, _0805DE7C @ =0x000007AC
	adds r2, r7, r0
_0805DDEE:
	adds r1, r4, r3
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, #2
	adds r4, #1
	cmp r4, r5
	ble _0805DDEE
	ldr r1, _0805DE80 @ =0x00000F2C
	adds r2, r7, r1
	ldr r3, _0805DE84 @ =0x030017A0
	movs r4, #8
_0805DE04:
	ldm r2!, {r0, r1}
	stm r3!, {r0, r1}
	subs r4, #1
	cmp r4, #0
	bge _0805DE04
	ldr r2, _0805DE88 @ =0x00000F74
	adds r0, r7, r2
	adds r1, r6, #0
	movs r2, #0x40
	bl CpuSet
	ldr r3, _0805DE8C @ =0x00000FF8
	adds r0, r7, r3
	ldr r1, _0805DE90 @ =0x030057E0
	movs r2, #0xcc
	lsls r2, r2, #3
	bl CpuSet
	ldr r2, _0805DE94 @ =0x03001788
	ldr r4, _0805DE98 @ =0x00001CB8
	adds r0, r7, r4
	ldrb r1, [r0]
	movs r4, #3
	movs r0, #3
	ands r0, r1
	strb r0, [r2]
	ldr r3, _0805DE9C @ =0x03001360
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x1a
	movs r2, #1
	ands r0, r2
	strb r0, [r3]
	ldr r3, _0805DEA0 @ =0x03000B94
	lsrs r0, r1, #0x1b
	ands r0, r4
	strb r0, [r3]
	ldr r3, _0805DEA4 @ =0x03001784
	lsrs r1, r1, #0x1d
	ands r1, r2
	ands r1, r2
	lsls r1, r1, #1
	ldrb r2, [r3]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805DE68: .4byte 0x03002B70
_0805DE6C: .4byte 0x03000BE0
_0805DE70: .4byte 0x000003BF
_0805DE74: .4byte 0x03002BA0
_0805DE78: .4byte 0x03004C40
_0805DE7C: .4byte 0x000007AC
_0805DE80: .4byte 0x00000F2C
_0805DE84: .4byte 0x030017A0
_0805DE88: .4byte 0x00000F74
_0805DE8C: .4byte 0x00000FF8
_0805DE90: .4byte 0x030057E0
_0805DE94: .4byte 0x03001788
_0805DE98: .4byte 0x00001CB8
_0805DE9C: .4byte 0x03001360
_0805DEA0: .4byte 0x03000B94
_0805DEA4: .4byte 0x03001784
	.syntax divided
