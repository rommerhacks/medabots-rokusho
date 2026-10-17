	.syntax unified

	thumb_func_start sub_080338F4
sub_080338F4: @ 0x080338F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	bl battle_script_load_operands
	bl battle_script_advance
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08033956
	ldr r0, _08033944 @ =0x083C6B28
	mov r8, r0
	ldr r5, _08033948 @ =0x03001800
	adds r7, r5, #0
	adds r7, #0xbc
	adds r6, r5, #0
	adds r6, #0xac
	mov r4, sp
_08033922:
	adds r0, r5, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	ldrh r0, [r7]
	adds r1, r1, r0
	ldrb r0, [r6]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0803394C
	bl battle_script_advance
	movs r0, #1
	strb r0, [r4]
	b _08033950
	.align 2, 0
_08033944: .4byte 0x083C6B28
_08033948: .4byte 0x03001800
_0803394C:
	bl battle_script_advance
_08033950:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08033922
_08033956:
	ldr r0, _0803396C @ =0x03001800
	ldr r2, _08033970 @ =0x00000163
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803396C: .4byte 0x03001800
_08033970: .4byte 0x00000163
	.syntax divided
