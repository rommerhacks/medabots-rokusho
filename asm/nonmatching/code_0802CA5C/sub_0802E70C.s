	.syntax unified

	thumb_func_start sub_0802E70C
sub_0802E70C: @ 0x0802E70C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r6, #0
	movs r2, #0
	movs r5, #0
	ldr r7, _0802E790 @ =0x03001800
	movs r0, #0xd6
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0802E794 @ =0x083B5F80
	mov sb, r1
_0802E728:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E76A
	adds r2, #1
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802E768
	ldr r0, _0802E798 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, sb
	ldr r0, [r0]
	adds r4, r5, #0
	adds r4, #0xa
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	str r2, [sp]
	bl process_sprite_anim_commands
	ldr r0, _0802E79C @ =0x03002C30
	lsls r4, r4, #6
	adds r4, r4, r0
	adds r4, #0x22
	ldrb r0, [r4]
	ldr r2, [sp]
	cmp r0, #0xff
	bne _0802E76A
_0802E768:
	adds r6, #1
_0802E76A:
	movs r0, #2
	add r8, r0
	adds r5, #1
	cmp r5, #2
	bls _0802E728
	cmp r6, r2
	bne _0802E782
	ldr r1, _0802E790 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802E782:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E790: .4byte 0x03001800
_0802E794: .4byte 0x083B5F80
_0802E798: .4byte 0x03000440
_0802E79C: .4byte 0x03002C30
	.syntax divided
