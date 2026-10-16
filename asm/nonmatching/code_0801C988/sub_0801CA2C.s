	.syntax unified

	thumb_func_start sub_0801CA2C
sub_0801CA2C: @ 0x0801CA2C
	push {lr}
	ldr r0, _0801CA4C @ =0x03002C30
	ldr r2, _0801CA50 @ =0x00000848
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #8
	bne _0801CA58
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0801CA54 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0801CA5A
	.align 2, 0
_0801CA4C: .4byte 0x03002C30
_0801CA50: .4byte 0x00000848
_0801CA54: .4byte 0x03001800
_0801CA58:
	subs r0, #8
_0801CA5A:
	strb r0, [r1]
	pop {r0}
	bx r0
	.syntax divided
