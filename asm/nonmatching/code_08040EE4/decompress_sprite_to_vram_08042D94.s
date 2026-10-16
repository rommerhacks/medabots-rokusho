	.syntax unified

	thumb_func_start decompress_sprite_to_vram_08042D94
	.global decompress_sprite_to_vram_08042D94
decompress_sprite_to_vram_08042D94: @ 0x08042D94
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r5, r1, #0
	mov r8, r2
	mov sl, r3
	ldr r6, [sp, #0x1c]
	ldr r1, _08042E3C @ =0x083B1888
	mov sb, r1
	lsls r1, r0, #2
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	add r1, sb
	ldr r0, [r1]
	lsls r6, r6, #0xa
	ldr r2, _08042E40 @ =0x06010000
	adds r1, r6, r2
	bl lz_decompress_dispatch
	lsls r4, r5, #2
	lsls r5, r5, #1
	adds r4, r4, r5
	adds r0, r4, #1
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r2, _08042E44 @ =0x06010080
	adds r1, r6, r2
	bl lz_decompress_dispatch
	adds r4, #2
	lsls r4, r4, #2
	add r4, sb
	ldr r0, [r4]
	ldr r2, _08042E48 @ =0x06010100
	adds r1, r6, r2
	bl lz_decompress_dispatch
	mov r0, r8
	lsls r4, r0, #2
	lsls r0, r0, #1
	mov r8, r0
	add r4, r8
	adds r0, r4, #3
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r2, _08042E4C @ =0x06010180
	adds r1, r6, r2
	bl lz_decompress_dispatch
	adds r4, #4
	lsls r4, r4, #2
	add r4, sb
	ldr r0, [r4]
	ldr r2, _08042E50 @ =0x06010200
	adds r1, r6, r2
	bl lz_decompress_dispatch
	mov r1, sl
	lsls r0, r1, #2
	lsls r1, r1, #1
	mov sl, r1
	add r0, sl
	adds r0, #5
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	ldr r2, _08042E54 @ =0x06010280
	adds r6, r6, r2
	adds r1, r6, #0
	bl lz_decompress_dispatch
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08042E3C: .4byte 0x083B1888
_08042E40: .4byte 0x06010000
_08042E44: .4byte 0x06010080
_08042E48: .4byte 0x06010100
_08042E4C: .4byte 0x06010180
_08042E50: .4byte 0x06010200
_08042E54: .4byte 0x06010280
	.syntax divided
