	.syntax unified

	thumb_func_start load_battlefield_data_to_buffer
	.global load_battlefield_data_to_buffer
load_battlefield_data_to_buffer: @ 0x0804387C
	push {r4, r5, lr}
	ldr r4, _080438AC @ =0x030057E0
	ldr r1, _080438B0 @ =0x000007FE
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #3
	ldr r1, _080438B4 @ =0x083BEA90
	adds r0, r0, r1
	ldr r5, _080438B8 @ =0x0300052E
	adds r1, r5, #0
	movs r2, #1
	bl memcpy_bytes_08041D04
	ldrb r1, [r5]
	ldr r2, _080438BC @ =0x00000C29
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r0, _080438C0 @ =0x00000C2B
	adds r4, r4, r0
	strb r2, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080438AC: .4byte 0x030057E0
_080438B0: .4byte 0x000007FE
_080438B4: .4byte 0x083BEA90
_080438B8: .4byte 0x0300052E
_080438BC: .4byte 0x00000C29
_080438C0: .4byte 0x00000C2B
	.syntax divided
