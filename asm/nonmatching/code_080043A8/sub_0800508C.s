	.syntax unified

	thumb_func_start sub_0800508C
	.global sub_0800508C
sub_0800508C: @ 0x0800508C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r6, #0
	ldr r0, _080050D0 @ =0x0400000A
	mov r8, r0
	ldr r5, _080050D4 @ =0x083AC44D
	movs r7, #0x83
	lsls r7, r7, #8
_080050A0:
	ldr r0, _080050D8 @ =0x030017A0
	lsls r1, r6, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080050F2
	ldrb r0, [r1, #6]
	cmp r0, #0x77
	bhi _080050E0
	ldr r4, _080050DC @ =0x0300052E
	movs r1, #3
	adds r2, r4, #0
	bl load_part_data
	ldrb r0, [r4, #1]
	subs r0, #0x64
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	mov r4, r8
	ldrh r3, [r4]
	str r7, [sp]
	bl draw_tilemap_with_offset
	b _08005102
	.align 2, 0
_080050D0: .4byte 0x0400000A
_080050D4: .4byte 0x083AC44D
_080050D8: .4byte 0x030017A0
_080050DC: .4byte 0x0300052E
_080050E0:
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	mov r0, r8
	ldrh r3, [r0]
	str r7, [sp]
	movs r0, #0xff
	bl draw_tilemap_with_offset
	b _08005102
_080050F2:
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	mov r4, r8
	ldrh r3, [r4]
	str r7, [sp]
	movs r0, #0xff
	bl draw_tilemap_with_offset
_08005102:
	adds r5, #2
	adds r6, #1
	cmp r6, #8
	bls _080050A0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
