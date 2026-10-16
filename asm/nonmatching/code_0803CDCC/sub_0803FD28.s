	.syntax unified

	thumb_func_start sub_0803FD28
sub_0803FD28: @ 0x0803FD28
	push {r4, r5, lr}
	ldr r1, _0803FD4C @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x13]
	adds r5, r1, #0
_0803FD32:
	ldrh r0, [r5, #0xc]
	ldr r1, [r5, #8]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #0xf7
	cmp r0, #8
	bls _0803FD42
	b _0803FE64
_0803FD42:
	lsls r0, r0, #2
	ldr r1, _0803FD50 @ =_0803FD54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803FD4C: .4byte 0x03000440
_0803FD50: .4byte _0803FD54
_0803FD54: @ jump table
	.4byte _0803FDC4 @ case 0
	.4byte _0803FE38 @ case 1
	.4byte _0803FD78 @ case 2
	.4byte _0803FDB0 @ case 3
	.4byte _0803FDDC @ case 4
	.4byte _0803FDE2 @ case 5
	.4byte _0803FDFC @ case 6
	.4byte _0803FE32 @ case 7
	.4byte _0803FE54 @ case 8
_0803FD78:
	ldr r4, _0803FD8C @ =0x03000440
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bne _0803FD90
	movs r0, #0
	strb r0, [r4, #0x13]
	bl reset_text_tile_state
	b _0803FE92
	.align 2, 0
_0803FD8C: .4byte 0x03000440
_0803FD90:
	cmp r0, #2
	bne _0803FD9E
	movs r0, #1
	strb r0, [r4, #0x13]
	bl update_text_compose_and_input
	b _0803FE92
_0803FD9E:
	movs r5, #0
	strb r5, [r4, #0x13]
	bl sub_080402B4
	ldrb r0, [r4, #0x1a]
	cmp r0, #0xff
	bne _0803FE92
	strb r5, [r4, #0x13]
	b _0803FE92
_0803FDB0:
	bl sub_0804070C
	ldr r1, _0803FDC0 @ =0x03000440
	ldrb r0, [r1, #0x1a]
	cmp r0, #0xff
	beq _0803FDD0
	b _0803FE5A
	.align 2, 0
_0803FDC0: .4byte 0x03000440
_0803FDC4:
	bl sub_080407A4
	ldr r1, _0803FDD8 @ =0x03000440
	ldrb r0, [r1, #0x1a]
	cmp r0, #0xff
	bne _0803FE5A
_0803FDD0:
	movs r0, #0
	strb r0, [r1, #0x13]
	b _0803FE92
	.align 2, 0
_0803FDD8: .4byte 0x03000440
_0803FDDC:
	bl sub_0803FEB8
	b _0803FE58
_0803FDE2:
	bl update_text_compose_and_input
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0803FE92
	ldr r1, _0803FDF8 @ =0x03000440
	ldrh r0, [r1, #0xc]
	adds r0, #1
	strh r0, [r1, #0xc]
	b _0803FE92
	.align 2, 0
_0803FDF8: .4byte 0x03000440
_0803FDFC:
	ldr r4, _0803FE18 @ =0x03000440
	ldrb r0, [r4, #0x19]
	cmp r0, #2
	bne _0803FE1C
	movs r0, #1
	strb r0, [r4, #0x13]
	bl update_text_compose_and_input
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0803FE92
	b _0803FE2A
	.align 2, 0
_0803FE18: .4byte 0x03000440
_0803FE1C:
	movs r0, #0
	strb r0, [r4, #0x13]
	bl reset_text_tile_state
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	bne _0803FE92
_0803FE2A:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	b _0803FE92
_0803FE32:
	bl sub_0803FEA8
	b _0803FE92
_0803FE38:
	ldr r2, _0803FE50 @ =0x03000440
	adds r3, r2, #0
	adds r3, #0x27
	ldrb r0, [r3]
	movs r1, #1
	eors r0, r1
	strb r0, [r3]
	ldrh r0, [r2, #0xc]
	adds r0, #1
	strh r0, [r2, #0xc]
	b _0803FE92
	.align 2, 0
_0803FE50: .4byte 0x03000440
_0803FE54:
	bl sub_08040820
_0803FE58:
	ldr r1, _0803FE60 @ =0x03000440
_0803FE5A:
	movs r0, #1
	strb r0, [r1, #0x13]
	b _0803FE92
	.align 2, 0
_0803FE60: .4byte 0x03000440
_0803FE64:
	ldrb r0, [r5, #0x19]
	cmp r0, #1
	bne _0803FE74
	movs r0, #0
	strb r0, [r5, #0x13]
	bl reset_text_tile_state
	b _0803FE92
_0803FE74:
	cmp r0, #2
	bne _0803FE82
	movs r0, #1
	strb r0, [r5, #0x13]
	bl update_text_compose_and_input
	b _0803FE92
_0803FE82:
	movs r4, #0
	strb r4, [r5, #0x13]
	bl text_render_glyph_step
	ldrb r0, [r5, #0x1a]
	cmp r0, #0xff
	bne _0803FE92
	strb r4, [r5, #0x13]
_0803FE92:
	ldr r0, _0803FEA4 @ =0x03000440
	ldrb r1, [r0, #0x13]
	adds r5, r0, #0
	cmp r1, #0
	bne _0803FE9E
	b _0803FD32
_0803FE9E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803FEA4: .4byte 0x03000440
	.syntax divided
