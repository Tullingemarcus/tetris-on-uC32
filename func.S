# Delay function. The arguemnt sets the delay in milliseconds

.data
.text
.globl delay, enable_interrupt

delay:  add	$t0, $0, $0		# int i = 0
        add	$t1, $a0, $0            # moves a0(ms) to t1
 	
while:	slt	$t2, $0, $t1		# while( ms > 0 )
        beq	$t2, $0, exit		# if ms = 0 goto exit
        nop
        addi    $t1, $t1, -1		# ms = ms – 1;
        add	$t0, $0, $0		# int i = 0
	
for:	slti	$t3, $t0, 3750		# i < constant
        beq	$t3, $0, while		# if i = constant goto while
        nop
        addi	$t0, $t0, 1		# i = i + 1
        j	for
        nop

exit:	jr	$ra
	nop

# Enables interrupts
enable_interrupt:
        ei
        jr      $ra
        nop