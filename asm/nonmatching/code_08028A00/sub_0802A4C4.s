	.syntax unified

	thumb_func_start sub_0802A4C4
sub_0802A4C4: @ 0x0802A4C4
	push {r4, r5, r6, lr}
	movs r4, #0
	movs r3, #0
	ldr r5, _0802A520 @ =0x030018D2
	ldr r0, _0802A524 @ =0x03002C30
	ldr r1, _0802A528 @ =0x000008C8
	adds r2, r0, r1
_0802A4D2:
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A4FC
	ldrh r0, [r2, #0x10]
	adds r0, #0x20
	ldr r6, _0802A52C @ =0x000003FF
	adds r1, r6, #0
	ands r0, r1
	strh r0, [r2, #0x10]
	ldrb r0, [r2]
	subs r0, #4
	strb r0, [r2]
	ldrb r0, [r2, #1]
	subs r0, #4
	strb r0, [r2, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _0802A4FC
	movs r4, #1
_0802A4FC:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802A4D2
	cmp r4, #0
	beq _0802A51A
	movs r0, #0x24
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _0802A530 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802A51A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802A520: .4byte 0x030018D2
_0802A524: .4byte 0x03002C30
_0802A528: .4byte 0x000008C8
_0802A52C: .4byte 0x000003FF
_0802A530: .4byte 0x03001800
	.syntax divided
