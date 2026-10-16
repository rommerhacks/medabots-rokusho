	.syntax unified

	thumb_func_start sub_08005BB4
	.global sub_08005BB4
sub_08005BB4: @ 0x08005BB4
	push {lr}
	sub sp, #4
	ldr r0, _08005BE0 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x97
	ldrb r0, [r2]
	cmp r0, #0x1d
	bhi _08005BF0
	ldr r1, _08005BE4 @ =0x03000BE0
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	ldr r1, _08005BE8 @ =0x0400000A
	ldrh r3, [r1]
	ldr r1, _08005BEC @ =0x0000D3A4
	str r1, [sp]
	movs r1, #0x1a
	movs r2, #9
	bl fill_tilemap_pair_or_divide
	b _08005C02
	.align 2, 0
_08005BE0: .4byte 0x03000440
_08005BE4: .4byte 0x03000BE0
_08005BE8: .4byte 0x0400000A
_08005BEC: .4byte 0x0000D3A4
_08005BF0:
	ldr r0, _08005C08 @ =0x0400000A
	ldrh r3, [r0]
	ldr r0, _08005C0C @ =0x0000D3A4
	str r0, [sp]
	movs r0, #0xff
	movs r1, #0x1a
	movs r2, #9
	bl fill_tilemap_pair_or_divide
_08005C02:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08005C08: .4byte 0x0400000A
_08005C0C: .4byte 0x0000D3A4
	.syntax divided
