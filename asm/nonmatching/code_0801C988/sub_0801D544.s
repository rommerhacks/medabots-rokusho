	.syntax unified

	thumb_func_start sub_0801D544
sub_0801D544: @ 0x0801D544
	push {lr}
	ldr r0, _0801D570 @ =0x083B5F80
	ldr r0, [r0, #0x6c]
	movs r1, #9
	bl process_sprite_anim_commands
	ldr r0, _0801D574 @ =0x03002C30
	ldr r1, _0801D578 @ =0x00000262
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801D56C
	movs r0, #9
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0801D57C @ =0x03001800
	adds r0, #0xb5
	movs r1, #1
	strb r1, [r0]
_0801D56C:
	pop {r0}
	bx r0
	.align 2, 0
_0801D570: .4byte 0x083B5F80
_0801D574: .4byte 0x03002C30
_0801D578: .4byte 0x00000262
_0801D57C: .4byte 0x03001800
	.syntax divided
