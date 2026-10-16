	.syntax unified

	thumb_func_start sub_0803C044
sub_0803C044: @ 0x0803C044
	push {r4, r5, lr}
	ldr r5, _0803C084 @ =0x03002C30
	ldr r0, _0803C088 @ =0x03000440
	ldr r1, _0803C08C @ =0x0000012F
	adds r4, r0, r1
	ldrb r2, [r4]
	lsls r0, r2, #6
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x2d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803C0BC
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r4]
	bl update_sprite_animation_position
	adds r0, r5, #0
	adds r0, #0xec
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803C094
	ldr r2, _0803C090 @ =0x03001800
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r1, [r0, #2]
	movs r3, #0xaa
	lsls r3, r3, #1
	b _0803C0A2
	.align 2, 0
_0803C084: .4byte 0x03002C30
_0803C088: .4byte 0x03000440
_0803C08C: .4byte 0x0000012F
_0803C090: .4byte 0x03001800
_0803C094:
	ldr r2, _0803C0B8 @ =0x03001800
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r1, [r0, #2]
	movs r3, #0xac
	lsls r3, r3, #1
_0803C0A2:
	adds r0, r2, r3
	strh r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r0, [r0, #4]
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	b _0803C0C4
	.align 2, 0
_0803C0B8: .4byte 0x03001800
_0803C0BC:
	adds r0, r2, #0
	movs r1, #1
	bl clear_battle_sprite_slot
_0803C0C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
