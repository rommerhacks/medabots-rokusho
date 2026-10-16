	.syntax unified

	thumb_func_start init_ewram_buffers_and_state
	.global init_ewram_buffers_and_state
init_ewram_buffers_and_state: @ 0x08018098
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r6, _08018154 @ =0x02026000
	adds r0, r6, #0
	movs r1, #0xd0
	movs r2, #0
	bl sub_0803F624
	ldr r5, _08018158 @ =0x020260D0
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r5, #0
	movs r2, #0
	bl sub_0803F624
	ldr r0, _0801815C @ =0x020268D0
	mov r8, r0
	movs r1, #0x60
	movs r2, #0
	bl sub_0803F624
	ldr r7, _08018160 @ =0x03000440
	adds r0, r7, #0
	adds r0, #0x96
	movs r1, #0
	mov sl, r1
	movs r1, #1
	mov sb, r1
	mov r1, sb
	strb r1, [r0]
	ldr r1, _08018164 @ =0x03000430
	movs r0, #2
	str r0, [r1]
	ldr r4, _08018168 @ =0x03002414
	ldr r1, _0801816C @ =0x02024000
	str r1, [r4]
	mov r0, sl
	str r0, [sp, #0x20]
	ldr r2, _08018170 @ =0x01000426
	add r0, sp, #0x20
	bl CpuFastSet
	ldr r0, _08018174 @ =0x03005308
	mov r1, r8
	str r1, [r0]
	ldr r1, [r4]
	ldr r2, _08018178 @ =0x083D1BF8
	adds r0, r6, #0
	adds r3, r5, #0
	bl sub_08047414
	str r5, [r6, #8]
	ldr r0, [r4]
	ldr r1, _0801817C @ =0x00000B84
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0x98
	ldrb r2, [r1]
	adds r1, #1
	ldrb r3, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r1, [sp]
	adds r1, r7, #0
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
	mov r1, sb
	str r1, [sp, #0x18]
	mov r1, sl
	str r1, [sp, #0x1c]
	adds r1, r6, #0
	bl setup_scene_bg_layers_and_sprites
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018154: .4byte 0x02026000
_08018158: .4byte 0x020260D0
_0801815C: .4byte 0x020268D0
_08018160: .4byte 0x03000440
_08018164: .4byte 0x03000430
_08018168: .4byte 0x03002414
_0801816C: .4byte 0x02024000
_08018170: .4byte 0x01000426
_08018174: .4byte 0x03005308
_08018178: .4byte 0x083D1BF8
_0801817C: .4byte 0x00000B84
	.syntax divided
