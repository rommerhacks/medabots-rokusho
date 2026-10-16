	.syntax unified

	thumb_func_start sub_0801F780
sub_0801F780: @ 0x0801F780
	push {lr}
	ldr r1, _0801F7A8 @ =0x03002C30
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0801F7B0
	ldr r0, _0801F7AC @ =0x00000289
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _0801F7BE
	movs r0, #1
	strb r0, [r2]
	b _0801F7BE
	.align 2, 0
_0801F7A8: .4byte 0x03002C30
_0801F7AC: .4byte 0x00000289
_0801F7B0:
	ldr r0, _0801F7EC @ =0x00000289
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	beq _0801F7BE
	subs r0, #4
	strb r0, [r1]
_0801F7BE:
	ldr r0, _0801F7F0 @ =0x083B5F80
	adds r0, #0x84
	ldr r0, [r0]
	movs r1, #0xb
	bl process_sprite_anim_commands
	ldr r0, _0801F7F4 @ =0x03002C30
	ldr r1, _0801F7F8 @ =0x000002E2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801F7E8
	movs r0, #0xa
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _0801F7FC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801F7E8:
	pop {r0}
	bx r0
	.align 2, 0
_0801F7EC: .4byte 0x00000289
_0801F7F0: .4byte 0x083B5F80
_0801F7F4: .4byte 0x03002C30
_0801F7F8: .4byte 0x000002E2
_0801F7FC: .4byte 0x03001800
	.syntax divided
