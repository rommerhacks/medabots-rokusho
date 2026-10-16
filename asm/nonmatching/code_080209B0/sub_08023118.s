	.syntax unified

	thumb_func_start sub_08023118
sub_08023118: @ 0x08023118
	push {r4, r5, r6, lr}
	ldr r2, _080231AC @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	movs r5, #0
	ldr r0, _080231B0 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _080231B4 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _080231B8 @ =0x03001800
	movs r6, #0x87
	adds r6, r6, r4
	mov ip, r6
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r6, _080231BC @ =0x00000842
	adds r0, r2, r6
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r6, _080231C0 @ =0x00000844
	adds r1, r2, r6
	strh r0, [r1]
	ldr r0, _080231C4 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #6
	strb r0, [r1]
	adds r6, #7
	adds r1, r2, r6
	movs r0, #0xf0
	strb r0, [r1]
	ldr r0, _080231C8 @ =0x00000846
	adds r1, r2, r0
	movs r0, #0x90
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r1, _080231CC @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	subs r6, #2
	adds r0, r2, r6
	strb r1, [r0]
	ldr r1, _080231D0 @ =0x00000858
	adds r0, r2, r1
	strh r5, [r0]
	adds r6, #0x24
	adds r2, r2, r6
	strb r3, [r2]
	movs r0, #0x4c
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080231AC: .4byte 0x03002C30
_080231B0: .4byte 0x0000C604
_080231B4: .4byte 0x0000085C
_080231B8: .4byte 0x03001800
_080231BC: .4byte 0x00000842
_080231C0: .4byte 0x00000844
_080231C4: .4byte 0x0000084A
_080231C8: .4byte 0x00000846
_080231CC: .4byte 0x00000848
_080231D0: .4byte 0x00000858
	.syntax divided
