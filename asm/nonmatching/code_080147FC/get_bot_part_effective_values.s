	.syntax unified

	thumb_func_start get_bot_part_effective_values
	.global get_bot_part_effective_values
get_bot_part_effective_values: @ 0x08015838
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	ldr r0, _08015858 @ =0x03000590
	lsls r1, r4, #8
	adds r3, r1, r0
	adds r1, r3, #0
	adds r1, #0x59
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #0
	beq _0801585C
	adds r0, r3, #0
	adds r0, #0x5f
	ldrb r0, [r0]
	b _08015864
	.align 2, 0
_08015858: .4byte 0x03000590
_0801585C:
	adds r0, r3, #0
	adds r0, #0x41
	ldrb r0, [r0]
	adds r0, #0x78
_08015864:
	strb r0, [r2]
	adds r2, #1
	lsls r1, r4, #8
	adds r3, r1, r5
	adds r0, r3, #0
	adds r0, #0x71
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801587E
	adds r0, r3, #0
	adds r0, #0x77
	ldrb r0, [r0]
	b _08015886
_0801587E:
	adds r0, r3, #0
	adds r0, #0x41
	ldrb r0, [r0]
	adds r0, #0x78
_08015886:
	strb r0, [r2]
	adds r2, #1
	adds r3, r1, r5
	adds r0, r3, #0
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801589E
	adds r0, r3, #0
	adds r0, #0x8f
	ldrb r0, [r0]
	b _080158A6
_0801589E:
	adds r0, r3, #0
	adds r0, #0x41
	ldrb r0, [r0]
	adds r0, #0x78
_080158A6:
	strb r0, [r2]
	adds r2, #1
	adds r1, r1, r5
	adds r0, r1, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080158BE
	adds r0, r1, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	b _080158C6
_080158BE:
	adds r0, r1, #0
	adds r0, #0x41
	ldrb r0, [r0]
	adds r0, #0x78
_080158C6:
	strb r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
