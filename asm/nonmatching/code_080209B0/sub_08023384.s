	.syntax unified

	thumb_func_start sub_08023384
sub_08023384: @ 0x08023384
	push {r4, r5, lr}
	movs r3, #0
	ldr r5, _080233D4 @ =0x03002C30
	movs r4, #0x80
	lsls r4, r4, #8
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r5, r0
_08023394:
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080233AA
	ldrb r0, [r2, #8]
	subs r0, #8
	strb r0, [r2, #8]
	ldrb r0, [r2, #9]
	adds r0, #8
	strb r0, [r2, #9]
_080233AA:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _08023394
	ldr r1, _080233D8 @ =0x00000848
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080233CE
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r1, _080233DC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080233CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080233D4: .4byte 0x03002C30
_080233D8: .4byte 0x00000848
_080233DC: .4byte 0x03001800
	.syntax divided
