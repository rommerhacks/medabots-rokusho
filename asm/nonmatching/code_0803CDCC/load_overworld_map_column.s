	.syntax unified

	thumb_func_start load_overworld_map_column
	.global load_overworld_map_column
load_overworld_map_column: @ 0x0803F51C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r6, [sp, #0x2c]
	add r0, sp, #0xc
	strb r4, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r7, _0803F5AC @ =0x03000440
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	bne _0803F57E
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0803F5B0 @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0803F5B4 @ =0x083AFD08
	lsls r0, r4, #3
	adds r0, r0, r4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803F5B8 @ =0x06000F80
	bl lz_decompress_dispatch
	ldr r1, _0803F5BC @ =0x083B15C8
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803F5C0 @ =0x050001A0
	movs r2, #8
	bl CpuFastSet
_0803F57E:
	ldr r3, [sp, #0x30]
	cmp r3, #0
	bne _0803F5C8
	ldr r1, _0803F5C4 @ =0x083B4AE0
	lsls r0, r6, #3
	adds r0, r0, r6
	ldrb r7, [r7, #0xe]
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _0803F5B0 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	str r3, [sp, #8]
	movs r0, #8
	movs r1, #8
	mov r2, r8
	mov r3, sb
	bl write_tilemap_rect
	b _0803F5F2
	.align 2, 0
_0803F5AC: .4byte 0x03000440
_0803F5B0: .4byte 0x04000008
_0803F5B4: .4byte 0x083AFD08
_0803F5B8: .4byte 0x06000F80
_0803F5BC: .4byte 0x083B15C8
_0803F5C0: .4byte 0x050001A0
_0803F5C4: .4byte 0x083B4AE0
_0803F5C8:
	ldr r2, _0803F608 @ =0x083B4AE0
	lsls r0, r6, #3
	adds r0, r0, r6
	ldrb r1, [r7, #0xe]
	subs r1, #8
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _0803F60C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #8
	mov r2, r8
	mov r3, sb
	bl write_tilemap_rect
_0803F5F2:
	ldr r1, _0803F610 @ =0x03000440
	ldrb r0, [r1, #0xe]
	adds r0, #1
	strb r0, [r1, #0xe]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	beq _0803F614
	movs r0, #0
	b _0803F616
	.align 2, 0
_0803F608: .4byte 0x083B4AE0
_0803F60C: .4byte 0x04000008
_0803F610: .4byte 0x03000440
_0803F614:
	movs r0, #1
_0803F616:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
