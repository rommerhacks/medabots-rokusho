	.syntax unified

	thumb_func_start sub_08026F6C
sub_08026F6C: @ 0x08026F6C
	push {r4, r5, lr}
	ldr r4, _08026FAC @ =0x03001800
	adds r5, r4, #0
	adds r5, #0xca
	ldrh r0, [r5]
	cmp r0, #0
	beq _08026FB0
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl clear_ewram_buffer_02023000_b
	cmp r0, #0
	beq _08026FB0
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xd0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x8b
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	ldrb r1, [r1]
	ldrh r2, [r5]
	bl battle_calc_damage_split
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x10
	b _08026FB8
	.align 2, 0
_08026FAC: .4byte 0x03001800
_08026FB0:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_08026FB8:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
_08026FC0:
	.byte 0x02, 0x48, 0xAA, 0x30, 0x04, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00, 0x00, 0x18, 0x00, 0x03
	.syntax divided
