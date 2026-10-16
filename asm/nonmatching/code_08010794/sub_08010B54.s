	.syntax unified

	thumb_func_start sub_08010B54
sub_08010B54: @ 0x08010B54
	push {r4, r5, lr}
	ldr r4, _08010B7C @ =0x03002B84
	ldr r5, _08010B80 @ =0x0000270F
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0801BF64
	ldr r0, _08010B84 @ =0x03000440
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _08010B88
	adds r0, r4, #2
	adds r1, r5, #0
	bl sub_0801BF64
	movs r0, #0xe
	bl play_song
	b _08010B8E
	.align 2, 0
_08010B7C: .4byte 0x03002B84
_08010B80: .4byte 0x0000270F
_08010B84: .4byte 0x03000440
_08010B88:
	movs r0, #0xf
	bl play_song
_08010B8E:
	ldr r1, _08010B9C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010B9C: .4byte 0x0300137C
	.syntax divided
