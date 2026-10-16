	.syntax unified

	thumb_func_start init_scene_buffers_080445F4
	.global init_scene_buffers_080445F4
init_scene_buffers_080445F4: @ 0x080445F4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	ldr r0, _08044680 @ =0x02026000
	mov sb, r0
	movs r1, #0xd0
	movs r2, #0
	bl sub_0803F624
	ldr r1, _08044684 @ =0x020260D0
	mov r8, r1
	movs r1, #0x82
	lsls r1, r1, #4
	mov r0, r8
	movs r2, #0
	bl sub_0803F624
	ldr r6, _08044688 @ =0x020268F0
	adds r0, r6, #0
	movs r1, #0x60
	movs r2, #0
	bl sub_0803F624
	ldr r1, _0804468C @ =0x03000430
	movs r0, #2
	str r0, [r1]
	ldr r4, _08044690 @ =0x03002414
	ldr r1, _08044694 @ =0x02024000
	str r1, [r4]
	movs r5, #0
	str r5, [sp]
	ldr r2, _08044698 @ =0x01000426
	mov r0, sp
	bl CpuFastSet
	ldr r0, _0804469C @ =0x03005308
	str r6, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #4]
	add r0, sp, #4
	ldr r1, [r4]
	ldr r2, _080446A0 @ =0x00000B84
	adds r1, r1, r2
	ldr r2, _080446A4 @ =0x01000100
	bl CpuFastSet
	ldr r0, [r4]
	ldr r1, _080446A8 @ =0x00001094
	adds r0, r0, r1
	strb r5, [r0]
	ldr r0, [r4]
	ldr r2, _080446AC @ =0x00001095
	adds r0, r0, r2
	strb r5, [r0]
	ldr r1, [r4]
	ldr r2, _080446B0 @ =0x083D1BF8
	mov r0, sb
	mov r3, r8
	bl sub_08047414
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08044680: .4byte 0x02026000
_08044684: .4byte 0x020260D0
_08044688: .4byte 0x020268F0
_0804468C: .4byte 0x03000430
_08044690: .4byte 0x03002414
_08044694: .4byte 0x02024000
_08044698: .4byte 0x01000426
_0804469C: .4byte 0x03005308
_080446A0: .4byte 0x00000B84
_080446A4: .4byte 0x01000100
_080446A8: .4byte 0x00001094
_080446AC: .4byte 0x00001095
_080446B0: .4byte 0x083D1BF8
	.syntax divided
