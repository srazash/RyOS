section .multiboot_header
header_start:
    ; magic number
    dd 0xe85250d4 ; multiboot2
    ; architecture
    dd 0 ; protected mode i386
    ; header length
    dd header_length - header_start
    ; checksum
    dd 0x100000000 - (0xe85250d4 + 0 + (header_length - header_start))

    ; end tag
    dw 0
    dw 0
    dd 0
header_end:
