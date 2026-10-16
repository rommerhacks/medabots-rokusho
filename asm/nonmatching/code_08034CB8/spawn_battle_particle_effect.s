	.syntax unified

	thumb_func_start spawn_battle_particle_effect
spawn_battle_particle_effect: @ 0x08037A94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	ldr r0, _08037AB0 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _08037AB8
	cmp r0, #1
	bgt _08037AB4
	cmp r0, #0
	beq _08037AB8
	b _08037ABA
	.align 2, 0
_08037AB0: .4byte 0x03001800
_08037AB4:
	cmp r0, #2
	bne _08037ABA
_08037AB8:
	movs r2, #7
_08037ABA:
	ldr r5, _08037B4C @ =0x03002C30
	lsls r0, r1, #6
	adds r7, r0, r5
	adds r0, r7, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _08037B8C
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x14
	bl find_next_free_sprite_slot
	adds r4, r0, #0
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl clear_battle_sprite_slot
	lsls r4, r4, #6
	adds r6, r4, r5
	movs r0, #0
	mov r8, r0
	ldr r0, _08037B50 @ =0x0000C604
	strh r0, [r6]
	mov r1, r8
	strb r1, [r6, #0x1c]
	bl rng_next_080424B8
	ldr r5, _08037B54 @ =0x083AF520
	movs r4, #3
	ands r0, r4
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	ldr r2, _08037B58 @ =0x000001FF
	adds r1, r2, #0
	ands r0, r1
	strh r0, [r6, #2]
	bl rng_next_080424B8
	ands r0, r4
	lsls r0, r0, #1
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r7, [r7, #4]
	adds r0, r0, r7
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #4]
	movs r0, #0x40
	strb r0, [r6, #8]
	strb r0, [r6, #9]
	movs r0, #6
	strb r0, [r6, #0xa]
	movs r0, #0xe0
	strb r0, [r6, #0xb]
	ldr r0, _08037B5C @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _08037B78
	cmp r0, #1
	bgt _08037B60
	cmp r0, #0
	beq _08037B66
	b _08037B8C
	.align 2, 0
_08037B4C: .4byte 0x03002C30
_08037B50: .4byte 0x0000C604
_08037B54: .4byte 0x083AF520
_08037B58: .4byte 0x000001FF
_08037B5C: .4byte 0x03001800
_08037B60:
	cmp r0, #2
	beq _08037B80
	b _08037B8C
_08037B66:
	ldr r0, _08037B74 @ =0x00007201
	strh r0, [r6, #6]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #0x30
	b _08037B8A
	.align 2, 0
_08037B74: .4byte 0x00007201
_08037B78:
	ldr r0, _08037B7C @ =0x00007302
	b _08037B82
	.align 2, 0
_08037B7C: .4byte 0x00007302
_08037B80:
	ldr r0, _08037B98 @ =0x00007402
_08037B82:
	strh r0, [r6, #6]
	adds r1, r6, #0
	adds r1, #0x29
	movs r0, #0x34
_08037B8A:
	strb r0, [r1]
_08037B8C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037B98: .4byte 0x00007402
	.syntax divided
