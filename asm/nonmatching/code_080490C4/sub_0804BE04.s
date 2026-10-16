	.syntax unified

	thumb_func_start sub_0804BE04
sub_0804BE04: @ 0x0804BE04
	push {r4, r5, r6, lr}
	ldr r4, _0804BE58 @ =0x030057E0
	ldr r1, _0804BE5C @ =0x00000CB4
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r5, r0, #3
	adds r3, r5, r4
	ldr r6, _0804BE60 @ =0x000005DE
	adds r0, r3, r6
	ldrh r2, [r0]
	ldr r0, _0804BE64 @ =0x00000FFF
	ldr r6, _0804BE68 @ =0x00000C8E
	adds r1, r4, r6
	ands r0, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _0804BE52
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r3, #0xc4
	lsls r3, r3, #0x16
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	ldr r2, _0804BE6C @ =0x083D24AC
	ldr r1, _0804BE70 @ =0x03002C30
	subs r6, #0xad
	adds r1, r1, r6
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r1, [r1]
	ldr r3, _0804BE74 @ =0x000005DC
	adds r2, r4, r3
	adds r2, r5, r2
	bl set_sprite_anim_and_store
_0804BE52:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BE58: .4byte 0x030057E0
_0804BE5C: .4byte 0x00000CB4
_0804BE60: .4byte 0x000005DE
_0804BE64: .4byte 0x00000FFF
_0804BE68: .4byte 0x00000C8E
_0804BE6C: .4byte 0x083D24AC
_0804BE70: .4byte 0x03002C30
_0804BE74: .4byte 0x000005DC
	.syntax divided
