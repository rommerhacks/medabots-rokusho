	.syntax unified

	thumb_func_start init_scene_rendering_context
	.global init_scene_rendering_context
init_scene_rendering_context: @ 0x080628A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	cmp r7, #0
	bne _08062970
	ldr r0, _08062940 @ =0x02026000
	mov r8, r0
	movs r1, #0xd0
	movs r2, #0
	bl sub_0803F624
	ldr r5, _08062944 @ =0x020260D0
	movs r4, #0x82
	lsls r4, r4, #4
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0803F624
	ldr r0, _08062948 @ =0x020264E0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0803F624
	ldr r6, _0806294C @ =0x020268F0
	adds r0, r6, #0
	movs r1, #0x60
	movs r2, #0
	bl sub_0803F624
	ldr r1, _08062950 @ =0x03000430
	movs r0, #2
	str r0, [r1]
	ldr r4, _08062954 @ =0x03002414
	ldr r1, _08062958 @ =0x02024000
	str r1, [r4]
	str r7, [sp, #0x14]
	ldr r2, _0806295C @ =0x01000426
	add r0, sp, #0x14
	bl CpuFastSet
	ldr r0, _08062960 @ =0x03005308
	str r6, [r0]
	ldr r1, [r4]
	ldr r2, _08062964 @ =0x083D1BF8
	mov r0, r8
	adds r3, r5, #0
	bl sub_08047414
	mov r1, r8
	str r5, [r1, #8]
	ldr r0, [r4]
	ldr r1, _08062968 @ =0x00000B84
	adds r0, r0, r1
	ldr r1, _0806296C @ =0x03006F74
	ldr r1, [r1]
	adds r2, r1, #0
	adds r2, #0x31
	ldrb r2, [r2]
	adds r1, #0x33
	ldrb r3, [r1]
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0xc7
	str r1, [sp, #8]
	str r7, [sp, #0xc]
	movs r1, #1
	str r1, [sp, #0x10]
	mov r1, r8
	bl load_sprite_animation_by_type
	b _080629B2
	.align 2, 0
_08062940: .4byte 0x02026000
_08062944: .4byte 0x020260D0
_08062948: .4byte 0x020264E0
_0806294C: .4byte 0x020268F0
_08062950: .4byte 0x03000430
_08062954: .4byte 0x03002414
_08062958: .4byte 0x02024000
_0806295C: .4byte 0x01000426
_08062960: .4byte 0x03005308
_08062964: .4byte 0x083D1BF8
_08062968: .4byte 0x00000B84
_0806296C: .4byte 0x03006F74
_08062970:
	ldr r6, _080629C0 @ =0x02026000
	ldr r5, _080629C4 @ =0x03002414
	ldr r1, [r5]
	ldr r2, _080629C8 @ =0x083D1BF8
	ldr r4, _080629CC @ =0x020264E0
	adds r0, r6, #0
	adds r3, r4, #0
	bl sub_08047414
	str r4, [r6, #8]
	ldr r0, [r5]
	ldr r1, _080629D0 @ =0x00000B84
	adds r0, r0, r1
	ldr r1, _080629D4 @ =0x03006F74
	ldr r1, [r1]
	adds r2, r1, #0
	adds r2, #0x32
	ldrb r2, [r2]
	adds r1, #0x34
	ldrb r3, [r1]
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0xc7
	str r1, [sp, #8]
	movs r1, #4
	str r1, [sp, #0xc]
	movs r1, #2
	str r1, [sp, #0x10]
	adds r1, r6, #0
	bl load_sprite_animation_by_type
_080629B2:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080629C0: .4byte 0x02026000
_080629C4: .4byte 0x03002414
_080629C8: .4byte 0x083D1BF8
_080629CC: .4byte 0x020264E0
_080629D0: .4byte 0x00000B84
_080629D4: .4byte 0x03006F74
	.syntax divided
