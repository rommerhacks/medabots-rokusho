	.syntax unified

	thumb_func_start init_sprite_object_entry
init_sprite_object_entry: @ 0x08045328
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0xc
	mov sl, r3
	ldr r3, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	mov sb, r4
	ldr r6, [sp, #0x30]
	ldr r5, [sp, #0x34]
	mov r8, r5
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r4, r8
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	str r1, [r0]
	mov r5, sb
	str r5, [r0, #4]
	ldr r5, [r3]
	lsls r4, r5, #0x14
	lsrs r4, r4, #0x1c
	strb r4, [r0, #0xa]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x1c
	strb r5, [r0, #0xb]
	mov r5, sb
	movs r4, #6
	ldrsb r4, [r5, r4]
	strh r4, [r0, #8]
	str r5, [sp]
	str r6, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r1, r2, #0
	mov r2, sl
	bl setup_oam_sprite_entries
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
