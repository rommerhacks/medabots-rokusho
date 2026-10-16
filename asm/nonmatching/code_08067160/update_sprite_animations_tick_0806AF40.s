	.syntax unified

	thumb_func_start update_sprite_animations_tick_0806AF40
update_sprite_animations_tick_0806AF40: @ 0x0806AF40
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r7, _0806AF70 @ =0x08485D30
_0806AF46:
	ldr r0, _0806AF74 @ =0x03002C30
	lsls r1, r6, #6
	adds r5, r1, r0
	adds r4, r5, #0
	adds r4, #0x20
	ldrb r0, [r4]
	cmp r0, #0
	beq _0806AF8A
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	cmp r0, #0
	beq _0806AF78
	ldrh r0, [r5, #0x1a]
	adds r0, #1
	strh r0, [r5, #0x1a]
	b _0806AF8A
	.align 2, 0
_0806AF70: .4byte 0x08485D30
_0806AF74: .4byte 0x03002C30
_0806AF78:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0806AF8A
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
_0806AF8A:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x13
	bls _0806AF46
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806AF9C:
	.byte 0x00, 0x20, 0x70, 0x47
	.syntax divided
