	.syntax unified

	thumb_func_start find_next_available_medapart_slot
	.global find_next_available_medapart_slot
find_next_available_medapart_slot: @ 0x080436AC
	push {r4, lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, [sp, #8]
	cmp r0, #0
	beq _08043740
	ldr r0, [sp]
	cmp r0, #0
	bne _080436C6
	b _080437D4
_080436C6:
	ldr r4, _08043738 @ =0x0300054E
_080436C8:
	ldr r0, [sp]
	subs r0, #1
	str r0, [sp]
	ldr r0, [sp]
	cmp r0, #0x78
	bne _080436DA
	ldr r0, [sp]
	subs r0, #1
	str r0, [sp]
_080436DA:
	ldr r1, [sp, #4]
	ldr r0, [sp]
	adds r2, r4, #0
	bl load_part_data
	ldr r0, [sp, #0xc]
	ldrb r1, [r4, #3]
	cmp r0, r1
	bne _0804372E
	ldr r3, _0804373C @ =0x03004C40
	ldr r0, [sp, #4]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	ldr r0, [sp]
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804372E
	ldr r0, [sp, #4]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	ldr r0, [sp]
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r3
	ldrb r2, [r1]
	ldr r1, [sp, #4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	ldr r1, [sp]
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bne _080437D0
_0804372E:
	ldr r0, [sp]
	cmp r0, #0
	bne _080436C8
	b _080437D4
	.align 2, 0
_08043738: .4byte 0x0300054E
_0804373C: .4byte 0x03004C40
_08043740:
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _08043756
	ldr r0, [sp]
	cmp r0, #0x78
	bne _08043756
	movs r0, #0x79
	str r0, [sp]
_08043756:
	ldr r0, [sp, #0xc]
	adds r0, #0x79
	ldr r1, [sp]
	cmp r1, r0
	bne _08043764
	movs r0, #0
	str r0, [sp]
_08043764:
	ldr r0, [sp, #0xc]
	adds r0, #0x78
	ldr r1, [sp]
	cmp r1, r0
	beq _080437D4
	ldr r1, [sp, #4]
	ldr r4, _080437C8 @ =0x0300054E
	ldr r0, [sp]
	adds r2, r4, #0
	bl load_part_data
	ldr r0, [sp, #0xc]
	ldrb r4, [r4, #3]
	cmp r0, r4
	bne _08043740
	ldr r3, _080437CC @ =0x03004C40
	ldr r0, [sp, #4]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	ldr r0, [sp]
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08043740
	ldr r0, [sp, #4]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #4
	ldr r0, [sp]
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r1, r3
	ldrb r2, [r1]
	ldr r1, [sp, #4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	ldr r1, [sp]
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	beq _08043740
	ldr r0, [sp]
	b _080437D8
	.align 2, 0
_080437C8: .4byte 0x0300054E
_080437CC: .4byte 0x03004C40
_080437D0:
	ldr r0, [sp]
	b _080437D8
_080437D4:
	ldr r0, [sp, #0xc]
	adds r0, #0x78
_080437D8:
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
