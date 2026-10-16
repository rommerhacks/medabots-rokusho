	.syntax unified

	thumb_func_start update_sprite_animation_position
	.global update_sprite_animation_position
update_sprite_animation_position: @ 0x0804422C
	push {r4, r5, r6, r7, lr}
	ldr r1, _080442A8 @ =0x03002C30
	lsls r0, r0, #6
	adds r0, r0, r1
	mov ip, r0
	mov r5, ip
	adds r5, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	beq _080442A2
	ldr r4, _080442AC @ =0x083C6DF8
	adds r1, r0, #0
	subs r1, #1
	lsls r1, r1, #8
	mov r7, ip
	adds r7, #0x25
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r1, r1, r0
	mov r6, ip
	adds r6, #0x27
	ldrb r3, [r6]
	movs r2, #3
	adds r0, r2, #0
	ands r0, r3
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	mov r3, ip
	strh r0, [r3, #4]
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #8
	ldrb r1, [r7]
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r6]
	ands r2, r1
	lsls r2, r2, #1
	adds r0, r0, r2
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	ldr r1, _080442B0 @ =0x000001FF
	ands r0, r1
	strh r0, [r3, #2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_080442A2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080442A8: .4byte 0x03002C30
_080442AC: .4byte 0x083C6DF8
_080442B0: .4byte 0x000001FF
	.syntax divided
