	.syntax unified

	thumb_func_start init_scene_state
	.global init_scene_state
init_scene_state: @ 0x0800656C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r7, _08006608 @ =0x02026000
	adds r0, r7, #0
	movs r1, #0xd0
	movs r2, #0
	bl sub_0803F624
	ldr r4, _0800660C @ =0x020260D0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	movs r2, #0
	bl sub_0803F624
	ldr r5, _08006610 @ =0x020268D0
	adds r0, r5, #0
	movs r1, #0x60
	movs r2, #0
	bl sub_0803F624
	ldr r1, _08006614 @ =0x03000430
	movs r0, #2
	str r0, [r1]
	ldr r6, _08006618 @ =0x03002414
	ldr r1, _0800661C @ =0x02024000
	str r1, [r6]
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r2, _08006620 @ =0x01000426
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, _08006624 @ =0x03005308
	str r5, [r0]
	ldr r1, [r6]
	ldr r2, _08006628 @ =0x083D1BF8
	adds r0, r7, #0
	adds r3, r4, #0
	bl sub_08047414
	str r4, [r7, #8]
	ldr r4, _0800662C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r5, [r0]
	cmp r5, #0
	beq _08006634
	ldr r0, [r6]
	ldr r1, _08006630 @ =0x00000B84
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r1, [sp]
	adds r1, r4, #0
	adds r1, #0x9b
	ldrb r1, [r1]
	str r1, [sp, #4]
	movs r1, #0x28
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #0x10]
	movs r1, #8
	str r1, [sp, #0x14]
	movs r1, #1
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r1, r7, #0
	bl setup_scene_bg_layers_and_sprites
	b _0800666E
	.align 2, 0
_08006608: .4byte 0x02026000
_0800660C: .4byte 0x020260D0
_08006610: .4byte 0x020268D0
_08006614: .4byte 0x03000430
_08006618: .4byte 0x03002414
_0800661C: .4byte 0x02024000
_08006620: .4byte 0x01000426
_08006624: .4byte 0x03005308
_08006628: .4byte 0x083D1BF8
_0800662C: .4byte 0x03000440
_08006630: .4byte 0x00000B84
_08006634:
	ldr r0, [r6]
	ldr r1, _08006678 @ =0x00000B84
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r1, [sp]
	adds r1, r4, #0
	adds r1, #0x9b
	ldrb r1, [r1]
	str r1, [sp, #4]
	movs r1, #0x28
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0xe1
	lsls r1, r1, #1
	str r1, [sp, #0x10]
	movs r1, #8
	str r1, [sp, #0x14]
	movs r1, #1
	str r1, [sp, #0x18]
	str r5, [sp, #0x1c]
	adds r1, r7, #0
	bl setup_scene_bg_layers_and_sprites
_0800666E:
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006678: .4byte 0x00000B84
	.syntax divided
