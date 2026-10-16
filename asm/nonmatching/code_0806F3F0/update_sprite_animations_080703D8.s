	.syntax unified

	thumb_func_start update_sprite_animations_080703D8
	.global update_sprite_animations_080703D8
update_sprite_animations_080703D8: @ 0x080703D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
_080703E0:
	ldr r0, _0807042C @ =0x03002C30
	lsls r1, r7, #6
	adds r5, r1, r0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r6]
	cmp r0, #0
	beq _08070452
	ldrh r0, [r5, #0x1a]
	adds r0, #1
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #0x1a]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08070430 @ =0x084860C0
	ldrb r1, [r6]
	subs r4, r1, #1
	adds r2, r4, r2
	ldrb r1, [r2]
	bl sub_0807CC88
	cmp r0, #0
	bne _08070452
	ldr r0, _08070434 @ =0x084860AC
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r7, #0
	bl _call_via_r1
	cmp r0, #1
	beq _08070452
	cmp r0, #1
	bgt _08070438
	cmp r0, #0
	beq _0807043E
	b _08070452
	.align 2, 0
_0807042C: .4byte 0x03002C30
_08070430: .4byte 0x084860C0
_08070434: .4byte 0x084860AC
_08070438:
	cmp r0, #0xff
	beq _0807044C
	b _08070452
_0807043E:
	mov r0, r8
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0x21
	mov r1, r8
	strb r1, [r0]
	b _08070452
_0807044C:
	adds r0, r7, #0
	bl sub_0806B584
_08070452:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0xa
	bls _080703E0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
