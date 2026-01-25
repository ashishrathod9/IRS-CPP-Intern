

void main()
{
  write(1, "HACK\n", 5);
}

// write() is a system call (declared in <unistd.h>).

// Parameters:

// 1 → File descriptor for stdout (standard output).

// 0 = stdin, 1 = stdout, 2 = stderr.

// "HACK\n" → The string to output.

// 5 → Number of bytes to write (the length of "HACK\n").

// So this writes exactly 5 characters (H, A, C, K, newline) directly to stdout.

// Difference from printf()

// printf() is a library function from <stdio.h> that formats output and buffers it.

// write() is a low-level system call that writes raw bytes directly to a file descriptor, bypassing buffering and formatting.
