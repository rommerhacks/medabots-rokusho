	.syntax unified

	thumb_func_start init_battle_background_layers
init_battle_background_layers: @ 0x080691F8
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _08069260 @ =0x03006F90
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08069264 @ =0x06004000
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r3, #9
	bl decompress_indexed_asset
	ldr r6, _08069268 @ =0x08486160
	ldr r5, _0806926C @ =0x03006FDC
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #4]
	ldr r2, _08069270 @ =0x06004800
	str r4, [sp]
	movs r1, #0
	movs r3, #0xa
	bl decompress_indexed_asset
	ldrb r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #8]
	ldr r2, _08069274 @ =0x06005000
	str r4, [sp]
	movs r1, #0
	movs r3, #0xb
	bl decompress_indexed_asset
	ldr r1, _08069278 @ =0x0400000C
	ldr r2, _0806927C @ =0x00001E02
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08069280 @ =0x0300057C
	ldr r0, _08069284 @ =0x0000FFE8
	strh r0, [r1]
	subs r0, #0x48
	strh r0, [r1, #2]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08069260: .4byte 0x03006F90
_08069264: .4byte 0x06004000
_08069268: .4byte 0x08486160
_0806926C: .4byte 0x03006FDC
_08069270: .4byte 0x06004800
_08069274: .4byte 0x06005000
_08069278: .4byte 0x0400000C
_0806927C: .4byte 0x00001E02
_08069280: .4byte 0x0300057C
_08069284: .4byte 0x0000FFE8
	.syntax divided
