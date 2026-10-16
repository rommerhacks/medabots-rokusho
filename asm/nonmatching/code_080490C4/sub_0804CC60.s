	.syntax unified

	thumb_func_start sub_0804CC60
sub_0804CC60: @ 0x0804CC60
	push {r4, r5, r6, lr}
	ldr r4, _0804CC98 @ =0x030057E0
	ldr r0, _0804CC9C @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CCA0 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #2
	bl read_map_script_bytes
	movs r0, #0xff
	bl get_entity_speed_fraction
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0
	beq _0804CC90
	ldr r0, _0804CCA4 @ =0x00000C96
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CC90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CC98: .4byte 0x030057E0
_0804CC9C: .4byte 0x00000C8A
_0804CCA0: .4byte 0x00000C8C
_0804CCA4: .4byte 0x00000C96
	.syntax divided
