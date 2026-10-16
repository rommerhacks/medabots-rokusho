	.syntax unified

	thumb_func_start sub_08021000
sub_08021000: @ 0x08021000
	push {lr}
	ldr r0, _08021028 @ =0x083B5F80
	adds r0, #0x8c
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802102C @ =0x03002C30
	ldr r1, _08021030 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08021024
	ldr r1, _08021034 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08021024:
	pop {r0}
	bx r0
	.align 2, 0
_08021028: .4byte 0x083B5F80
_0802102C: .4byte 0x03002C30
_08021030: .4byte 0x00000862
_08021034: .4byte 0x03001800
	.syntax divided
