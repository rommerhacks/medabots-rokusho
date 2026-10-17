	.syntax unified

	thumb_func_start sub_0801EB5C
sub_0801EB5C: @ 0x0801EB5C
	push {r4, lr}
	ldr r0, _0801EBA4 @ =0x083B5F80
	ldr r0, [r0, #0x78]
	movs r1, #0xa
	bl process_sprite_anim_commands
	ldr r0, _0801EBA8 @ =0x03002C30
	ldr r1, _0801EBAC @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0801EB86
	movs r0, #0xa
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0801EBB0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801EB86:
	ldr r0, _0801EBB4 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x86
	ldrh r0, [r4]
	cmp r0, #0x12
	bne _0801EB96
	bl setup_battle_medapart_scenes
_0801EB96:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801EBA4: .4byte 0x083B5F80
_0801EBA8: .4byte 0x03002C30
_0801EBAC: .4byte 0x000002A2
_0801EBB0: .4byte 0x03001800
_0801EBB4: .4byte 0x03000440
	.syntax divided
