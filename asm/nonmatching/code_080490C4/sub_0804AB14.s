	.syntax unified

	thumb_func_start sub_0804AB14
sub_0804AB14: @ 0x0804AB14
	push {lr}
	ldr r0, _0804AB2C @ =0x030057E0
	ldr r1, _0804AB30 @ =0x00000C5C
	adds r2, r0, r1
	ldrb r1, [r2]
	cmp r1, #1
	beq _0804AB38
	ldr r3, _0804AB34 @ =0x00000C69
	adds r0, r0, r3
	strb r1, [r0]
	movs r0, #1
	b _0804AB3E
	.align 2, 0
_0804AB2C: .4byte 0x030057E0
_0804AB30: .4byte 0x00000C5C
_0804AB34: .4byte 0x00000C69
_0804AB38:
	ldr r1, _0804AB58 @ =0x00000C69
	adds r0, r0, r1
	ldrb r0, [r0]
_0804AB3E:
	strb r0, [r2]
	movs r0, #0
	bl load_battle_palette_via_dma
	movs r0, #7
	movs r1, #0
	bl dispatch_jump_table_29
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_0804AB58: .4byte 0x00000C69
_0804AB5C:
	.byte 0x03, 0x49, 0x00, 0x20
	.byte 0x48, 0x70, 0x03, 0x49, 0x05, 0x20, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x10, 0x53, 0x00, 0x03
	.byte 0x7C, 0x13, 0x00, 0x03
	.syntax divided
