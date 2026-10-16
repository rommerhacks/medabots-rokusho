	.syntax unified

	thumb_func_start sub_080270BC
sub_080270BC: @ 0x080270BC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _08027178 @ =0x084DB788
	ldr r1, _0802717C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08027180 @ =0x0850EB38
	ldr r1, _08027184 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08027188 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r0, #0
	mov r8, r0
	ldr r0, _0802718C @ =0x0000C624
	strh r0, [r2]
	ldr r2, _08027190 @ =0x0000085C
	adds r0, r1, r2
	mov r2, r8
	strb r2, [r0]
	ldr r2, _08027194 @ =0x00000842
	adds r0, r1, r2
	movs r6, #0x78
	strh r6, [r0]
	ldr r0, _08027198 @ =0x00000844
	adds r2, r1, r0
	movs r0, #0x30
	strh r0, [r2]
	ldr r2, _0802719C @ =0x00000848
	adds r0, r1, r2
	movs r3, #0x80
	strb r3, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r1, r2
	movs r5, #7
	strb r5, [r0]
	adds r2, #1
	adds r0, r1, r2
	movs r4, #0xf0
	strb r4, [r0]
	ldr r0, _080271A0 @ =0x00000846
	adds r2, r1, r0
	movs r0, #0xca
	lsls r0, r0, #7
	strh r0, [r2]
	movs r0, #0x88
	lsls r0, r0, #4
	adds r2, r1, r0
	ldr r0, _080271A4 @ =0x00004624
	strh r0, [r2]
	ldr r2, _080271A8 @ =0x0000089C
	adds r0, r1, r2
	mov r2, r8
	strb r2, [r0]
	ldr r2, _080271AC @ =0x00000882
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, _080271B0 @ =0x00000884
	adds r2, r1, r0
	movs r0, #0x50
	strh r0, [r2]
	ldr r2, _080271B4 @ =0x00000888
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r4, [r0]
	ldr r0, _080271B8 @ =0x00000886
	adds r1, r1, r0
	ldr r0, _080271BC @ =0x00006501
	strh r0, [r1]
	ldr r1, _080271C0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08027178: .4byte 0x084DB788
_0802717C: .4byte 0x06014800
_08027180: .4byte 0x0850EB38
_08027184: .4byte 0x050002E0
_08027188: .4byte 0x03002C30
_0802718C: .4byte 0x0000C624
_08027190: .4byte 0x0000085C
_08027194: .4byte 0x00000842
_08027198: .4byte 0x00000844
_0802719C: .4byte 0x00000848
_080271A0: .4byte 0x00000846
_080271A4: .4byte 0x00004624
_080271A8: .4byte 0x0000089C
_080271AC: .4byte 0x00000882
_080271B0: .4byte 0x00000884
_080271B4: .4byte 0x00000888
_080271B8: .4byte 0x00000886
_080271BC: .4byte 0x00006501
_080271C0: .4byte 0x03001800
	.syntax divided
