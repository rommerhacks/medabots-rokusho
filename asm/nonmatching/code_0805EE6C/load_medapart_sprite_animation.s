	.syntax unified

	thumb_func_start load_medapart_sprite_animation
	.global load_medapart_sprite_animation
load_medapart_sprite_animation: @ 0x080629D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r3, r2, #0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r6, _08062A30 @ =0x02026000
	lsls r0, r3, #6
	adds r0, r0, r3
	lsls r0, r0, #4
	ldr r1, _08062A34 @ =0x020260D0
	adds r0, r0, r1
	str r0, [r6, #8]
	ldr r2, _08062A38 @ =0x080AFA3C
	lsls r0, r5, #1
	lsls r1, r3, #3
	adds r0, r0, r1
	adds r1, r0, r2
	ldrb r4, [r1]
	adds r2, #1
	adds r0, r0, r2
	ldrb r1, [r0]
	cmp r3, #0
	beq _08062A44
	ldr r0, _08062A3C @ =0x03002414
	ldr r0, [r0]
	ldr r2, _08062A40 @ =0x00000B84
	adds r0, r0, r2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0xc7
	str r1, [sp, #8]
	movs r1, #4
	str r1, [sp, #0xc]
	movs r1, #6
	str r1, [sp, #0x10]
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl load_sprite_animation_by_type
	b _08062A64
	.align 2, 0
_08062A30: .4byte 0x02026000
_08062A34: .4byte 0x020260D0
_08062A38: .4byte 0x080AFA3C
_08062A3C: .4byte 0x03002414
_08062A40: .4byte 0x00000B84
_08062A44:
	ldr r0, _08062A6C @ =0x03002414
	ldr r0, [r0]
	ldr r2, _08062A70 @ =0x00000B84
	adds r0, r0, r2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0xc7
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl load_sprite_animation_by_type
_08062A64:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08062A6C: .4byte 0x03002414
_08062A70: .4byte 0x00000B84
	.syntax divided
