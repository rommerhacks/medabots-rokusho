	.syntax unified

	thumb_func_start sub_0803C9E0
sub_0803C9E0: @ 0x0803C9E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r4, _0803CA00 @ =0x03002C30
	ldr r7, _0803CA04 @ =0x03000440
	ldr r0, _0803CA08 @ =0x0000012F
	adds r5, r7, r0
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r2, r0, r4
	ldrh r0, [r2, #0x30]
	adds r6, r0, #0
	cmp r6, #0
	beq _0803CA0C
	subs r0, #1
	strh r0, [r2, #0x30]
	b _0803CAA0
	.align 2, 0
_0803CA00: .4byte 0x03002C30
_0803CA04: .4byte 0x03000440
_0803CA08: .4byte 0x0000012F
_0803CA0C:
	ldr r1, _0803CA5C @ =0x083CEC74
	adds r0, r2, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	bl process_animation_script
	adds r0, r7, #0
	adds r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0803CA64
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r3, r0, r4
	adds r0, r3, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	movs r4, #2
	ldrsh r2, [r3, r4]
	movs r4, #4
	ldrsh r3, [r3, r4]
	ldr r4, _0803CA60 @ =0x04000008
	ldrh r4, [r4]
	str r4, [sp]
	str r6, [sp, #4]
	bl tilemap_fill_rect
	ldrb r0, [r5]
	movs r1, #1
	bl clear_battle_sprite_slot
	b _0803CAA0
	.align 2, 0
_0803CA5C: .4byte 0x083CEC74
_0803CA60: .4byte 0x04000008
_0803CA64:
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r6, [r0]
	cmp r6, #0
	bne _0803CAA0
	adds r0, #1
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x2f
	ldrb r1, [r1]
	movs r5, #2
	ldrsh r2, [r4, r5]
	movs r5, #4
	ldrsh r3, [r4, r5]
	ldr r5, _0803CAA8 @ =0x083B4AE0
	adds r4, #0x2c
	ldrb r4, [r4]
	lsls r4, r4, #2
	adds r4, r4, r5
	ldr r4, [r4]
	str r4, [sp]
	ldr r4, _0803CAAC @ =0x04000008
	ldrh r4, [r4]
	str r4, [sp, #4]
	str r6, [sp, #8]
	bl write_tilemap_to_vram_0803F1C8
_0803CAA0:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CAA8: .4byte 0x083B4AE0
_0803CAAC: .4byte 0x04000008
	.syntax divided
