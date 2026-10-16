	.syntax unified

	thumb_func_start sub_0801AD10
sub_0801AD10: @ 0x0801AD10
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0801AD2C @ =0x03000590
	lsls r1, r4, #8
	adds r1, r1, r0
	adds r1, #0xc1
	ldrb r0, [r1]
	cmp r0, #0x50
	bne _0801AD30
	adds r0, r4, #0
	bl draw_battle_panel_left_b
	b _0801AD36
	.align 2, 0
_0801AD2C: .4byte 0x03000590
_0801AD30:
	adds r0, r4, #0
	bl draw_battle_panel_left_a
_0801AD36:
	adds r0, r4, #0
	bl render_bot_health_bar
	adds r0, r4, #0
	bl render_bot_cash_display
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
