	.syntax unified

	thumb_func_start sub_0800E690
sub_0800E690: @ 0x0800E690
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	ldr r0, _0800E6BC @ =0x083B5F80
	ldr r0, [r0, #0xc]
	movs r1, #6
	bl process_sprite_anim_commands
	ldr r0, _0800E6C0 @ =0x083B53F8
	ldr r0, [r0, #0x14]
	bl run_message
	cmp r0, #0
	beq _0800E6B8
	ldr r1, _0800E6C4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800E6B8:
	pop {r0}
	bx r0
	.align 2, 0
_0800E6BC: .4byte 0x083B5F80
_0800E6C0: .4byte 0x083B53F8
_0800E6C4: .4byte 0x0300137C
	.syntax divided
