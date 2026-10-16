	.syntax unified

	thumb_func_start load_battle_sprite_tiles
	.global load_battle_sprite_tiles
load_battle_sprite_tiles: @ 0x0805B03C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r1, #1
	beq _0805B068
	cmp r1, #1
	bgt _0805B050
	cmp r1, #0
	beq _0805B05A
	b _0805B0B6
_0805B050:
	cmp r1, #2
	beq _0805B078
	cmp r1, #3
	beq _0805B09C
	b _0805B0B6
_0805B05A:
	ldr r2, _0805B064 @ =0x083B1888
	lsls r0, r4, #2
	lsls r1, r4, #1
	adds r0, r0, r1
	b _0805B082
	.align 2, 0
_0805B064: .4byte 0x083B1888
_0805B068:
	ldr r2, _0805B074 @ =0x083B1888
	lsls r0, r4, #2
	lsls r1, r4, #1
	adds r0, r0, r1
	adds r0, #1
	b _0805B082
	.align 2, 0
_0805B074: .4byte 0x083B1888
_0805B078:
	ldr r2, _0805B094 @ =0x083B1888
	lsls r0, r4, #2
	lsls r1, r4, #1
	adds r0, r0, r1
	adds r0, #3
_0805B082:
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r5, #7
	ldr r2, _0805B098 @ =0x06013340
	adds r1, r1, r2
	bl lz_decompress_dispatch
	b _0805B0B6
	.align 2, 0
_0805B094: .4byte 0x083B1888
_0805B098: .4byte 0x06013340
_0805B09C:
	ldr r2, _0805B0D0 @ =0x083B1888
	lsls r0, r4, #2
	lsls r1, r4, #1
	adds r0, r0, r1
	adds r0, #5
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r5, #7
	ldr r2, _0805B0D4 @ =0x06013340
	adds r1, r1, r2
	bl lz_decompress_dispatch
_0805B0B6:
	ldr r0, _0805B0D8 @ =0x03002C30
	adds r1, r5, #0
	adds r1, #0x6e
	lsls r1, r1, #6
	adds r1, r1, r0
	ldr r0, _0805B0DC @ =0x083BEA14
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r0, #4
	strb r0, [r1, #0xa]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805B0D0: .4byte 0x083B1888
_0805B0D4: .4byte 0x06013340
_0805B0D8: .4byte 0x03002C30
_0805B0DC: .4byte 0x083BEA14
	.syntax divided
