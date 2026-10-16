	.syntax unified

	thumb_func_start sub_080440D4
	.global sub_080440D4
sub_080440D4: @ 0x080440D4
	push {r4, lr}
	movs r2, #0
	ldr r3, _080440E8 @ =0x000001DF
	ldr r1, _080440EC @ =0x03004C40
_080440DC:
	ldrb r0, [r1]
	ldrb r4, [r1, #1]
	cmp r0, r4
	beq _080440F0
	movs r0, #0
	b _080440FA
	.align 2, 0
_080440E8: .4byte 0x000001DF
_080440EC: .4byte 0x03004C40
_080440F0:
	adds r1, #2
	adds r2, #1
	cmp r2, r3
	bls _080440DC
	movs r0, #1
_080440FA:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
