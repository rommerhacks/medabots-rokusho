	.syntax unified

	thumb_func_start sub_0804CB48
sub_0804CB48: @ 0x0804CB48
	push {r4, r5, r6, lr}
	ldr r4, _0804CB7C @ =0x030057E0
	ldr r0, _0804CB80 @ =0x00000C8A
	adds r6, r4, r0
	ldrh r0, [r6]
	ldr r1, _0804CB84 @ =0x00000C8C
	adds r5, r4, r1
	strh r0, [r5]
	movs r0, #1
	bl read_map_script_bytes
	ldr r0, _0804CB88 @ =0x03005310
	adds r0, #0x39
	ldrb r0, [r0]
	cmp r0, #2
	bne _0804CB74
	ldr r0, _0804CB8C @ =0x00000C94
	adds r1, r4, r0
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6]
_0804CB74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804CB7C: .4byte 0x030057E0
_0804CB80: .4byte 0x00000C8A
_0804CB84: .4byte 0x00000C8C
_0804CB88: .4byte 0x03005310
_0804CB8C: .4byte 0x00000C94
	.syntax divided
