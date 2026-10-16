	.syntax unified

	thumb_func_start sub_0800E350
sub_0800E350: @ 0x0800E350
	push {r4, lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl toggle_sprite_hflip_by_frame
	ldr r0, _0800E36C @ =0x03000440
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0800E374
	ldr r4, _0800E370 @ =0x083BE3E4
	b _0800E376
	.align 2, 0
_0800E36C: .4byte 0x03000440
_0800E370: .4byte 0x083BE3E4
_0800E374:
	ldr r4, _0800E398 @ =0x083BE92C
_0800E376:
	bl sub_0800F6CC
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _0800E390
	ldr r1, _0800E39C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800E390:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800E398: .4byte 0x083BE92C
_0800E39C: .4byte 0x0300137C
	.syntax divided
