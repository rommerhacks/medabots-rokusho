	.syntax unified

	thumb_func_start start_battle_transition_anim
start_battle_transition_anim: @ 0x0801F290
	push {lr}
	ldr r0, _0801F2C8 @ =0x083B5F80
	adds r0, #0x80
	ldr r0, [r0]
	movs r1, #0xa
	bl process_sprite_anim_commands
	ldr r0, _0801F2CC @ =0x03002C30
	ldr r1, _0801F2D0 @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801F2C4
	movs r0, #0xa
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0801F2D4 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0801F2D8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801F2C4:
	pop {r0}
	bx r0
	.align 2, 0
_0801F2C8: .4byte 0x083B5F80
_0801F2CC: .4byte 0x03002C30
_0801F2D0: .4byte 0x000002A2
_0801F2D4: .4byte 0x03000440
_0801F2D8: .4byte 0x03001800
	.syntax divided
