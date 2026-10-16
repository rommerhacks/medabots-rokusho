	.syntax unified

	thumb_func_start swap_inventory_items
swap_inventory_items: @ 0x0805B448
	push {lr}
	ldr r0, _0805B468 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #0x13]
	lsls r0, r0, #1
	ldr r2, _0805B46C @ =0x03002BA0
	adds r0, r0, r2
	ldrb r1, [r1, #0xc]
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #2
	bl memswap
	pop {r0}
	bx r0
	.align 2, 0
_0805B468: .4byte 0x03006F74
_0805B46C: .4byte 0x03002BA0
	.syntax divided
