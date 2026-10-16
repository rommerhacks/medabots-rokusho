	.syntax unified

	thumb_func_start sub_080310A0
sub_080310A0: @ 0x080310A0
	push {lr}
	ldr r2, _080310BC @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _080310C4
	ldr r0, _080310C0 @ =0x03002B74
	adds r1, r2, #0
	adds r1, #0x9e
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	b _080310FC
	.align 2, 0
_080310BC: .4byte 0x03000440
_080310C0: .4byte 0x03002B74
_080310C4:
	adds r0, r2, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _080310F0
	ldr r1, _080310E8 @ =0x083C3F38
	ldr r0, _080310EC @ =0x03001800
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0x9e
	movs r2, #0x12
	bl memcpy_bytes_0803F63C
	b _080310FC
	.align 2, 0
_080310E8: .4byte 0x083C3F38
_080310EC: .4byte 0x03001800
_080310F0:
	ldr r0, _08031114 @ =0x0300198A
	adds r1, r2, #0
	adds r1, #0x9e
	movs r2, #0x12
	bl memcpy_bytes_0803F63C
_080310FC:
	ldr r0, _08031118 @ =0x083C65C4
	ldr r0, [r0, #8]
	bl run_message
	cmp r0, #0
	beq _08031110
	ldr r1, _0803111C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08031110:
	pop {r0}
	bx r0
	.align 2, 0
_08031114: .4byte 0x0300198A
_08031118: .4byte 0x083C65C4
_0803111C: .4byte 0x0300137C
	.syntax divided
