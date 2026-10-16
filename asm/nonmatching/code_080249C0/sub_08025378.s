	.syntax unified

	thumb_func_start sub_08025378
sub_08025378: @ 0x08025378
	push {r4, r5, lr}
	movs r0, #0x21
	bl sub_08037424
	ldr r2, _08025470 @ =0x03002C30
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _08025474 @ =0x0000C604
	strh r0, [r1]
	ldr r1, _08025478 @ =0x0000089C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _0802547C @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _08025480 @ =0x00000882
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08025484 @ =0x00000884
	adds r1, r2, r3
	strh r0, [r1]
	adds r5, #6
	adds r0, r2, r5
	movs r1, #1
	strb r1, [r0]
	adds r3, #5
	adds r0, r2, r3
	strb r1, [r0]
	adds r5, #2
	adds r1, r2, r5
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08025488 @ =0x0000088B
	adds r1, r2, r0
	movs r0, #0xe0
	strb r0, [r1]
	subs r3, #3
	adds r1, r2, r3
	ldr r0, _0802548C @ =0x00005001
	strh r0, [r1]
	movs r5, #0x87
	adds r5, r5, r4
	mov ip, r5
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	adds r3, #0x2a
	adds r0, r2, r3
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	ldr r5, _08025490 @ =0x000008A4
	adds r0, r2, r5
	movs r3, #3
	strb r3, [r0]
	mov r1, ip
	ldrb r0, [r1]
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
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r5, _08025494 @ =0x00000872
	adds r1, r2, r5
	strh r0, [r1]
	ldr r0, _08025498 @ =0x00000864
	adds r2, r2, r0
	strb r3, [r2]
	movs r0, #0x6f
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025470: .4byte 0x03002C30
_08025474: .4byte 0x0000C604
_08025478: .4byte 0x0000089C
_0802547C: .4byte 0x03001800
_08025480: .4byte 0x00000882
_08025484: .4byte 0x00000884
_08025488: .4byte 0x0000088B
_0802548C: .4byte 0x00005001
_08025490: .4byte 0x000008A4
_08025494: .4byte 0x00000872
_08025498: .4byte 0x00000864
	.syntax divided
