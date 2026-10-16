	.syntax unified

	thumb_func_start find_map_event_by_coords
	.global find_map_event_by_coords
find_map_event_by_coords: @ 0x08052C1C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r3, #0
	ldr r1, _08052C64 @ =0x08413114
	ldr r0, _08052C68 @ =0x030057E0
	ldr r2, _08052C6C @ =0x000007FE
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _08052C5C
	ldr r7, _08052C70 @ =0x03006D38
	movs r6, #0xf0
_08052C3E:
	ldrb r0, [r1]
	ldrb r2, [r1, #1]
	cmp r0, r5
	bne _08052C54
	cmp r2, r4
	bne _08052C54
	movs r3, #1
	ldrb r0, [r1, #3]
	ands r0, r6
	asrs r0, r0, #4
	strb r0, [r7, #3]
_08052C54:
	adds r1, #8
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _08052C3E
_08052C5C:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08052C64: .4byte 0x08413114
_08052C68: .4byte 0x030057E0
_08052C6C: .4byte 0x000007FE
_08052C70: .4byte 0x03006D38
	.syntax divided
