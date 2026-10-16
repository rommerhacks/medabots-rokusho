	.syntax unified

	thumb_func_start sub_08021A6C
sub_08021A6C: @ 0x08021A6C
	push {r4, lr}
	ldr r0, _08021ACC @ =0x083B5F80
	adds r0, #0xec
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r4, _08021AD0 @ =0x03003470
	adds r1, r4, #0
	adds r1, #0x40
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r1, r4, #0
	adds r1, #0x80
	adds r0, r4, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	movs r0, #0x58
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #6
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x72
	movs r0, #0x40
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x64
	strb r1, [r0]
	adds r2, #0x40
	movs r0, #0x28
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	ldr r0, _08021AD4 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021AD8
	movs r0, #0x88
	b _08021ADA
	.align 2, 0
_08021ACC: .4byte 0x083B5F80
_08021AD0: .4byte 0x03003470
_08021AD4: .4byte 0x03001800
_08021AD8:
	movs r0, #0x68
_08021ADA:
	strh r0, [r4, #0x30]
	adds r1, r4, #0
	adds r1, #0x70
	strh r0, [r1]
	adds r1, #0x40
	strh r0, [r1]
	ldr r1, _08021AF8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08021AF8: .4byte 0x03001800
	.syntax divided
