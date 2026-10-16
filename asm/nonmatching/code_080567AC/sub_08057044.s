	.syntax unified

	thumb_func_start sub_08057044
sub_08057044: @ 0x08057044
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x14
	ldr r0, _0805710C @ =0x030064A0
	ldr r1, _08057110 @ =0x00000874
	bl sub_080496C8
	ldr r0, _08057114 @ =0x085FA144
	ldr r1, _08057118 @ =0x06000F80
	bl LZ77UnCompVram
	ldr r0, _0805711C @ =0x085FA5D8
	ldr r1, _08057120 @ =0x06002100
	bl LZ77UnCompVram
	ldr r0, _08057124 @ =0x03006D14
	mov sb, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r2, _08057128 @ =0x040000D4
	ldr r0, _0805712C @ =0x085FA4D8
	str r0, [r2]
	mov r3, sb
	ldr r1, [r3]
	str r1, [r2, #4]
	ldr r0, _08057130 @ =0x80000070
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _08057134 @ =0x085FA620
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r1, r3
	str r0, [r2, #4]
	ldr r0, _08057138 @ =0x80000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0805713C @ =0x083D5F30
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r1, r5
	movs r2, #0x10
	str r2, [sp]
	movs r2, #0xa
	mov r8, r2
	str r2, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r6, #0xf
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl copy_tilemap_region
	mov r3, sb
	ldr r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	mov r2, r8
	str r2, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #2
	movs r2, #0xe
	movs r3, #0x10
	bl fill_tilemap_rect_0804916C
	mov r3, sb
	ldr r0, [r3]
	adds r5, r0, r5
	movs r2, #0xe
	str r2, [sp]
	movs r1, #8
	str r1, [sp, #4]
	movs r1, #0x7c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r4, [sp, #0x10]
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl copy_tilemap_region
	movs r0, #0
	bl check_vehicle_usability
	cmp r0, #0
	beq _08057144
	cmp r0, #1
	beq _08057158
	ldr r0, _08057140 @ =0x085FA87C
	b _08057146
	.align 2, 0
_0805710C: .4byte 0x030064A0
_08057110: .4byte 0x00000874
_08057114: .4byte 0x085FA144
_08057118: .4byte 0x06000F80
_0805711C: .4byte 0x085FA5D8
_08057120: .4byte 0x06002100
_08057124: .4byte 0x03006D14
_08057128: .4byte 0x040000D4
_0805712C: .4byte 0x085FA4D8
_08057130: .4byte 0x80000070
_08057134: .4byte 0x085FA620
_08057138: .4byte 0x80000010
_0805713C: .4byte 0x083D5F30
_08057140: .4byte 0x085FA87C
_08057144:
	ldr r0, _08057150 @ =0x085FA660
_08057146:
	ldr r1, _08057154 @ =0x06016F80
	bl LZ77UnCompVram
	b _08057166
	.align 2, 0
_08057150: .4byte 0x085FA660
_08057154: .4byte 0x06016F80
_08057158:
	ldr r0, _08057178 @ =0x085FAA98
	ldr r1, _0805717C @ =0x06016F80
	bl LZ77UnCompVram
	movs r0, #0
	bl render_npc_tilemap_row
_08057166:
	movs r0, #1
	bl check_vehicle_usability
	cmp r0, #0
	beq _08057184
	cmp r0, #1
	beq _08057198
	ldr r0, _08057180 @ =0x085FA904
	b _08057186
	.align 2, 0
_08057178: .4byte 0x085FAA98
_0805717C: .4byte 0x06016F80
_08057180: .4byte 0x085FA904
_08057184:
	ldr r0, _08057190 @ =0x085FA6E8
_08057186:
	ldr r1, _08057194 @ =0x06017000
	bl LZ77UnCompVram
	b _080571A6
	.align 2, 0
_08057190: .4byte 0x085FA6E8
_08057194: .4byte 0x06017000
_08057198:
	ldr r0, _080571B8 @ =0x085FAA98
	ldr r1, _080571BC @ =0x06017000
	bl LZ77UnCompVram
	movs r0, #1
	bl render_npc_tilemap_row
_080571A6:
	movs r0, #2
	bl check_vehicle_usability
	cmp r0, #0
	beq _080571C4
	cmp r0, #1
	beq _080571D8
	ldr r0, _080571C0 @ =0x085FA990
	b _080571C6
	.align 2, 0
_080571B8: .4byte 0x085FAA98
_080571BC: .4byte 0x06017000
_080571C0: .4byte 0x085FA990
_080571C4:
	ldr r0, _080571D0 @ =0x085FA774
_080571C6:
	ldr r1, _080571D4 @ =0x06017080
	bl LZ77UnCompVram
	b _080571E6
	.align 2, 0
_080571D0: .4byte 0x085FA774
_080571D4: .4byte 0x06017080
_080571D8:
	ldr r0, _080571F8 @ =0x085FAA98
	ldr r1, _080571FC @ =0x06017080
	bl LZ77UnCompVram
	movs r0, #2
	bl render_npc_tilemap_row
_080571E6:
	movs r0, #3
	bl check_vehicle_usability
	cmp r0, #0
	beq _08057204
	cmp r0, #1
	beq _08057218
	ldr r0, _08057200 @ =0x085FAA18
	b _08057206
	.align 2, 0
_080571F8: .4byte 0x085FAA98
_080571FC: .4byte 0x06017080
_08057200: .4byte 0x085FAA18
_08057204:
	ldr r0, _08057210 @ =0x085FA7FC
_08057206:
	ldr r1, _08057214 @ =0x06017100
	bl LZ77UnCompVram
	b _08057226
	.align 2, 0
_08057210: .4byte 0x085FA7FC
_08057214: .4byte 0x06017100
_08057218:
	ldr r0, _080572AC @ =0x085FAA98
	ldr r1, _080572B0 @ =0x06017100
	bl LZ77UnCompVram
	movs r0, #3
	bl render_npc_tilemap_row
_08057226:
	ldr r4, _080572B4 @ =0x040000D4
	ldr r0, _080572B8 @ =0x085FA640
	str r0, [r4]
	ldr r0, _080572BC @ =0x05000380
	str r0, [r4, #4]
	ldr r5, _080572C0 @ =0x84000008
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080572C4 @ =0x085FA85C
	str r0, [r4]
	ldr r0, _080572C8 @ =0x050003A0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl decompress_bg_tiles_to_vram_bg
	ldr r0, _080572CC @ =0x084C6998
	str r0, [r4]
	ldr r0, _080572D0 @ =0x050001C0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080572D4 @ =0x084878EC
	ldr r1, _080572D8 @ =0x06002600
	bl lz_decompress_dispatch
	ldr r0, _080572DC @ =0x0848796C
	ldr r1, _080572E0 @ =0x060026E0
	bl lz_decompress_dispatch
	ldr r0, _080572E4 @ =0x084C7318
	ldr r1, _080572E8 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r0, _080572EC @ =0x084E2E58
	str r0, [r4]
	ldr r0, _080572F0 @ =0x050003C0
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _080572F4 @ =0x030064A0
	adds r2, r0, #0
	adds r2, #0x66
	movs r1, #0
	strb r1, [r2]
	adds r2, #1
	strb r1, [r2]
	adds r2, #8
	strb r1, [r2]
	subs r2, #3
	adds r3, r0, #0
	adds r3, #0x6d
	adds r0, #0x6e
	strb r1, [r0]
	movs r0, #0x10
	strb r0, [r2]
	movs r0, #3
	strb r0, [r3]
	bl sub_0804A1C4
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080572AC: .4byte 0x085FAA98
_080572B0: .4byte 0x06017100
_080572B4: .4byte 0x040000D4
_080572B8: .4byte 0x085FA640
_080572BC: .4byte 0x05000380
_080572C0: .4byte 0x84000008
_080572C4: .4byte 0x085FA85C
_080572C8: .4byte 0x050003A0
_080572CC: .4byte 0x084C6998
_080572D0: .4byte 0x050001C0
_080572D4: .4byte 0x084878EC
_080572D8: .4byte 0x06002600
_080572DC: .4byte 0x0848796C
_080572E0: .4byte 0x060026E0
_080572E4: .4byte 0x084C7318
_080572E8: .4byte 0x06017E00
_080572EC: .4byte 0x084E2E58
_080572F0: .4byte 0x050003C0
_080572F4: .4byte 0x030064A0
	.syntax divided
