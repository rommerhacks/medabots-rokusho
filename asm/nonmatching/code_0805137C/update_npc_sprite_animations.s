	.syntax unified

	thumb_func_start update_npc_sprite_animations
	.global update_npc_sprite_animations
update_npc_sprite_animations: @ 0x080521B8
	push {r4, r5, r6, r7, lr}
	ldr r4, _080521E8 @ =0x03005DBC
	movs r5, #0
	ldr r0, _080521EC @ =0xFFFFFA24
	adds r6, r4, r0
	ldr r1, _080521F0 @ =0x00000C92
	adds r7, r6, r1
_080521C6:
	ldr r1, _080521F4 @ =0x00000C88
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080521F8
	adds r1, #0x2c
	adds r0, r6, r1
	ldrb r1, [r0]
	eors r1, r5
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r1, r0, #0x1f
	ldrb r0, [r7]
	cmp r0, #0x87
	bne _080521FA
	b _08052224
	.align 2, 0
_080521E8: .4byte 0x03005DBC
_080521EC: .4byte 0xFFFFFA24
_080521F0: .4byte 0x00000C92
_080521F4: .4byte 0x00000C88
_080521F8:
	movs r1, #1
_080521FA:
	cmp r1, #0
	beq _08052224
	ldrh r0, [r4, #2]
	lsrs r0, r0, #0xc
	cmp r0, #6
	bne _08052224
	ldrb r0, [r4, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1b
	adds r2, r0, #0
	adds r2, #0x31
	ldr r1, _08052234 @ =0x03002C30
	lsls r0, r2, #6
	adds r0, r0, r1
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08052224
	adds r0, r2, #0
	bl advance_sprite_animation_frame
_08052224:
	adds r4, #8
	adds r5, #1
	cmp r5, #0x3f
	ble _080521C6
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052234: .4byte 0x03002C30
	.syntax divided
