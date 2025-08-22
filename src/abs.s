.globl abs

.text
# =================================================================
# FUNCTION: Given an int return its absolute value.
# Arguments:
#   a0 (int*) is a pointer to the input integer
# Returns:
#   None
# =================================================================
abs:
  # Load number from memory
  lw t0 0(a0)
  ebreak
  
  bge t0, zero, done #Original was blt: which is branch if it was less than; New Version: bge now branching if greater or equal

  # Negate a0
  sub t0, x0, t0

  # Store number back to memory
  sw t0 0(a0)

done:
  jr ra