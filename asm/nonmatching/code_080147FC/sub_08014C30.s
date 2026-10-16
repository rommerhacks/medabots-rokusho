	.syntax unified

	thumb_func_start sub_08014C30
sub_08014C30: @ 0x08014C30
	push {r4, lr}
	ldr r1, _08014C6C @ =0x03005010
	movs r0, #0
	strh r0, [r1, #6]
	ldr r4, _08014C70 @ =0x03000590
	ldr r1, _08014C74 @ =0x000003DD
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #3
	bl battle_bot_select_part
	ldr r1, _08014C78 @ =0x000004DD
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #4
	bl battle_bot_select_part
	ldr r0, _08014C7C @ =0x000005DD
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #5
	bl battle_bot_select_part
	ldr r1, _08014C80 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08014C6C: .4byte 0x03005010
_08014C70: .4byte 0x03000590
_08014C74: .4byte 0x000003DD
_08014C78: .4byte 0x000004DD
_08014C7C: .4byte 0x000005DD
_08014C80: .4byte 0x0300137C
	.syntax divided
