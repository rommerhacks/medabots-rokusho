	.syntax unified

	thumb_func_start sub_08020288
sub_08020288: @ 0x08020288
	push {lr}
	ldr r0, _080202C4 @ =0x084CA428
	ldr r1, _080202C8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _080202CC @ =0x0850E178
	ldr r1, _080202D0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080202D4 @ =0x03002C30
	ldr r2, _080202D8 @ =0x000002AB
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	strb r2, [r0]
	movs r0, #0x2f
	bl play_sound_effect
	ldr r1, _080202DC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080202C4: .4byte 0x084CA428
_080202C8: .4byte 0x06010000
_080202CC: .4byte 0x0850E178
_080202D0: .4byte 0x050003C0
_080202D4: .4byte 0x03002C30
_080202D8: .4byte 0x000002AB
_080202DC: .4byte 0x03001800
	.syntax divided
