main: 
or $fp, $sp, $0
addi $sp, $sp, -12
or $10, $0, $fp
lw $10, -12($10)
li $11, 1
or $10, $0, $11
or $v1, $0, $fp
sw $10, -12($v1)
or $12, $0, $fp
lw $12, -8($12)
li $13, 10
or $12, $0, $13
or $v1, $0, $fp
sw $12, -8($v1)
Error: No this function -- testforrr
0x163e010
add $14, $v0, $0
or $15, $0, $fp
lw $15, -12($15)
li $16, 3
sge $17, $15, $16
bne $0, $17, row_15
j row_19
row_15:
or $18, $0, $fp
lw $18, -12($18)
or $a0, $0, $18
li $v0, 1
syscall
.data
string1: .asciiz "\n"
.text
li $v0, 4
la $a0, string1
syscall
bne $0, $17, row_22
row_19:
or $19, $0, $fp
lw $19, -8($19)
or $a0, $0, $19
li $v0, 1
syscall
.data
string2: .asciiz "\n"
.text
li $v0, 4
la $a0, string2
syscall
row_22:
li	$v0, 10
syscall
testfor:
addi $sp, $sp, -4
sw $31, 0($sp)
addi $sp, $sp, -12
or $v0, $0, $fp
addi $sp, $sp, -4
sw $v0, 0($sp)
addi $sp, $sp, -4
sw $fp, 0($sp)
add $fp, $sp, $0
jal MyProcedure
lw $fp, 0($fp)
addi $sp, $sp, 8
add $20, $v0, $0
li $21, 0
add $v0, $0, $21
addi $sp, $sp, 12
lw $31, 0($sp)
addi $sp, $sp, 4
jr $31
addi $sp, $sp, 12
lw $31, 0($sp)
addi $sp, $sp, 4
jr $31
MyProcedure:
addi $sp, $sp, -4
sw $31, 0($sp)
addi $sp, $sp, -0
or $22, $0, $fp
lw $22, 4($22)
lw $22, -8($22)
li $23, 0
or $22, $0, $23
or $v1, $0, $fp
lw $v1, 4($v1)
sw $22, -8($v1)
or $24, $0, $fp
lw $24, 4($24)
lw $24, 4($24)
lw $24, -12($24)
row_35:
or $25, $0, $fp
lw $25, 4($25)
lw $25, -8($25)
or $10, $0, $fp
lw $10, 4($10)
lw $10, -8($10)
li $11, 1
add $12, $10, $11
or $25, $0, $12
or $v1, $0, $fp
lw $v1, 4($v1)
sw $25, -8($v1)
or $13, $0, $fp
lw $13, 4($13)
lw $13, 4($13)
lw $13, -8($13)
slt $14, $24, $13
addi $24, $24, 1
bne $0, $14, row_35
or $15, $0, $fp
lw $15, 4($15)
lw $15, -8($15)
or $a0, $0, $15
li $v0, 1
syscall
.data
string3: .asciiz "\n"
.text
li $v0, 4
la $a0, string3
syscall
li $16, 0
add $v0, $0, $16
addi $sp, $sp, 0
lw $31, 0($sp)
addi $sp, $sp, 4
jr $31
addi $sp, $sp, 0
lw $31, 0($sp)
addi $sp, $sp, 4
jr $31
