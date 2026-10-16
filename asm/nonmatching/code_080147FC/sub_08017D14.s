	.syntax unified

	thumb_func_start sub_08017D14
	.global sub_08017D14
sub_08017D14: @ 0x08017D14
	push {r4, r5, lr}
	sub sp, #8
	movs r4, #0
	movs r5, #2
_08017D1C:
	ldr r0, _08017D48 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	lsls r0, r4, #0x12
	ldr r1, _08017D4C @ =0xC3700000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #9
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	adds r5, #2
	adds r4, #1
	cmp r4, #4
	bls _08017D1C
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017D48: .4byte 0x0400000A
_08017D4C: .4byte 0xC3700000
	.syntax divided
