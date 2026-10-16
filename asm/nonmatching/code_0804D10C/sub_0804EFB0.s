	.syntax unified

	thumb_func_start sub_0804EFB0
sub_0804EFB0: @ 0x0804EFB0
	push {r4, r5, lr}
	ldr r4, _0804EFC8 @ =0x030057E0
	ldr r0, _0804EFCC @ =0x00000C93
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	beq _0804EFF4
	cmp r0, #1
	bgt _0804EFD0
	cmp r0, #0
	beq _0804EFD6
	b _0804F050
	.align 2, 0
_0804EFC8: .4byte 0x030057E0
_0804EFCC: .4byte 0x00000C93
_0804EFD0:
	cmp r0, #2
	beq _0804F024
	b _0804F050
_0804EFD6:
	ldr r0, _0804EFE4 @ =0x00007FFF
	ldr r1, _0804EFE8 @ =0x00000000
	ldr r2, _0804EFEC @ =0x42000000
	ldr r3, _0804EFF0 @ =0x41000000
	bl setup_palette_fade_to_color_with_obj
	b _0804F00C
	.align 2, 0
_0804EFE4: .4byte 0x00007FFF
_0804EFE8: .4byte 0x00000000
_0804EFEC: .4byte 0x42000000
_0804EFF0: .4byte 0x41000000
_0804EFF4:
	ldr r4, _0804F014 @ =0x00007FFF
	adds r0, r4, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804F050
	ldr r1, _0804F018 @ =0x42000000
	ldr r2, _0804F01C @ =0x00000000
	ldr r3, _0804F020 @ =0x41000000
	adds r0, r4, #0
	bl setup_palette_fade_to_color
_0804F00C:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0804F050
	.align 2, 0
_0804F014: .4byte 0x00007FFF
_0804F018: .4byte 0x42000000
_0804F01C: .4byte 0x00000000
_0804F020: .4byte 0x41000000
_0804F024:
	ldr r0, _0804F044 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804F050
	ldr r0, _0804F048 @ =0x00000C94
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F04C
	movs r0, #0
	strb r0, [r5]
	b _0804F050
	.align 2, 0
_0804F044: .4byte 0x00007FFF
_0804F048: .4byte 0x00000C94
_0804F04C:
	bl sub_08050244
_0804F050:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
