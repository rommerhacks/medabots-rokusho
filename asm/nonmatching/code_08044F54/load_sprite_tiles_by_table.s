	.syntax unified

	thumb_func_start load_sprite_tiles_by_table
load_sprite_tiles_by_table: @ 0x08046034
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	ldr r1, [sp, #0x10]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r1, r3, #2
	adds r1, r1, r0
	ldr r5, [r1]
	cmp r2, #0
	beq _080460A8
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	beq _080460A8
	lsls r0, r4, #4
	adds r4, r0, r6
_0804605A:
	ldr r1, [r2]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1a
	cmp r3, r0
	bne _0804609C
	lsls r0, r1, #0x12
	lsrs r0, r0, #0x18
	ldr r1, [r5]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _08046094 @ =0x02030800
	bl dma3_copy_or_decompress
	cmp r0, #0
	beq _080460A8
	ldrh r1, [r4, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	ldr r2, _08046098 @ =0x06010000
	adds r1, r1, r2
	lsrs r2, r0, #0x1f
	adds r2, r0, r2
	lsls r2, r2, #0xa
	lsrs r2, r2, #0xb
	ldr r0, _08046094 @ =0x02030800
	bl CpuSet
	b _080460A8
	.align 2, 0
_08046094: .4byte 0x02030800
_08046098: .4byte 0x06010000
_0804609C:
	adds r2, #4
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _0804605A
_080460A8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
