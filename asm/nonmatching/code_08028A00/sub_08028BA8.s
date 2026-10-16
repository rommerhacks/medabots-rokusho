	.syntax unified

	thumb_func_start sub_08028BA8
sub_08028BA8: @ 0x08028BA8
	push {lr}
	movs r0, #0x21
	movs r1, #3
	bl clear_battle_sprite_slot
	ldr r0, _08028BC8 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08028C2C
	lsls r0, r0, #2
	ldr r1, _08028BCC @ =_08028BD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028BC8: .4byte 0x03001800
_08028BCC: .4byte _08028BD0
_08028BD0: @ jump table
	.4byte _08028BE8 @ case 0
	.4byte _08028BF4 @ case 1
	.4byte _08028C00 @ case 2
	.4byte _08028C0C @ case 3
	.4byte _08028C18 @ case 4
	.4byte _08028C24 @ case 5
_08028BE8:
	ldr r0, _08028BF0 @ =0x03001800
	adds r0, #0xa6
	movs r1, #0x46
	b _08028C2A
	.align 2, 0
_08028BF0: .4byte 0x03001800
_08028BF4:
	ldr r0, _08028BFC @ =0x03001800
	adds r0, #0xa6
	movs r1, #0x49
	b _08028C2A
	.align 2, 0
_08028BFC: .4byte 0x03001800
_08028C00:
	ldr r0, _08028C08 @ =0x03001800
	adds r0, #0xa6
	movs r1, #0x47
	b _08028C2A
	.align 2, 0
_08028C08: .4byte 0x03001800
_08028C0C:
	ldr r0, _08028C14 @ =0x03001800
	adds r0, #0xa6
	movs r1, #0x48
	b _08028C2A
	.align 2, 0
_08028C14: .4byte 0x03001800
_08028C18:
	ldr r0, _08028C20 @ =0x03001800
	adds r0, #0xa6
	movs r1, #0x5d
	b _08028C2A
	.align 2, 0
_08028C20: .4byte 0x03001800
_08028C24:
	ldr r0, _08028C3C @ =0x03001800
	adds r0, #0xa6
	movs r1, #0x5e
_08028C2A:
	strb r1, [r0]
_08028C2C:
	ldr r1, _08028C3C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08028C3C: .4byte 0x03001800
	.syntax divided
