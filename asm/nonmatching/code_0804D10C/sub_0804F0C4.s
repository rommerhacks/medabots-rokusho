	.syntax unified

	thumb_func_start sub_0804F0C4
sub_0804F0C4: @ 0x0804F0C4
	push {r4, r5, lr}
	ldr r4, _0804F0D8 @ =0x030057E0
	ldr r0, _0804F0DC @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804F0E0
	cmp r0, #1
	beq _0804F120
	b _0804F132
	.align 2, 0
_0804F0D8: .4byte 0x030057E0
_0804F0DC: .4byte 0x00000C93
_0804F0E0:
	movs r0, #0x2f
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	ldr r2, _0804F118 @ =0x00000C8A
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _0804F11C @ =0x00000C94
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #4
	adds r2, #0xb
	adds r0, r4, r2
	ldrb r0, [r0]
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x2f
	movs r2, #0
	bl sub_080500D8
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804F132
	.align 2, 0
_0804F118: .4byte 0x00000C8A
_0804F11C: .4byte 0x00000C94
_0804F120:
	ldr r1, _0804F138 @ =0x00000C94
	adds r0, r4, r1
	ldrb r0, [r0]
	bl sub_0804F13C
	cmp r0, #0
	beq _0804F132
	bl map_script_command_done
_0804F132:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F138: .4byte 0x00000C94
	.syntax divided
