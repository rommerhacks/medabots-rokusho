	.syntax unified

	thumb_func_start battle_render_bot_status_icon
battle_render_bot_status_icon: @ 0x08025858
	push {r4, r5, lr}
	ldr r3, _08025890 @ =0x03000590
	ldr r2, _08025894 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, #0x87
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x2e
	bne _080258A8
	ldr r0, _08025898 @ =0x084D6CC4
	ldr r1, _0802589C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080258A0 @ =0x0850E8F8
	ldr r1, _080258A4 @ =0x050002E0
	movs r2, #0x10
	bl CpuFastSet
	b _080258BA
	.align 2, 0
_08025890: .4byte 0x03000590
_08025894: .4byte 0x03001800
_08025898: .4byte 0x084D6CC4
_0802589C: .4byte 0x06014800
_080258A0: .4byte 0x0850E8F8
_080258A4: .4byte 0x050002E0
_080258A8:
	ldr r0, _08025948 @ =0x084D6E20
	ldr r1, _0802594C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08025950 @ =0x0850E918
	ldr r1, _08025954 @ =0x050002E0
	movs r2, #0x10
	bl CpuFastSet
_080258BA:
	ldr r2, _08025958 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r2, r0
	ldrh r1, [r3]
	movs r4, #0x88
	lsls r4, r4, #2
	adds r0, r4, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r5, _0802595C @ =0x00000848
	adds r0, r2, r5
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08025960 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	adds r5, #0x10
	adds r0, r2, r5
	strh r4, [r0]
	ldr r0, _08025964 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	subs r3, #3
	adds r1, r2, r3
	movs r0, #0xa4
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r3, _08025968 @ =0x03001800
	adds r4, r3, #0
	adds r4, #0x88
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r5, #0x87
	lsls r5, r5, #4
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r4, _0802596C @ =0x00000872
	adds r1, r2, r4
	strh r0, [r1]
	subs r5, #0xc
	adds r2, r2, r5
	movs r0, #6
	strb r0, [r2]
	ldr r0, _08025970 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r3, #0xaa
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025948: .4byte 0x084D6E20
_0802594C: .4byte 0x06014800
_08025950: .4byte 0x0850E918
_08025954: .4byte 0x050002E0
_08025958: .4byte 0x03002C30
_0802595C: .4byte 0x00000848
_08025960: .4byte 0x00000849
_08025964: .4byte 0x0000084A
_08025968: .4byte 0x03001800
_0802596C: .4byte 0x00000872
_08025970: .4byte 0x03000440
	.syntax divided
