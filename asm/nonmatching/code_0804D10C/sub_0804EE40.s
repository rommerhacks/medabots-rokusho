	.syntax unified

	thumb_func_start sub_0804EE40
sub_0804EE40: @ 0x0804EE40
	push {r4, r5, r6, lr}
	ldr r4, _0804EE58 @ =0x030057E0
	ldr r0, _0804EE5C @ =0x00000C93
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, #1
	beq _0804EEB0
	cmp r0, #1
	bgt _0804EE60
	cmp r0, #0
	beq _0804EE6A
	b _0804EF04
	.align 2, 0
_0804EE58: .4byte 0x030057E0
_0804EE5C: .4byte 0x00000C93
_0804EE60:
	cmp r0, #2
	beq _0804EECC
	cmp r0, #3
	beq _0804EEF0
	b _0804EF04
_0804EE6A:
	bl init_cursor_state
	movs r0, #0xe
	bl sub_08047BA8
	ldr r1, _0804EE98 @ =0x00000C94
	adds r5, r4, r1
	ldrb r0, [r5]
	bl sub_08047BCC
	adds r1, r0, #0
	movs r0, #0
	bl copy_string_to_text_buffer
	ldrb r0, [r5]
	bl sub_08047DB0
	cmp r0, #0
	beq _0804EE9C
	movs r0, #1
	strb r0, [r6]
	b _0804EF04
	.align 2, 0
_0804EE98: .4byte 0x00000C94
_0804EE9C:
	ldr r4, _0804EEAC @ =0x030017EC
	ldrb r0, [r5]
	bl sub_08047E20
	strb r0, [r4]
	movs r0, #2
	strb r0, [r6]
	b _0804EF04
	.align 2, 0
_0804EEAC: .4byte 0x030017EC
_0804EEB0:
	ldr r0, _0804EEC8 @ =0x0847E8C4
	ldr r3, [r0, #0x70]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EF04
	bl sub_08050244
	b _0804EF04
	.align 2, 0
_0804EEC8: .4byte 0x0847E8C4
_0804EECC:
	ldr r0, _0804EEEC @ =0x0847E8C4
	ldr r3, [r0, #0x74]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _0804EF04
	bl sub_08050C74
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _0804EF04
	.align 2, 0
_0804EEEC: .4byte 0x0847E8C4
_0804EEF0:
	ldr r1, _0804EF0C @ =0x00000C94
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	bl scene_state_dispatch
	cmp r0, #0
	beq _0804EF04
	bl sub_08050244
_0804EF04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804EF0C: .4byte 0x00000C94
	.syntax divided
