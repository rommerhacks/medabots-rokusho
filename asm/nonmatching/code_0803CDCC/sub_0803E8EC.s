	.syntax unified

	thumb_func_start sub_0803E8EC
sub_0803E8EC: @ 0x0803E8EC
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r4, #0
	ldr r6, _0803E92C @ =0x0300199A
	movs r5, #2
_0803E8F6:
	ldr r0, _0803E930 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #0x11
	movs r1, #0xce
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #2
	movs r2, #4
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	adds r5, #2
	adds r4, #1
	cmp r4, #5
	bls _0803E8F6
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803E92C: .4byte 0x0300199A
_0803E930: .4byte 0x0400000A
	.syntax divided
