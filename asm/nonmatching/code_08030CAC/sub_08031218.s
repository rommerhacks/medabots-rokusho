	.syntax unified

	thumb_func_start sub_08031218
sub_08031218: @ 0x08031218
	push {lr}
	ldr r2, _08031234 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803123C
	ldr r0, _08031238 @ =0x03002B74
	adds r1, r2, #0
	adds r1, #0x9e
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	b _08031274
	.align 2, 0
_08031234: .4byte 0x03000440
_08031238: .4byte 0x03002B74
_0803123C:
	adds r0, r2, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _08031268
	ldr r1, _08031260 @ =0x083C3F38
	ldr r0, _08031264 @ =0x03001800
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0x9e
	movs r2, #0x12
	bl memcpy_bytes_0803F63C
	b _08031274
	.align 2, 0
_08031260: .4byte 0x083C3F38
_08031264: .4byte 0x03001800
_08031268:
	ldr r0, _0803128C @ =0x0300198A
	adds r1, r2, #0
	adds r1, #0x9e
	movs r2, #0x12
	bl memcpy_bytes_0803F63C
_08031274:
	ldr r0, _08031290 @ =0x083C65C4
	ldr r0, [r0, #0xc]
	bl run_message
	cmp r0, #0
	beq _08031288
	ldr r1, _08031294 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08031288:
	pop {r0}
	bx r0
	.align 2, 0
_0803128C: .4byte 0x0300198A
_08031290: .4byte 0x083C65C4
_08031294: .4byte 0x0300137C
	.syntax divided
