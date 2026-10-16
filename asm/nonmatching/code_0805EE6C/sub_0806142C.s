	.syntax unified

	thumb_func_start sub_0806142C
sub_0806142C: @ 0x0806142C
	push {lr}
	sub sp, #0x30
	ldr r0, _0806145C @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	ldr r1, _08061460 @ =0x08485580
	cmp r0, #0
	bne _0806143E
	ldr r1, _08061464 @ =0x08485551
_0806143E:
	mov r0, sp
	bl copy_text_with_lookup
	mov r0, sp
	bl run_message
	cmp r0, #0
	beq _08061456
	ldr r1, _08061468 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08061456:
	add sp, #0x30
	pop {r0}
	bx r0
	.align 2, 0
_0806145C: .4byte 0x03006F74
_08061460: .4byte 0x08485580
_08061464: .4byte 0x08485551
_08061468: .4byte 0x0300137C
	.syntax divided
