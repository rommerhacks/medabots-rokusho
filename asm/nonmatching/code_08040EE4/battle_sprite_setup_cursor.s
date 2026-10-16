	.syntax unified

	thumb_func_start battle_sprite_setup_cursor
battle_sprite_setup_cursor: @ 0x08041920
	push {r4, r5, lr}
	ldr r3, _080419BC @ =0x03002C30
	ldr r5, _080419C0 @ =0x03000440
	movs r0, #0x2b
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r4, #0
	ldr r1, _080419C4 @ =0x0000D204
	strh r1, [r0]
	mov r0, ip
	ldrb r1, [r0]
	lsls r1, r1, #6
	adds r1, r1, r3
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #0x14
	strh r0, [r1, #2]
	mov r1, ip
	ldrb r2, [r1]
	lsls r2, r2, #6
	adds r2, r2, r3
	adds r0, r5, #0
	adds r0, #0x2d
	ldrb r1, [r0]
	lsls r1, r1, #3
	subs r0, #3
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, #0x10
	strh r1, [r2, #4]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	ldr r1, _080419C8 @ =0x00000307
	strh r1, [r0, #6]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0xe
	strb r1, [r0, #0xa]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	strb r4, [r0, #0x1c]
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r2, #1
	strb r2, [r0, #8]
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	strb r2, [r0, #9]
	ldrb r0, [r1]
	lsls r0, r0, #6
	adds r0, r0, r3
	movs r1, #0xff
	strb r1, [r0, #0xb]
	adds r0, r5, #0
	adds r0, #0x84
	strb r2, [r0]
	adds r1, r5, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080419BC: .4byte 0x03002C30
_080419C0: .4byte 0x03000440
_080419C4: .4byte 0x0000D204
_080419C8: .4byte 0x00000307
	.syntax divided
