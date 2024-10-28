#for (i=0; i<=100; i++)
#	a[i] = b[i] + c

# $a0 = &a[0]
#$a1 = &b[0]
#i = $t0
#c = $s0

# São executadas 9 *101 + 1 = 910 instruções
# são feitas 202 referencias a memoria
add $t0, $zero, $zero
loop:
	# t3 = i * 4
	sll $t3, $t0, 2
		
	# t4 = i*4 + b
	add $t4, $t3, $a1
	lw $t4, 0($t4)
	
	# t6 =  b[i] + c
	add $t6, $t4, $s0
	
	# t5 = i*4 + a
	add $t5, $t3, $a0
	
	# a[i] = b[i] + c
	sw $t6, 0($t5)
	
	# i ++;
	addi $t0, $t0, 1
	
	# t2 = t0 < 101 ? 1 : 0
	slti $t2, $t0, 101
	
	# while t2 != 0
	bne $t2, $zero, loop

	