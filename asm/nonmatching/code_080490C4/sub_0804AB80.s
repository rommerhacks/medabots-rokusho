	.syntax unified

	thumb_func_start sub_0804AB80
sub_0804AB80: @ 0x0804AB80
	push {lr}
	ldr r0, _0804AB98 @ =0x030057E0
	ldr r1, _0804AB9C @ =0x00000C5C
	adds r2, r0, r1
	ldrb r1, [r2]
	cmp r1, #2
	beq _0804ABA4
	ldr r3, _0804ABA0 @ =0x00000C69
	adds r0, r0, r3
	strb r1, [r0]
	movs r0, #2
	b _0804ABAA
	.align 2, 0
_0804AB98: .4byte 0x030057E0
_0804AB9C: .4byte 0x00000C5C
_0804ABA0: .4byte 0x00000C69
_0804ABA4:
	ldr r1, _0804ABC4 @ =0x00000C69
	adds r0, r0, r1
	ldrb r0, [r0]
_0804ABAA:
	strb r0, [r2]
	movs r0, #0
	bl load_battle_palette_via_dma
	movs r0, #8
	movs r1, #0
	bl dispatch_jump_table_29
	bl sub_0804A1C4
	pop {r0}
	bx r0
	.align 2, 0
_0804ABC4: .4byte 0x00000C69
	.syntax divided
