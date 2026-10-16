	.syntax unified

	thumb_func_start sub_0801D9DC
sub_0801D9DC: @ 0x0801D9DC
	push {r4, r5, r6, r7, lr}
	movs r7, #0
	ldr r2, _0801DA20 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _0801DA28
	ldr r2, _0801DA24 @ =0x03002C30
	adds r3, r6, #0
	adds r3, #0xde
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	subs r1, #2
	strh r1, [r0, #2]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0x78
	bgt _0801DA56
	b _0801DA54
	.align 2, 0
_0801DA20: .4byte 0x03001800
_0801DA24: .4byte 0x03002C30
_0801DA28:
	ldr r2, _0801DAE0 @ =0x03002C30
	adds r3, r6, #0
	adds r3, #0xde
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	adds r1, #2
	strh r1, [r0, #2]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xb2
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0x77
	ble _0801DA56
_0801DA54:
	movs r7, #1
_0801DA56:
	adds r5, r6, #0
	adds r5, #0xde
	ldrb r1, [r5]
	subs r1, #1
	lsls r0, r1, #2
	adds r0, #0x5a
	adds r2, r6, #0
	adds r2, #0xf8
	ldrb r3, [r2]
	movs r4, #1
	movs r2, #1
	ands r2, r3
	eors r2, r4
	bl update_battle_sprite_orbiting_positions
	cmp r7, #0
	beq _0801DADA
	ldr r2, _0801DAE0 @ =0x03002C30
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldr r1, _0801DAE4 @ =0x00001664
	adds r0, r0, r1
	movs r3, #0
	movs r1, #8
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldr r1, _0801DAE8 @ =0x00001665
	adds r0, r0, r1
	strb r3, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	subs r1, #0x25
	adds r0, r0, r1
	adds r0, r0, r2
	strh r3, [r0, #0x30]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, r0, r2
	movs r1, #0x78
	strh r1, [r0, #2]
	ldrb r0, [r5]
	adds r0, #0x71
	lsls r0, r0, #6
	adds r0, r0, r2
	strh r1, [r0, #2]
	ldrb r1, [r5]
	adds r1, #0x71
	lsls r1, r1, #6
	adds r1, r1, r2
	adds r0, r6, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r0, #0x72
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	strh r0, [r1, #4]
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801DADA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DAE0: .4byte 0x03002C30
_0801DAE4: .4byte 0x00001664
_0801DAE8: .4byte 0x00001665
	.syntax divided
