	.syntax unified

	thumb_func_start sub_0801C660
sub_0801C660: @ 0x0801C660
	push {r4, lr}
	movs r2, #3
	ldr r4, _0801C684 @ =0x03001800
	ldr r1, _0801C688 @ =0x03000590
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, #0xa1
	adds r3, r4, #0
	adds r3, #0xd0
_0801C678:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801C68C
	strb r2, [r3]
	b _0801C694
	.align 2, 0
_0801C684: .4byte 0x03001800
_0801C688: .4byte 0x03000590
_0801C68C:
	subs r1, #0x18
	subs r2, #1
	cmp r2, #0
	bge _0801C678
_0801C694:
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd0
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0x89
	ldrb r2, [r2]
	lsls r2, r2, #3
	adds r2, r2, r4
	adds r2, #0x2d
	ldrb r2, [r2]
	bl battle_set_damage_vs_armor
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
