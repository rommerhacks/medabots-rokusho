	.syntax unified

	thumb_func_start setup_overworld_scene_from_position
	.global setup_overworld_scene_from_position
setup_overworld_scene_from_position: @ 0x080054C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	ldr r6, _08005524 @ =0x030017A0
	ldr r1, _08005528 @ =0x03000440
	movs r0, #0x51
	adds r0, r0, r1
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r4, r0, r6
	ldrb r0, [r4]
	cmp r0, #0
	beq _08005572
	adds r0, r1, #0
	adds r0, #0x5e
	ldrb r5, [r0]
	cmp r5, #0
	beq _08005538
	ldr r0, _0800552C @ =0x03002414
	ldr r0, [r0]
	ldr r1, _08005530 @ =0x00000B84
	adds r0, r0, r1
	ldr r1, _08005534 @ =0x02026000
	ldrb r2, [r4, #3]
	ldrb r3, [r4, #4]
	ldrb r4, [r4, #5]
	str r4, [sp]
	mov r5, ip
	ldrb r4, [r5]
	lsls r4, r4, #3
	adds r4, r4, r6
	ldrb r4, [r4, #6]
	str r4, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	movs r4, #0x32
	str r4, [sp, #0xc]
	movs r4, #0xe1
	lsls r4, r4, #1
	str r4, [sp, #0x10]
	movs r4, #8
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	movs r4, #1
	str r4, [sp, #0x1c]
	bl setup_scene_bg_layers_and_sprites
	b _08005572
	.align 2, 0
_08005524: .4byte 0x030017A0
_08005528: .4byte 0x03000440
_0800552C: .4byte 0x03002414
_08005530: .4byte 0x00000B84
_08005534: .4byte 0x02026000
_08005538:
	ldr r0, _0800557C @ =0x03002414
	ldr r0, [r0]
	ldr r7, _08005580 @ =0x00000B84
	adds r0, r0, r7
	ldr r1, _08005584 @ =0x02026000
	ldrb r2, [r4, #3]
	ldrb r3, [r4, #4]
	ldrb r4, [r4, #5]
	str r4, [sp]
	mov r7, ip
	ldrb r4, [r7]
	lsls r4, r4, #3
	adds r4, r4, r6
	ldrb r4, [r4, #6]
	str r4, [sp, #4]
	movs r4, #0x3c
	str r4, [sp, #8]
	movs r4, #0x32
	str r4, [sp, #0xc]
	movs r4, #0xe1
	lsls r4, r4, #1
	str r4, [sp, #0x10]
	movs r4, #8
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	str r5, [sp, #0x1c]
	bl setup_scene_bg_layers_and_sprites
_08005572:
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800557C: .4byte 0x03002414
_08005580: .4byte 0x00000B84
_08005584: .4byte 0x02026000
	.syntax divided
