	.syntax unified

	thumb_func_start sub_080201DC
sub_080201DC: @ 0x080201DC
	push {r4, lr}
	ldr r0, _0802020C @ =0x083B5F80
	adds r0, #0xdc
	ldr r0, [r0]
	movs r1, #0xb
	bl process_sprite_anim_commands
	ldr r2, _08020210 @ =0x03002C30
	ldr r0, _08020214 @ =0x000002AB
	adds r4, r2, r0
	ldrb r3, [r4]
	cmp r3, #0x28
	bne _0802021C
	movs r0, #0xb
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _08020218 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08020240
	.align 2, 0
_0802020C: .4byte 0x083B5F80
_08020210: .4byte 0x03002C30
_08020214: .4byte 0x000002AB
_08020218: .4byte 0x03001800
_0802021C:
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _08020240
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	adds r0, r3, #1
	strb r0, [r4]
_08020240:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
