	.syntax unified

	thumb_func_start sub_08035C3C
	.global sub_08035C3C
sub_08035C3C: @ 0x08035C3C
	ldr r0, _08035C54 @ =0x03001800
	adds r0, #0xf8
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _08035C5C
	ldr r0, _08035C58 @ =0x0300057C
	movs r1, #0x88
	lsls r1, r1, #1
	b _08035C5E
	.align 2, 0
_08035C54: .4byte 0x03001800
_08035C58: .4byte 0x0300057C
_08035C5C:
	ldr r0, _08035C68 @ =0x0300057C
_08035C5E:
	strh r1, [r0]
	ldr r0, _08035C6C @ =0x03001C04
	strh r1, [r0]
	bx lr
	.align 2, 0
_08035C68: .4byte 0x0300057C
_08035C6C: .4byte 0x03001C04
	.syntax divided
