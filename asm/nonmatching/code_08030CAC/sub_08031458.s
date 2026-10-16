	.syntax unified

	thumb_func_start sub_08031458
sub_08031458: @ 0x08031458
	push {r4, r5, lr}
	ldr r2, _080314EC @ =0x03002C30
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _080314F0 @ =0x0000C404
	strh r0, [r1]
	ldr r1, _080314F4 @ =0x0000089C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _080314F8 @ =0x03001800
	movs r5, #0x87
	adds r5, r5, r4
	mov ip, r5
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	subs r0, #0x10
	ldr r5, _080314FC @ =0x00000882
	adds r1, r2, r5
	strh r0, [r1]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	adds r0, #4
	ldr r5, _08031500 @ =0x00000884
	adds r1, r2, r5
	strh r0, [r1]
	ldr r1, _08031504 @ =0x083AED18
	movs r0, #0xb3
	lsls r0, r0, #1
	adds r0, r0, r4
	mov ip, r0
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r4, _08031508 @ =0x0000088A
	adds r0, r2, r4
	strb r1, [r0]
	adds r5, #7
	adds r1, r2, r5
	movs r0, #0x80
	strb r0, [r1]
	ldr r1, _0803150C @ =0x00005801
	adds r0, r1, #0
	mov r4, ip
	ldrb r4, [r4]
	adds r0, r0, r4
	subs r5, #5
	adds r1, r2, r5
	strh r0, [r1]
	ldr r0, _08031510 @ =0x000008A3
	adds r2, r2, r0
	strb r3, [r2]
	movs r0, #0x2a
	bl play_sound_effect
	ldr r1, _08031514 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080314EC: .4byte 0x03002C30
_080314F0: .4byte 0x0000C404
_080314F4: .4byte 0x0000089C
_080314F8: .4byte 0x03001800
_080314FC: .4byte 0x00000882
_08031500: .4byte 0x00000884
_08031504: .4byte 0x083AED18
_08031508: .4byte 0x0000088A
_0803150C: .4byte 0x00005801
_08031510: .4byte 0x000008A3
_08031514: .4byte 0x0300137C
	.syntax divided
