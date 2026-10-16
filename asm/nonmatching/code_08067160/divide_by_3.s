	.syntax unified

	thumb_func_start divide_by_3
divide_by_3: @ 0x080699A4
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x20
	adds r4, r0, #0
	mov sb, r1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r5, #3
	mov sl, r5
	adds r0, r4, #0
	movs r1, #3
	bl sub_0807CD58
	mov r8, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r4, #0
	movs r1, #3
	bl sub_0807CDD0
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r1, _08069A58 @ =0x080AFF30
	add r0, sp, #0x1c
	movs r2, #3
	bl memcpy_optimized
	ldr r4, _08069A5C @ =0x03006FA0
	mov r0, r8
	lsls r6, r0, #1
	add r6, r8
	lsls r3, r6, #2
	adds r3, r5, r3
	adds r0, r3, r4
	ldrb r0, [r0]
	adds r1, r4, #3
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r4, #6
	adds r2, r3, r2
	ldrb r2, [r2]
	adds r4, #9
	adds r3, r3, r4
	ldrb r3, [r3]
	subs r4, r5, #2
	subs r4, r6, r4
	str r4, [sp]
	ldr r4, _08069A60 @ =0x08485CC4
	adds r5, r5, r6
	adds r5, r5, r4
	ldrb r4, [r5]
	subs r4, #3
	str r4, [sp, #4]
	ldr r6, _08069A64 @ =0x03002C30
	ldrb r4, [r5]
	lsls r4, r4, #6
	adds r4, r4, r6
	movs r5, #2
	ldrsh r4, [r4, r5]
	str r4, [sp, #8]
	mov r4, sp
	add r4, r8
	adds r4, #0x1c
	ldrb r4, [r4]
	str r4, [sp, #0xc]
	mov r4, sb
	str r4, [sp, #0x10]
	mov r5, sl
	str r5, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	bl setup_battle_sprite_group
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08069A58: .4byte 0x080AFF30
_08069A5C: .4byte 0x03006FA0
_08069A60: .4byte 0x08485CC4
_08069A64: .4byte 0x03002C30
	.syntax divided
