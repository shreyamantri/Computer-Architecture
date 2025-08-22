.globl matmul

.text
# =======================================================
# FUNCTION: Matrix Multiplication of 2 integer matrices
#   d = matmul(m0, m1)
# Arguments:
#   a0 (int*)  is the pointer to the start of m0
#   a1 (int)   is the # of rows (height) of m0
#   a2 (int)   is the # of columns (width) of m0
#   a3 (int*)  is the pointer to the start of m1
#   a4 (int)   is the # of rows (height) of m1
#   a5 (int)   is the # of columns (width) of m1
#   a6 (int*)  is the pointer to the the start of d
# Returns:
#   None (void), sets d = matmul(m0, m1)
# Exceptions:
#   Make sure to check in top to bottom order!
#   - If the dimensions of m0 do not make sense,
#     this function terminates the program with exit code 38
#   - If the dimensions of m1 do not make sense,
#     this function terminates the program with exit code 38
#   - If the dimensions of m0 and m1 don't match,
#     this function terminates the program with exit code 38
# =======================================================
matmul:
#matrix multipliication
#read pictures of handwritten digits 
#what digit is in the picture
#matrix = 2D array, store each as a 1-dimensional integer array
#use dot product

#MATRIX A:
#a0 = pointer to start of matrix 1
#a1 = number of rows (height) of matrix A
#a2 = number of columns (width) of matrix A

#MATRIX B:
#a3 = pointer to start of Matrix B start
#a4 = number of rows (height) of B
#a5 = number of columns (width) of matrix B

#MATRIX C:
#a6 = pointer to integer array where result should be 

    # Error checks
    #malformed = return code 38 if the H or W is <1
    #malformed = return code 38 if #columns != #rows (height) of matrix B
    
    #use a0 pointer and check a1
    #must use a register for blt check because 1 not recognized
    bge x0, a1, error_code #height of Matrix A less than 0
    bge x0, a2, error_code #width matrix A less than 0
    bge x0, a4, error_code #height of matrix B less than 0
    bge x0, a5, error_code #width of matrix B less than 0
    bne a2, a4, error_code #need to check if #columns of M1 != #rows M2, error checking code is good
    ## DONE WITH ERROR CHECKING
   
    
    # Prologue
    #comments to keep track of what register is doing what
    addi sp sp -44 #want to check for 10 words, each having 4-bits from reference sheet
    sw ra 0(sp) #saving the address to return to when the function completes
    sw s0 4(sp) #array integer - pointer to start of return array
    sw s1 8(sp) 
    sw s2 12(sp) 
    sw s3 16(sp) 
    sw s4 20(sp) 
    sw s5 24(sp) 
    sw s6 28(sp) 
    sw s7 32(sp) 
    sw s8 36(sp) 
    sw s9 40(sp) 
    
    #now we have to use mv -- MoVe move the contents in register 1 to rd!
    #we need to use the pointers a0 to a6 to store the values 
    #move values from a0 and store in made registers
    
    mv s0 a0 #pointer to the start of matrix 1
    mv s1 a1 #number of rows of matrix 1
    mv s2 a2 #number of columns in matrix 2 (width)
    ##ALL ABOVE ONLY M1 HANDLING
    
    ##ALL BELOW M2 HANDLING
    mv s3 a3 #pointer to M2
    mv s4 a4 #height of M2 
    mv s5 a5 #width (columns) of M2
    mv s6 a6 #pointer to the array where the result should be
    mv s7 ra
    
    #add s8 x0 x0 #add 0 to 8 
    li s8 0 #row counter for A
   
outer_loop_start:
    #iterates through rows of matrix 1
    bge s8 s1 outer_loop_end #if we have hit a row number greater than total number
    #add s9 x0 x0 #restart it at B
    li s9 0 #count columns for B, start at a new column 
    
inner_loop_start:
#iterates through matrix 2
#every column iteration
    bge s9 s5 inner_loop_end 
    mv a0 s0 #starting of matrix 1, setting a0 to s0 -- pointer s0 start of matrix 1
    mv a1 s3 #s3 = pointer to m2
    #s9 = the column count for b
    
    slli t0, s9, 2 #byte offset -- each integer is 4 bytes, shifting it left 2 bits to multiply by 4
    #each memory address is 4 bytes apart
    #incrementing the memory address by 4 to account for the digit byte
    add a1, a1, t0 #get the next row pointer after slli
    
    mv a2, s2  #number of elements to use in dot product
    li a3, 1   # stride for matrix 1
    mv a4, s5  # stride for matrix 2 which is the column width
    
    jal ra, dot 
    
    #s6 is a pointer to the result matrix 
    
    sw a0 0(s6)  #store result in output matrix
    addi s6 s6 4 #move to next element in matrix c
    addi s9 s9 1  #increment column number
    j inner_loop_start

inner_loop_end:

    slli t0, s2, 2 #move by multiplication of 4 -- for each digit
    add s0, s0, t0  #move to next row in matrix 1 for the new pointer position
    addi s8, s8, 1  #increment the rows by 1
    j outer_loop_start

outer_loop_end:

    # Epilogue
    lw ra 0(sp) #saving the address to return to when the function completes
    lw s0 4(sp) #array integer - pointer to start of return array
    lw s1 8(sp) 
    lw s2 12(sp) 
    lw s3 16(sp) 
    lw s4 20(sp) 
    lw s5 24(sp) 
    lw s6 28(sp) 
    lw s7 32(sp)
    lw s8 36(sp)
    lw s9 40(sp)
    addi sp sp 44 #reallocate the space
    jr ra

error_code:
    li a0, 38 #return code 38
    j exit