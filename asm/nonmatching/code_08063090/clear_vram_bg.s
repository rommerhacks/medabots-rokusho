	.syntax unified

	thumb_func_start clear_vram_bg
clear_vram_bg: @ 0x08065BB0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	movs r0, #0
	mov r8, r0
	str r0, [sp, #4]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08065CE4 @ =0x01006000
	add r0, sp, #4
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_080415BC
	movs r5, #0x80
	lsls r5, r5, #0x13
	movs r0, #0x60
	strh r0, [r5]
	ldr r1, _08065CE8 @ =0x0400000A
	ldr r2, _08065CEC @ =0x00001E05
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _08065CF0 @ =0x0400000C
	subs r2, #0xff
	adds r0, r2, #0
	strh r0, [r4]
	ldr r6, _08065CF4 @ =0x0400000E
	ldr r2, _08065CF8 @ =0x00003C07
	adds r0, r2, #0
	strh r0, [r6]
	ldr r0, _08065CFC @ =0x0879C06C
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _08065D00 @ =0x0879C260
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08065D04 @ =0x0879C3A0
	ldrh r1, [r6]
	bl decompress_and_write_tilemap
	ldr r0, _08065D08 @ =0x0879AC40
	ldr r4, _08065D0C @ =0x02030000
	adds r1, r4, #0
	bl dma3_copy_or_decompress
	adds r2, r0, #0
	ldr r1, _08065D10 @ =0x06004000
	lsls r2, r2, #0xa
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuSet
	ldr r0, _08065D14 @ =0x0879AA40
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _08065D18 @ =0x084E2E58
	ldr r1, _08065D1C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08065D20 @ =0x08784DA4
	ldr r1, _08065D24 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _08065D28 @ =0x0850DEB8
	ldr r1, _08065D2C @ =0x05000200
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08065D30 @ =0x03002C30
	movs r6, #0
	movs r0, #0x80
	lsls r0, r0, #8
	strh r0, [r1]
	movs r0, #2
	strb r0, [r1, #0x1c]
	movs r0, #0xe
	strb r0, [r1, #0xa]
	movs r0, #6
	strh r0, [r1, #6]
	movs r0, #0xc
	strh r0, [r1, #2]
	movs r0, #0x1c
	strh r0, [r1, #4]
	ldr r4, _08065D34 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0x10
	movs r2, #0
	bl init_blend_effect
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r5]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r0, [r4]
	mov r1, r8
	strh r1, [r0, #0x3a]
	strb r6, [r0, #5]
	ldr r0, [r4]
	adds r0, #0x7a
	movs r1, #0xff
	strb r1, [r0]
	bl sub_08074B68
	cmp r0, #0x18
	beq _08065CD0
	movs r0, #0x18
	bl play_song
_08065CD0:
	ldr r1, _08065D38 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08065CE4: .4byte 0x01006000
_08065CE8: .4byte 0x0400000A
_08065CEC: .4byte 0x00001E05
_08065CF0: .4byte 0x0400000C
_08065CF4: .4byte 0x0400000E
_08065CF8: .4byte 0x00003C07
_08065CFC: .4byte 0x0879C06C
_08065D00: .4byte 0x0879C260
_08065D04: .4byte 0x0879C3A0
_08065D08: .4byte 0x0879AC40
_08065D0C: .4byte 0x02030000
_08065D10: .4byte 0x06004000
_08065D14: .4byte 0x0879AA40
_08065D18: .4byte 0x084E2E58
_08065D1C: .4byte 0x050003C0
_08065D20: .4byte 0x08784DA4
_08065D24: .4byte 0x06010000
_08065D28: .4byte 0x0850DEB8
_08065D2C: .4byte 0x05000200
_08065D30: .4byte 0x03002C30
_08065D34: .4byte 0x03006F74
_08065D38: .4byte 0x0300137C
	.syntax divided
