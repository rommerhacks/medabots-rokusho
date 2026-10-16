	.syntax unified

	thumb_func_start decompress_sprite_tiles_to_vram_obj_4800_alt
decompress_sprite_tiles_to_vram_obj_4800_alt: @ 0x080276E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov r8, r0
	ldr r0, _08027768 @ =0x084CDBD8
	ldr r1, _0802776C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08027770 @ =0x0850E378
	ldr r1, _08027774 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r4, #0
	ldr r5, _08027778 @ =0x03001800
	ldr r0, _0802777C @ =0x03002C30
	mov sl, r0
	movs r0, #0x60
	adds r0, r0, r5
	mov sb, r0
	movs r6, #0x21
_08027718:
	adds r7, r5, #0
	adds r7, #0xd2
	adds r0, r4, r7
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08027750
	mov r0, sb
	ldrb r2, [r0]
	adds r2, r2, r4
	lsls r2, r2, #2
	movs r0, #0x7f
	ands r0, r1
	adds r0, #0x5a
	adds r2, r2, r0
	lsls r2, r2, #6
	add r2, sl
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r0, #4
	ldrsh r2, [r2, r0]
	adds r0, r6, #0
	movs r3, #4
	bl setup_battle_cursor_sprite_08036FF8
	movs r0, #1
	mov r8, r0
_08027750:
	adds r6, #4
	adds r4, #1
	cmp r4, #2
	bls _08027718
	mov r0, r8
	cmp r0, #0
	bne _08027780
	adds r1, r7, #0
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	b _08027788
	.align 2, 0
_08027768: .4byte 0x084CDBD8
_0802776C: .4byte 0x06014800
_08027770: .4byte 0x0850E378
_08027774: .4byte 0x050002E0
_08027778: .4byte 0x03001800
_0802777C: .4byte 0x03002C30
_08027780:
	adds r1, r7, #0
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #3
_08027788:
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
