	.syntax unified

	thumb_func_start sub_0804BC88
sub_0804BC88: @ 0x0804BC88
	push {lr}
	movs r0, #2
	bl read_map_script_bytes
	ldr r0, _0804BCB4 @ =0x030057E0
	ldr r2, _0804BCB8 @ =0x00000C94
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	orrs r0, r1
	bl battle_find_entity_by_id
	cmp r0, #0
	beq _0804BCAE
	bl sub_0804D934
_0804BCAE:
	pop {r0}
	bx r0
	.align 2, 0
_0804BCB4: .4byte 0x030057E0
_0804BCB8: .4byte 0x00000C94
	.syntax divided
