.data 
	array: .space 40

.text
addi $t0, $zero, 0
addi $t1, $zero, 10
set_array:
	# Salva contexto: t0, t1
	addi $sp, $sp, -8
	sw $t1, 0($sp)
	sw $t0, 4($sp)
	
	# compare(a0, i)
	add $a1, $zero, $t0 
	jal compare 
	
	# recupera registradores t1 e t0
	lw $t1, 0($sp)
	lw $t0, 4($sp)
	addi $sp, $sp, 8
	
	#Pega endereço do espaço alocado
	la $s0, array
	
	#calcula offset (i*4 + endereço array)
	sll $t2, $t0, 2
	add $t3, $t2, $s0
	
	# array[i] = compare(a0, i)
	sw $v0, 0($t3)
	addi $t0, $t0, 1 # i+=1
	
	#if (i == 10)
	beq $t0, $t1, FIM
	j set_array
compare:
	# salva o return address
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	jal sub

	lw $ra, 0($sp)
	addi $sp, $sp, 4

	# sub(a0, a1) < 0 ?
	#t0 = 0 se v0 >= 0
	slti $t0, $v0, 0
	#t0 = 0? se sim vai para else
	bne $t0, $zero, ELSE 
	add $v0, $zero, 1
	jr $ra
ELSE:
	add $v0, $zero, $zero
	jr $ra
sub:
	sub $v0, $a0, $a1 
	jr $ra
FIM:
