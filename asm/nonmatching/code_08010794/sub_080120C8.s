	.syntax unified

	thumb_func_start sub_080120C8
	.global sub_080120C8
sub_080120C8: @ 0x080120C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r6, #0
	ldr r0, _0801210C @ =0x03001800
	mov sb, r0
	ldr r5, _08012110 @ =0x083ACEEA
	mov r7, sb
	ldr r1, _08012114 @ =0x0300052E
	mov r8, r1
_080120E0:
	mov r1, sb
	ldrb r0, [r1, #2]
	cmp r0, r6
	bls _0801211C
	ldrb r0, [r7, #7]
	movs r1, #3
	mov r2, r8
	bl load_part_data
	mov r1, r8
	ldrb r0, [r1, #1]
	subs r0, #0x64
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldr r3, _08012118 @ =0x04000008
	ldrh r3, [r3]
	movs r4, #0x83
	lsls r4, r4, #8
	str r4, [sp]
	bl draw_tilemap_with_offset
	b _08012130
	.align 2, 0
_0801210C: .4byte 0x03001800
_08012110: .4byte 0x083ACEEA
_08012114: .4byte 0x0300052E
_08012118: .4byte 0x04000008
_0801211C:
	ldrb r1, [r5]
	ldrb r2, [r5, #1]
	ldr r0, _08012148 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0x83
	lsls r0, r0, #8
	str r0, [sp]
	movs r0, #0xff
	bl draw_tilemap_with_offset
_08012130:
	adds r5, #2
	adds r7, #0xc
	adds r6, #1
	cmp r6, #2
	bls _080120E0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08012148: .4byte 0x04000008
	.syntax divided
