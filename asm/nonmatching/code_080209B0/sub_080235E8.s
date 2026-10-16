	.syntax unified

	thumb_func_start sub_080235E8
sub_080235E8: @ 0x080235E8
	push {r4, r5, lr}
	ldr r5, _08023644 @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r4, _08023648 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	ldrb r1, [r1]
	movs r2, #2
	bl sub_08037330
	ldr r0, _0802364C @ =0x083B5F80
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _08023650 @ =0x03002C30
	ldr r1, _08023654 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0802363C
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	adds r1, r5, #0
	adds r1, #0x86
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802363C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023644: .4byte 0x03000440
_08023648: .4byte 0x03001800
_0802364C: .4byte 0x083B5F80
_08023650: .4byte 0x03002C30
_08023654: .4byte 0x00000862
	.syntax divided
