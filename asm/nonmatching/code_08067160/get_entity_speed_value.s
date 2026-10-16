	.syntax unified

	thumb_func_start get_entity_speed_value
get_entity_speed_value: @ 0x08069E90
	push {r4, lr}
	ldr r2, _08069EB0 @ =0x08486160
	ldr r0, _08069EB4 @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r0, r2
	ldrb r0, [r2]
	cmp r0, #0
	beq _08069EBC
	ldr r1, _08069EB8 @ =0x03006F84
	ldrb r0, [r2, #1]
	strb r0, [r1]
	b _08069ED0
	.align 2, 0
_08069EB0: .4byte 0x08486160
_08069EB4: .4byte 0x03006FDC
_08069EB8: .4byte 0x03006F84
_08069EBC:
	ldr r4, _08069ED8 @ =0x03006F84
	ldr r1, _08069EDC @ =0x083F7FF4
	ldr r0, _08069EE0 @ =0x03001780
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl sub_0807CDD0
	strb r0, [r4]
_08069ED0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08069ED8: .4byte 0x03006F84
_08069EDC: .4byte 0x083F7FF4
_08069EE0: .4byte 0x03001780
	.syntax divided
