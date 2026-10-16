	.syntax unified

	thumb_func_start sub_0801DFE0
sub_0801DFE0: @ 0x0801DFE0
	push {r4, r5, lr}
	ldr r0, _0801DFF8 @ =0x03000440
	ldr r1, _0801DFFC @ =0x00000139
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #1
	beq _0801E050
	cmp r0, #1
	bgt _0801E000
	cmp r0, #0
	beq _0801E006
	b _0801E088
	.align 2, 0
_0801DFF8: .4byte 0x03000440
_0801DFFC: .4byte 0x00000139
_0801E000:
	cmp r0, #2
	beq _0801E06C
	b _0801E088
_0801E006:
	ldr r0, _0801E030 @ =0x06002800
	ldr r1, _0801E034 @ =0x02020800
	movs r4, #0x80
	lsls r4, r4, #2
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801E038 @ =0x0600C800
	ldr r1, _0801E03C @ =0x02021000
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801E040 @ =0x0600D000
	ldr r1, _0801E044 @ =0x02021800
	adds r2, r4, #0
	bl CpuFastSet
	ldr r0, _0801E048 @ =0x0600D800
	ldr r1, _0801E04C @ =0x02022000
	adds r2, r4, #0
	b _0801E058
	.align 2, 0
_0801E030: .4byte 0x06002800
_0801E034: .4byte 0x02020800
_0801E038: .4byte 0x0600C800
_0801E03C: .4byte 0x02021000
_0801E040: .4byte 0x0600D000
_0801E044: .4byte 0x02021800
_0801E048: .4byte 0x0600D800
_0801E04C: .4byte 0x02022000
_0801E050:
	ldr r0, _0801E064 @ =0x03002C30
	ldr r1, _0801E068 @ =0x02028000
	movs r2, #0x80
	lsls r2, r2, #4
_0801E058:
	bl CpuFastSet
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0801E088
	.align 2, 0
_0801E064: .4byte 0x03002C30
_0801E068: .4byte 0x02028000
_0801E06C:
	ldr r1, _0801E090 @ =0x030017F0
	ldr r0, _0801E094 @ =0x08000841
	str r0, [r1]
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r0, #0
	strb r0, [r5]
	ldr r1, _0801E098 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801E088:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801E090: .4byte 0x030017F0
_0801E094: .4byte 0x08000841
_0801E098: .4byte 0x03001800
	.syntax divided
