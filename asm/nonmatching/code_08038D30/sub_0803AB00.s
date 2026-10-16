	.syntax unified

	thumb_func_start sub_0803AB00
sub_0803AB00: @ 0x0803AB00
	push {r4, lr}
	bl load_battle_sequence_commands
	ldr r0, _0803AB2C @ =0x03001800
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r4, #0
	bne _0803AB3C
	bl copy_obj_palette_to_buffer
	ldr r0, _0803AB30 @ =0x03002C30
	ldr r2, _0803AB34 @ =0x000009EF
	adds r1, r0, r2
	strb r4, [r1]
	ldr r4, _0803AB38 @ =0x000009E9
	adds r0, r0, r4
	movs r1, #0x28
	b _0803AB44
	.align 2, 0
_0803AB2C: .4byte 0x03001800
_0803AB30: .4byte 0x03002C30
_0803AB34: .4byte 0x000009EF
_0803AB38: .4byte 0x000009E9
_0803AB3C:
	ldr r0, _0803AB8C @ =0x03002C30
	ldr r1, _0803AB90 @ =0x000009E9
	adds r0, r0, r1
	movs r1, #0x29
_0803AB44:
	strb r1, [r0]
	ldr r2, _0803AB8C @ =0x03002C30
	ldr r3, _0803AB94 @ =0x03001800
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r3, r4
	ldrh r1, [r0]
	ldr r4, _0803AB98 @ =0x000009EB
	adds r0, r2, r4
	strb r1, [r0]
	movs r1, #0x83
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrh r0, [r0]
	adds r4, #1
	adds r2, r2, r4
	strb r0, [r2]
	bl battle_advance_sequence_counter
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AB8C: .4byte 0x03002C30
_0803AB90: .4byte 0x000009E9
_0803AB94: .4byte 0x03001800
_0803AB98: .4byte 0x000009EB
	.syntax divided
