	.syntax unified

	thumb_func_start sub_08014C84
sub_08014C84: @ 0x08014C84
	push {r4, r5, lr}
	movs r5, #0
	ldr r0, _08014CBC @ =0x03000590
	ldr r1, _08014CC0 @ =0x000003DD
	adds r4, r0, r1
_08014C8E:
	adds r2, r5, #3
	ldrb r0, [r4]
	cmp r0, #3
	bls _08014CA0
	adds r1, r0, #0
	subs r1, #4
	adds r0, r2, #0
	bl load_bot_palette_data
_08014CA0:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	bls _08014C8E
	ldr r1, _08014CC4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08014CBC: .4byte 0x03000590
_08014CC0: .4byte 0x000003DD
_08014CC4: .4byte 0x0300137C
	.syntax divided
