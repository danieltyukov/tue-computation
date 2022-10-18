.data
str1:    .ascii "result = \0"
str2:    .ascii "\n\0"

.text

.global main

# void main(void) {
# int a, b;

# a = read_int();
# b = read_int();
# print_int(a+b);
# }

main:
    call read_int
    move t0, a0
    call read_int
    move t1, a0
    add t2, t0, t1
    move a0, t2 #move num read into t1
	