	.syntax unified

	thumb_func_start sub_08013288
sub_08013288: @ 0x08013288
	push {r4, r5, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r4, _08013314 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r4, _08013318 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r1]
	movs r5, #0
	adds r0, #2
	strb r0, [r1]
	bl sub_080168F4
	bl sub_08016C0C
	adds r4, #0x86
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _0801330C
	movs r0, #0
	movs r1, #0x46
	bl clear_battle_sprite_slot
	ldr r0, _0801331C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _08013320 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _08013324 @ =0x084E2F38
	ldr r1, _08013328 @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0801332C @ =0x0300137C
	movs r0, #0xd
	str r0, [r1]
_0801330C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013314: .4byte 0x03001800
_08013318: .4byte 0x03000440
_0801331C: .4byte 0x04000008
_08013320: .4byte 0x0400000A
_08013324: .4byte 0x084E2F38
_08013328: .4byte 0x05000340
_0801332C: .4byte 0x0300137C
	.syntax divided
