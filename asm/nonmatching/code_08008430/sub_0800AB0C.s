	.syntax unified

	thumb_func_start sub_0800AB0C
	.global sub_0800AB0C
sub_0800AB0C: @ 0x0800AB0C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	movs r4, #0
	ldr r5, _0800AB50 @ =0x03000BE0
	ldr r7, _0800AB54 @ =0x0300047D
	movs r6, #6
_0800AB18:
	ldrb r0, [r7]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrb r0, [r0, #9]
	cmp r4, r0
	bhs _0800AB60
	ldr r0, _0800AB58 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldrb r0, [r7]
	lsls r0, r0, #6
	adds r0, r4, r0
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r1, _0800AB5C @ =0xB3400000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r6, #0
	movs r3, #7
	bl fill_tilemap_rect_08042698
	b _0800AB8A
	.align 2, 0
_0800AB50: .4byte 0x03000BE0
_0800AB54: .4byte 0x0300047D
_0800AB58: .4byte 0x0400000A
_0800AB5C: .4byte 0xB3400000
_0800AB60:
	ldr r0, _0800AB9C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldrb r0, [r7]
	lsls r0, r0, #6
	adds r0, r4, r0
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r1, _0800ABA0 @ =0xA3400000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	adds r2, r6, #0
	movs r3, #7
	bl fill_tilemap_rect_08042698
_0800AB8A:
	adds r6, #2
	adds r4, #1
	cmp r4, #7
	bls _0800AB18
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800AB9C: .4byte 0x0400000A
_0800ABA0: .4byte 0xA3400000
	.syntax divided
