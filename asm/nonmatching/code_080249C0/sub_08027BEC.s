	.syntax unified

	thumb_func_start sub_08027BEC
sub_08027BEC: @ 0x08027BEC
	push {r4, r5, lr}
	ldr r1, _08027C84 @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	movs r4, #0
	strh r0, [r1]
	ldr r2, _08027C88 @ =0x03002C30
	ldr r0, _08027C8C @ =0x00000858
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r0, #0x40
	ldr r5, _08027C90 @ =0x000003FF
	adds r1, r5, #0
	ands r0, r1
	strh r0, [r3]
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r2, r0
	ldr r0, _08027C94 @ =0x0000C624
	strh r0, [r1]
	ldr r1, _08027C98 @ =0x0000089C
	adds r0, r2, r1
	strb r4, [r0]
	ldr r3, _08027C9C @ =0x03001800
	adds r4, r3, #0
	adds r4, #0x87
	ldrb r0, [r4]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _08027CA0 @ =0x00000882
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
	ldr r4, _08027CA4 @ =0x00000884
	adds r1, r2, r4
	strh r0, [r1]
	adds r5, #6
	adds r0, r2, r5
	movs r1, #0x80
	strb r1, [r0]
	adds r4, #5
	adds r0, r2, r4
	strb r1, [r0]
	adds r5, #2
	adds r1, r2, r5
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08027CA8 @ =0x0000088B
	adds r1, r2, r0
	movs r0, #0xf1
	strb r0, [r1]
	ldr r1, _08027CAC @ =0x00000886
	adds r2, r2, r1
	movs r0, #0xce
	lsls r0, r0, #7
	strh r0, [r2]
	adds r3, #0xaa
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08027C84: .4byte 0x03000440
_08027C88: .4byte 0x03002C30
_08027C8C: .4byte 0x00000858
_08027C90: .4byte 0x000003FF
_08027C94: .4byte 0x0000C624
_08027C98: .4byte 0x0000089C
_08027C9C: .4byte 0x03001800
_08027CA0: .4byte 0x00000882
_08027CA4: .4byte 0x00000884
_08027CA8: .4byte 0x0000088B
_08027CAC: .4byte 0x00000886
	.syntax divided
