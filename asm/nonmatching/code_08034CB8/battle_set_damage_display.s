	.syntax unified

	thumb_func_start battle_set_damage_display
	.global battle_set_damage_display
battle_set_damage_display: @ 0x080372D4
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08037304 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x4c
	ldrb r1, [r2]
	cmp r1, r4
	blt _0803730C
	ldr r2, _08037308 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xc8
	movs r1, #0
	strh r4, [r0]
	adds r0, #4
	strh r4, [r0]
	subs r0, #2
	strh r1, [r0]
	b _08037324
	.align 2, 0
_08037304: .4byte 0x03000590
_08037308: .4byte 0x03001800
_0803730C:
	ldr r3, _0803732C @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xc8
	strh r1, [r0]
	ldrb r1, [r2]
	adds r0, #4
	strh r1, [r0]
	ldrb r0, [r2]
	subs r0, r4, r0
	adds r1, r3, #0
	adds r1, #0xca
	strh r0, [r1]
_08037324:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803732C: .4byte 0x03001800
	.syntax divided
