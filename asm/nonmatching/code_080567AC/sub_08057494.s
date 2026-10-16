	.syntax unified

	thumb_func_start sub_08057494
sub_08057494: @ 0x08057494
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	ldr r0, _08057510 @ =0x030064A0
	adds r7, r0, #0
	adds r7, #0x6f
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805751C
	ldr r0, _08057514 @ =0x03006D14
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r0, r1
	ldr r1, _08057518 @ =0x06002800
	mov sb, r1
	ldrb r1, [r7]
	movs r3, #0x1e
	subs r3, r3, r1
	movs r1, #1
	str r1, [sp]
	movs r6, #0xa
	str r6, [sp, #4]
	movs r5, #0x20
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r4, #0
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	mov r1, sb
	movs r2, #2
	bl copy_tilemap_rect_with_offset
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r7]
	movs r3, #0x1f
	subs r3, r3, r1
	str r1, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	mov r1, sb
	movs r2, #2
	bl copy_tilemap_rect_with_offset
	movs r0, #1
	bl init_vehicle_menu_sprite
	ldrb r0, [r7]
	subs r0, #1
	strb r0, [r7]
	b _08057528
	.align 2, 0
_08057510: .4byte 0x030064A0
_08057514: .4byte 0x03006D14
_08057518: .4byte 0x06002800
_0805751C:
	ldr r0, _08057538 @ =0x084C1ACC
	ldr r1, _0805753C @ =0x06002100
	bl lz_decompress_dispatch
	bl sub_0804A1C4
_08057528:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08057538: .4byte 0x084C1ACC
_0805753C: .4byte 0x06002100
	.syntax divided
