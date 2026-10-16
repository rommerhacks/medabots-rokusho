	.syntax unified

	thumb_func_start sub_08026080
sub_08026080: @ 0x08026080
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	movs r6, #0
	ldr r0, _080260DC @ =0x083B6060
	mov r8, r0
	movs r5, #0x84
	lsls r5, r5, #4
	movs r4, #0x84
	lsls r4, r4, #0x16
_08026096:
	mov r1, r8
	ldr r0, [r1]
	lsrs r1, r4, #0x18
	bl process_sprite_anim_commands
	ldr r0, _080260E0 @ =0x03002C30
	adds r0, r5, r0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080260AE
	movs r7, #1
_080260AE:
	adds r5, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #2
	bls _08026096
	cmp r7, #0
	beq _080260D2
	ldr r0, _080260E4 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _080260E8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080260D2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080260DC: .4byte 0x083B6060
_080260E0: .4byte 0x03002C30
_080260E4: .4byte 0x03000440
_080260E8: .4byte 0x03001800
	.syntax divided
