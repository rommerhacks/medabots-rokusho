	.syntax unified

	thumb_func_start sub_08031048
sub_08031048: @ 0x08031048
	push {lr}
	ldr r0, _08031080 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x5a
	bne _08031096
	ldr r0, _08031084 @ =0x03002C30
	ldr r2, _08031088 @ =0x00000849
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #8
	bne _08031090
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0803108C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0803109A
	.align 2, 0
_08031080: .4byte 0x03000440
_08031084: .4byte 0x03002C30
_08031088: .4byte 0x00000849
_0803108C: .4byte 0x0300137C
_08031090:
	subs r0, #8
	strb r0, [r1]
	b _0803109A
_08031096:
	adds r0, #1
	strh r0, [r1]
_0803109A:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
