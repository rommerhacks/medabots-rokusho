	.syntax unified

	thumb_func_start sub_08002D48
sub_08002D48: @ 0x08002D48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r7, _08002DDC @ =0x03000440
	adds r4, r7, #0
	adds r4, #0x88
	ldrb r3, [r4]
	subs r3, #1
	ldr r2, _08002DE0 @ =0x083B4AE0
	movs r0, #0x8e
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #0x1f
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r6, _08002DE4 @ =0x04000008
	ldrh r0, [r6]
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	bl write_tilemap_rect
	ldrb r3, [r4]
	adds r3, #1
	ldrh r0, [r6]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0x12
	bl vram_fill_tilemap_rect
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _08002DD0
	ldr r0, _08002DE8 @ =0x084C1C14
	ldr r1, _08002DEC @ =0x060017E0
	bl lz_decompress_dispatch
	bl copy_obj_palette_to_buffer
	adds r0, r7, #0
	adds r0, #0x84
	strb r4, [r0]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _08002DC8
	movs r0, #0x10
	bl sound_stop_all_with_fade_guard
_08002DC8:
	ldr r1, _08002DF0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08002DD0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002DDC: .4byte 0x03000440
_08002DE0: .4byte 0x083B4AE0
_08002DE4: .4byte 0x04000008
_08002DE8: .4byte 0x084C1C14
_08002DEC: .4byte 0x060017E0
_08002DF0: .4byte 0x0300137C
	.syntax divided
