	.syntax unified

	thumb_func_start sub_08005628
	.global sub_08005628
sub_08005628: @ 0x08005628
	push {r4, r5, lr}
	ldr r5, _0800568C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldr r4, _08005690 @ =0x0000C604
	strh r4, [r0]
	ldr r2, _08005694 @ =0x00000123
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #4
	bl update_battle_sprite_orbit_counterclockwise
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _08005698 @ =0x00000163
	adds r1, r5, r2
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #5
	bl update_battle_sprite_orbit_counterclockwise
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _0800569C @ =0x000001A3
	adds r1, r5, r2
	movs r0, #0x20
	strb r0, [r1]
	movs r0, #6
	bl update_battle_sprite_orbit_counterclockwise
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r2, _080056A0 @ =0x000001E3
	adds r1, r5, r2
	movs r0, #0x30
	strb r0, [r1]
	movs r0, #7
	bl update_battle_sprite_orbit_counterclockwise
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800568C: .4byte 0x03002C30
_08005690: .4byte 0x0000C604
_08005694: .4byte 0x00000123
_08005698: .4byte 0x00000163
_0800569C: .4byte 0x000001A3
_080056A0: .4byte 0x000001E3
	.syntax divided
