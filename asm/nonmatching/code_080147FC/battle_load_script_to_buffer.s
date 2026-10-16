	.syntax unified

	thumb_func_start battle_load_script_to_buffer
	.global battle_load_script_to_buffer
battle_load_script_to_buffer: @ 0x08017E00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r0, #0x20
	movs r1, #0x38
	bl clear_sprite_table_mask
	movs r4, #0
	ldr r0, _08017E9C @ =0x03000590
	mov sl, r0
	ldr r5, _08017EA0 @ =0x03000440
	movs r1, #0x9e
	adds r1, r1, r5
	mov sb, r1
	movs r0, #4
	mov r8, r0
	movs r7, #0x80
	lsls r7, r7, #0x16
	movs r6, #0
_08017E2C:
	adds r2, r5, #0
	adds r2, #0x3d
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r0, r6, r0
	add r0, sl
	adds r0, #0x5f
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _08017EA4 @ =0x083BB9CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, sb
	movs r2, #0xf
	bl memcpy_bytes_08041D04
	lsrs r1, r7, #0x18
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	mov r0, sb
	movs r2, #0xd
	mov r3, r8
	bl render_text_sprites_08040DB8
	movs r0, #2
	add r8, r0
	movs r1, #0xe0
	lsls r1, r1, #0x14
	adds r7, r7, r1
	adds r6, #0x18
	adds r4, #1
	cmp r4, #3
	bls _08017E2C
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017E9C: .4byte 0x03000590
_08017EA0: .4byte 0x03000440
_08017EA4: .4byte 0x083BB9CC
	.syntax divided
