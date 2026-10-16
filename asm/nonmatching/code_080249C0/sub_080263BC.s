	.syntax unified

	thumb_func_start sub_080263BC
sub_080263BC: @ 0x080263BC
	push {r4, r5, r6, r7, lr}
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r4, _0802643C @ =0x03000590
	ldr r6, _08026440 @ =0x03001800
	movs r0, #0x87
	adds r0, r0, r6
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xbd
	ldrb r2, [r0]
	movs r1, #0x10
	movs r5, #0
	orrs r1, r2
	strb r1, [r0]
	mov r1, ip
	ldrb r2, [r1]
	lsls r2, r2, #8
	adds r3, r2, r4
	adds r7, r6, #0
	adds r7, #0xa7
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, #0x49
	ldrb r0, [r0]
	adds r3, #0xdf
	strb r0, [r3]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xd8
	strh r5, [r0]
	ldrb r3, [r1]
	lsls r3, r3, #8
	adds r0, r4, r3
	adds r0, #0xd8
	ldrb r2, [r7]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r3
	adds r1, r1, r4
	adds r1, #0x4e
	ldrb r1, [r1]
	movs r2, #0xff
	bl sub_08035740
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802643C: .4byte 0x03000590
_08026440: .4byte 0x03001800
_08026444:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x2A, 0x20, 0x10, 0x70, 0xAA, 0x31
	.byte 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
