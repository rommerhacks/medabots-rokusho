	.include "asm/macros.inc"

	.syntax unified

	.text


	arm_func_start sub_08000000
sub_08000000: @ 0x08000000
	b crt0_start
_08000004:
	.incbin "baserom.gba", 0x4, 0xBC  @ cartridge header

	arm_func_start crt0_start
crt0_start: @ 0x080000C0
	mov r0, #0x12
	msr cpsr_fc, r0
	ldr sp, _080000F8 @ =0x03007FA0
	mov r0, #0x1f
	msr cpsr_fc, r0
	ldr sp, _080000F4 @ =0x03007F00
	ldr r1, _080000FC @ =0x03007FFC
	add r0, pc, #0x20 @ =irq_dispatch_arm
	str r0, [r1]
	ldr r1, _08000100 @ =main
	mov lr, pc
	bx r1
	b crt0_start
	.align 2, 0
_080000F4: .4byte 0x03007F00
_080000F8: .4byte 0x03007FA0
_080000FC: .4byte 0x03007FFC
_08000100: .4byte main

	arm_func_start irq_dispatch_arm
	.global irq_dispatch_arm
irq_dispatch_arm: @ 0x08000104
	mov r3, #0x4000000
	add r3, r3, #0x200
	ldr r2, [r3]
	ldrh r1, [r3, #8]
	mrs r0, spsr
	push {r0, r1, r2, r3, lr}
	mov r0, #1
	strh r0, [r3, #8]
	and r1, r2, r2, lsr #16
	mov ip, #0
	ands r0, r1, #0xc0
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #1
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #4
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #2
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x100
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x200
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x400
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x800
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x1000
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x20
	bne _080001B0
	add ip, ip, #4
	ands r0, r1, #0x2000
	strbne r0, [r3, #-0x17c]
_080001AC:
	bne _080001AC
_080001B0:
	strh r0, [r3, #2]
	mov r1, #0x26c0
	bic r2, r2, r0
	and r1, r1, r2
	strh r1, [r3]
	mrs r3, apsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x1f
	msr cpsr_fc, r3
	ldr r1, _08000214 @ =0x03000BA0
	add r1, r1, ip
	ldr r0, [r1]
	stmdb sp!, {lr}
	add lr, pc, #0x0 @ =0x080001EC
	bx r0
	ldm sp!, {lr}
	mrs r3, apsr
	bic r3, r3, #0xdf
	orr r3, r3, #0x92
	msr cpsr_fc, r3
	pop {r0, r1, r2, r3, lr}
	strh r2, [r3]
	strh r1, [r3, #8]
	msr spsr_fc, r0
	bx lr
	.align 2, 0
_08000214: .4byte 0x03000BA0

	arm_func_start link_buffer_swap_arm
	.global link_buffer_swap_arm
link_buffer_swap_arm: @ 0x08000218
	push {r8, sb, sl, fp}
	mov ip, #0x4000000
	ldr fp, _08000254 @ =0x03005170
	add sl, fp, #0x28
	mov sb, #1
	mov r8, #0
	strb r8, [ip, #0x208]
	ldm sl, {r0, r1}
	stm sl!, {r1}
	stm sl!, {r0}
	ldrb r0, [fp, #5]
	strb r8, [fp, #5]
	strb sb, [ip, #0x208]
	pop {r8, sb, sl, fp}
	bx lr
	.align 2, 0
_08000254: .4byte 0x03005170
_08000258:
	.byte 0x70, 0x47, 0x00, 0x00
