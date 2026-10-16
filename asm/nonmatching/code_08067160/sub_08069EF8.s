	.syntax unified

	thumb_func_start sub_08069EF8
sub_08069EF8: @ 0x08069EF8
	push {r4, lr}
	ldr r4, _08069F08 @ =0x03006F88
	ldr r0, [r4]
	cmp r0, #0
	beq _08069F0C
	cmp r0, #1
	beq _08069F4C
	b _08069F70
	.align 2, 0
_08069F08: .4byte 0x03006F88
_08069F0C:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	bl init_battle_sprite_small
	movs r0, #0
	movs r1, #1
	movs r2, #0x20
	movs r3, #0x58
	bl sprite_animation_dispatch
	ldr r0, _08069F40 @ =0x030004DE
	ldr r2, _08069F44 @ =0x083BE9E8
	ldr r1, _08069F48 @ =0x03006F84
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_08069EE4
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	b _08069F78
	.align 2, 0
_08069F40: .4byte 0x030004DE
_08069F44: .4byte 0x083BE9E8
_08069F48: .4byte 0x03006F84
_08069F4C:
	ldr r0, _08069F68 @ =0x084864E8
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08069F70
	ldr r0, _08069F6C @ =0x03002C30
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	bne _08069F70
	movs r0, #1
	b _08069F7A
	.align 2, 0
_08069F68: .4byte 0x084864E8
_08069F6C: .4byte 0x03002C30
_08069F70:
	bl update_sprite_animations_tick_0806AF40
	bl update_sprite_animations_0806B334
_08069F78:
	movs r0, #0
_08069F7A:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
