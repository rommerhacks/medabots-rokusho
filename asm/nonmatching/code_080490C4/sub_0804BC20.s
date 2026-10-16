	.syntax unified

	thumb_func_start sub_0804BC20
sub_0804BC20: @ 0x0804BC20
	push {r4, r5, lr}
	ldr r4, _0804BC80 @ =0x030057E0
	ldr r0, _0804BC84 @ =0x00000CB4
	adds r5, r4, r0
	ldrb r1, [r5]
	lsls r1, r1, #3
	adds r1, r1, r4
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r1, r1, r3
	ldrb r2, [r1]
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	adds r0, r0, r3
	ldrb r1, [r0]
	lsls r0, r1, #0x19
	cmp r0, #0
	bge _0804BC7A
	lsls r0, r1, #0x1b
	lsrs r0, r0, #3
	movs r1, #0xc4
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r1, #0xb6
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
_0804BC7A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804BC80: .4byte 0x030057E0
_0804BC84: .4byte 0x00000CB4
	.syntax divided
