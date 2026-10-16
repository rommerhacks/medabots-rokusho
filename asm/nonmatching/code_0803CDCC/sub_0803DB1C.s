	.syntax unified

	thumb_func_start sub_0803DB1C
sub_0803DB1C: @ 0x0803DB1C
	push {lr}
	ldr r0, _0803DB30 @ =0x03000440
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803DB34
	movs r0, #0xe
	bl play_song
	b _0803DB3A
	.align 2, 0
_0803DB30: .4byte 0x03000440
_0803DB34:
	movs r0, #0xf
	bl play_song
_0803DB3A:
	ldr r1, _0803DB48 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803DB48: .4byte 0x0300137C
	.syntax divided
