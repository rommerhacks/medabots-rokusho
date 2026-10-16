	.syntax unified

	thumb_func_start load_battle_script_data_d0
load_battle_script_data_d0: @ 0x0801CB24
	push {r4, r5, lr}
	ldr r1, _0801CB68 @ =0x083C6DE8
	ldr r5, _0801CB6C @ =0x03001800
	adds r0, r5, #0
	adds r0, #0xd0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _0801CB70 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	adds r4, #0x14
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #0x35
	bl divide_by_100000_b
	adds r1, r5, #0
	adds r1, #0xa6
	movs r0, #0x12
	strb r0, [r1]
	adds r1, #4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801CB68: .4byte 0x083C6DE8
_0801CB6C: .4byte 0x03001800
_0801CB70: .4byte 0x030004DE
	.syntax divided
