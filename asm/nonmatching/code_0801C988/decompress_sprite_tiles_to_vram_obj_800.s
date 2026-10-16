	.syntax unified

	thumb_func_start decompress_sprite_tiles_to_vram_obj_800
decompress_sprite_tiles_to_vram_obj_800: @ 0x0801F214
	push {r4, lr}
	sub sp, #4
	ldr r0, _0801F240 @ =0x084CDCD4
	ldr r1, _0801F244 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801F248 @ =0x0850E398
	ldr r1, _0801F24C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r3, _0801F250 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801F254
	movs r1, #0xac
	lsls r1, r1, #1
	b _0801F258
	.align 2, 0
_0801F240: .4byte 0x084CDCD4
_0801F244: .4byte 0x06010800
_0801F248: .4byte 0x0850E398
_0801F24C: .4byte 0x050003C0
_0801F250: .4byte 0x03001800
_0801F254:
	movs r1, #0xaa
	lsls r1, r1, #1
_0801F258:
	adds r0, r3, r1
	ldrh r2, [r0]
	adds r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	ldr r4, _0801F28C @ =0x03001800
	adds r1, r4, #0
	adds r1, #0x8b
	ldrb r1, [r1]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r0, #0x10
	asrs r3, r3, #0x10
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0xa
	bl sub_08036C20
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801F28C: .4byte 0x03001800
	.syntax divided
