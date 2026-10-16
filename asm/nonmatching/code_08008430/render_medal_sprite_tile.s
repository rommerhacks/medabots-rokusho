	.syntax unified

	thumb_func_start render_medal_sprite_tile
	.global render_medal_sprite_tile
render_medal_sprite_tile: @ 0x08009484
	push {r4, r5, r6, lr}
	sub sp, #0xc
	movs r5, #0
	ldr r0, _080094CC @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x3f
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r1, r0, #1
	lsls r0, r0, #0x19
	lsrs r4, r0, #0x18
	adds r1, #6
	cmp r4, r1
	bge _08009504
	adds r6, r2, #0
_080094A4:
	ldr r1, _080094D0 @ =0x03000BE0
	lsls r0, r4, #6
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080094DC
	ldrb r0, [r2, #1]
	lsls r0, r0, #7
	ldr r1, _080094D4 @ =0x084C21BC
	adds r0, r0, r1
	lsls r1, r5, #7
	ldr r2, _080094D8 @ =0x06006600
	adds r1, r1, r2
	movs r2, #0x20
	bl CpuFastSet
	b _080094EA
	.align 2, 0
_080094CC: .4byte 0x03000440
_080094D0: .4byte 0x03000BE0
_080094D4: .4byte 0x084C21BC
_080094D8: .4byte 0x06006600
_080094DC:
	lsls r1, r5, #7
	ldr r0, _08009530 @ =0x06006600
	adds r1, r1, r0
	ldr r0, _08009534 @ =0x084C30BC
	movs r2, #0x20
	bl CpuFastSet
_080094EA:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #6
	cmp r4, r0
	blt _080094A4
_08009504:
	ldr r0, _08009538 @ =0x083B4AE0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _0800953C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0xc
	movs r2, #4
	movs r3, #4
	bl write_tilemap_rect
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08009530: .4byte 0x06006600
_08009534: .4byte 0x084C30BC
_08009538: .4byte 0x083B4AE0
_0800953C: .4byte 0x0400000A
	.syntax divided
