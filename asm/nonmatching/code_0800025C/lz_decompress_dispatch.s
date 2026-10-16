	.syntax unified

	thumb_func_start lz_decompress_dispatch
	.global lz_decompress_dispatch
lz_decompress_dispatch: @ 0x080009BC
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r3]
	cmp r0, #0x4c
	bne _080009CE
	ldrb r0, [r3, #1]
	cmp r0, #0x65
	beq _080009D2
_080009CE:
	movs r0, #0
	b _08000A04
_080009D2:
	ldr r0, _080009F4 @ =0xFBFFFFFF
	adds r1, r4, r0
	ldr r0, _080009F8 @ =0x03FFFFFE
	cmp r1, r0
	bls _080009FC
	ldrb r2, [r3, #2]
	ldrb r0, [r3, #3]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r3, #4]
	lsls r0, r0, #0x10
	orrs r2, r0
	adds r0, r3, #0
	adds r1, r4, #0
	bl lz_decompress_custom_08000A0C
	b _08000A04
	.align 2, 0
_080009F4: .4byte 0xFBFFFFFF
_080009F8: .4byte 0x03FFFFFE
_080009FC:
	adds r0, r3, #0
	adds r1, r4, #0
	bl lz_decompress_custom_08000B14
_08000A04:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
