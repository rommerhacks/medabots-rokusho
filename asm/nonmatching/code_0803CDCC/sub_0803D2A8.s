	.syntax unified

	thumb_func_start sub_0803D2A8
sub_0803D2A8: @ 0x0803D2A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0
	ldr r0, _0803D2D4 @ =0x03002C30
	mov r8, r0
	ldr r0, _0803D2D8 @ =0x03000440
	ldr r1, _0803D2DC @ =0x0000012F
	adds r7, r0, r1
	ldrb r0, [r7]
	lsls r0, r0, #6
	mov r2, r8
	adds r1, r0, r2
	adds r2, r1, #0
	adds r2, #0x2b
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803D2E0
	subs r0, #1
	strb r0, [r2]
	b _0803D3B0
	.align 2, 0
_0803D2D4: .4byte 0x03002C30
_0803D2D8: .4byte 0x03000440
_0803D2DC: .4byte 0x0000012F
_0803D2E0:
	adds r0, r1, #0
	adds r0, #0x2e
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803D330
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	bl sub_080362C4
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2d
	ldrb r0, [r0]
	bl sub_08036340
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2d
	ldrb r0, [r0]
	ldr r4, _0803D348 @ =0x03001800
	adds r4, #0x87
	ldrb r1, [r4]
	bl sub_08036370
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2d
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl sub_080364A8
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2e
	strb r6, [r0]
_0803D330:
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r1, r0, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D34C
	subs r0, #1
	strb r0, [r1]
	b _0803D3B0
	.align 2, 0
_0803D348: .4byte 0x03001800
_0803D34C:
	ldr r4, _0803D3BC @ =0x030018D6
	adds r5, r4, #0
	subs r5, #0x4f
	ldrb r1, [r5]
	adds r0, r4, #0
	movs r2, #0
	bl sub_08036BB8
	adds r6, r0, #0
	adds r0, r4, #2
	ldrb r1, [r5]
	movs r2, #1
	bl sub_08036BB8
	adds r6, r6, r0
	adds r0, r4, #4
	ldrb r1, [r5]
	movs r2, #2
	bl sub_08036BB8
	adds r6, r6, r0
	adds r4, #6
	ldrb r1, [r5]
	adds r0, r4, #0
	movs r2, #3
	bl sub_08036BB8
	adds r6, r6, r0
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2d
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl sub_08036370
	ldrb r0, [r7]
	lsls r0, r0, #6
	add r0, r8
	adds r0, #0x2d
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl sub_080364A8
	cmp r6, #4
	bne _0803D3B0
	ldrb r0, [r7]
	movs r1, #1
	bl clear_battle_sprite_slot
_0803D3B0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D3BC: .4byte 0x030018D6
	.syntax divided
