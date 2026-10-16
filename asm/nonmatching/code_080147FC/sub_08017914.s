	.syntax unified

	thumb_func_start sub_08017914
	.global sub_08017914
sub_08017914: @ 0x08017914
	push {lr}
	ldr r1, _08017934 @ =0x03000590
	ldr r0, _08017938 @ =0x03001800
	adds r0, #0x80
	ldrb r2, [r0]
	lsls r0, r2, #8
	adds r0, r0, r1
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	bne _0801793C
	adds r0, r2, #0
	bl draw_battle_panel_left_b
	b _08017942
	.align 2, 0
_08017934: .4byte 0x03000590
_08017938: .4byte 0x03001800
_0801793C:
	adds r0, r2, #0
	bl draw_battle_panel_left_a
_08017942:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
