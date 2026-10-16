	.syntax unified

	thumb_func_start update_sprite_animations_tick_080370AC
	.global update_sprite_animations_tick_080370AC
update_sprite_animations_tick_080370AC: @ 0x080370AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	adds r7, r1, #0
	movs r0, #1
	mov r8, r0
	movs r6, #0
	cmp r6, r7
	bhs _0803712A
	ldr r1, _080370EC @ =0x083B6010
	mov sl, r1
_080370C8:
	ldr r1, _080370F0 @ =0x03002C30
	mov r0, sb
	adds r3, r0, r6
	lsls r0, r3, #6
	adds r4, r0, r1
	ldrh r2, [r4]
	cmp r2, #0
	beq _08037124
	adds r1, r4, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _080370F4
	subs r0, #1
	strb r0, [r1]
	movs r1, #0
	mov r8, r1
	b _08037124
	.align 2, 0
_080370EC: .4byte 0x083B6010
_080370F0: .4byte 0x03002C30
_080370F4:
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	orrs r0, r2
	strh r0, [r4]
	mov r1, sl
	ldr r0, [r1]
	lsls r1, r3, #0x18
	lsrs r5, r1, #0x18
	adds r1, r5, #0
	bl process_sprite_anim_commands
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08037120
	adds r0, r5, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	b _08037124
_08037120:
	movs r0, #0
	mov r8, r0
_08037124:
	adds r6, #1
	cmp r6, r7
	blo _080370C8
_0803712A:
	mov r0, r8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
